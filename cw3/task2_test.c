#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/xattr.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/sysmacros.h>   // For makedev()
#include <sys/un.h>          // For struct sockaddr_un



#define TEST_DIR "test"

void create_test_directory() {
    if (mkdir(TEST_DIR, 0755) && errno != EEXIST) {
        perror("mkdir");
        exit(EXIT_FAILURE);
    } else {
        // printf("Created parent folder '%s/'\n", TEST_DIR);
    }
}

void create_regular_file() {
    char path[] = TEST_DIR "/test_regular";
    int fd = open(path, O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("regular file");
    } else {
        close(fd);
        // printf("Created regular file 'test_regular'\n");
    }
}

void create_directory() {
    char path[] = TEST_DIR "/test_directory";
    if (mkdir(path, 0755) && errno != EEXIST) {
        perror("directory");
    } else {
        // printf("Created directory 'test_directory'\n");
    }
}

void create_character_device() {
    char path[] = TEST_DIR "/test_chardev";
    if (mknod(path, S_IFCHR | 0644, makedev(1, 7)) && errno != EEXIST) {
        perror("character device");
    } else {
        // printf("Created character device 'test_chardev'\n");
    }
}

void create_block_device() {
    char path[] = TEST_DIR "/test_blockdev";
    if (mknod(path, S_IFBLK | 0644, makedev(8, 0)) && errno != EEXIST) {
        perror("block device");
    } else {
        // printf("Created block device 'test_blockdev'\n");
    }
}

void create_fifo() {
    char path[] = TEST_DIR "/test_fifo";
    if (mkfifo(path, 0644) && errno != EEXIST) {
        perror("FIFO");
    } else {
        // printf("Created FIFO 'test_fifo'\n");
    }
}

void create_socket() {
    char path[] = TEST_DIR "/test_socket";
    int sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return;
    }
    unlink(path);
    struct sockaddr_un addr = { .sun_family = AF_UNIX };
    strncpy(addr.sun_path, path, sizeof(addr.sun_path) - 1);
    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("socket bind");
    }
    close(sock);
    // printf("Created socket 'test_socket'\n");
}

void create_symlink() {
    char target[] = "test_regular";
    char path[] = TEST_DIR "/test_symlink";
    unlink(path);
    if (symlink(target, path) && errno != EEXIST) {
        perror("symlink");
    } else {
        // printf("Created symlink 'test_symlink'\n");
    }
}

void create_unknown_file() {
    char path[] = TEST_DIR "/test_unknown";
    if (mknod(path, S_IFCHR | 0644, makedev(999, 999)) < 0) {
        perror("mknod");
    } else {
        // printf("Unknown file created: %s\n", "test_unknown");
    }
}

void set_xattr(const char *value) {
    if (setxattr(TEST_DIR, "user.cw3_hide", value, strlen(value), 0)) {
        perror("setxattr");
    } else {
        printf("\nSet xattr to hide: %s\n", value);
    }
}

void check_hidden_files(const char *hidden_type) {
    DIR *dir = opendir(TEST_DIR);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    struct stat file_stat;
    char filepath[512];

    while ((entry = readdir(dir))) {
        snprintf(filepath, sizeof(filepath), "%s/%s", TEST_DIR, entry->d_name);
        
        if (stat(filepath, &file_stat) < 0) {
            perror("stat");
            continue;
        }

        const char *type_str = NULL;
        
        if (S_ISREG(file_stat.st_mode)) type_str = "regular";
        else if (S_ISDIR(file_stat.st_mode)) type_str = "directory";
        else if (S_ISCHR(file_stat.st_mode)) type_str = "chardev";
        else if (S_ISBLK(file_stat.st_mode)) type_str = "blockdev";
        else if (S_ISFIFO(file_stat.st_mode)) type_str = "fifo";
        else if (S_ISSOCK(file_stat.st_mode)) type_str = "socket";
        else if (S_ISLNK(file_stat.st_mode)) type_str = "symlink";
        else type_str = "unknown";

        if (strcmp(type_str, hidden_type) == 0) {
            printf("Error: %s file '%s' is still visible!\n", hidden_type, entry->d_name);
        }
    }

    closedir(dir);
}

void delete_test_directory() {
    system("rm -rf " TEST_DIR);
    printf("Deleted test directory\n");
}

void create_and_populate_test_directory() {
    create_test_directory();
    create_regular_file();
    create_directory();
    create_character_device();
    create_block_device();
    create_fifo();
    create_socket();
    create_symlink();
    create_unknown_file();
    printf("Created all test files\n");
}

int main() {
    const char *types[] = { "regular", "directory", "chardev", "blockdev", "fifo", "socket", "symlink", "unknown" };
    create_and_populate_test_directory();
    for (int i = 0; i < 8; i++) {
        set_xattr(types[i]);
        check_hidden_files(types[i]);
        // delete_test_directory();
        // sleep(1);
    }

    return 0;
}
