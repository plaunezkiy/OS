
CORE_PATH="core.c"
DICE_OS_HOME="/disk/scratch/operating_systems/s2150635/linux-cw1"
WSL_OS_HOME="/home/os/linux-cw1"
SRC_HOME="CW1_S2150635"

cp $SRC_HOME/$CORE_PATH $WSL_OS_HOME/kernel/sched/$CORE_PATH
cp array.c $WSL_OS_HOME/fs/proc/array.c
# cp CW1_S2150635/kernel/sched/core.c /disk/scratch/operating_systems/s2150635/linux-cw1/kernel/sched/core.c