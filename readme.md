# XV6 Schedulers

This is a study project to implement [Lottery Scheduling](https://en.wikipedia.org/wiki/Lottery_scheduling) and [Stride Scheduling](https://en.wikipedia.org/wiki/Stride_scheduling) into the [XV6 OS](https://github.com/mit-pdos/xv6-public).

## Setup

### Dependencies
- [QEMU](https://www.qemu.org/) for virtualization.
- gcc v11
- libc6-dev-i386
- make

### Build
The project uses make to automate the building proccess, some of the availables commands are:
```bash
make # Compile the source
make clean # Remove build files

make qemu # Build the source and start virtualization with qemu using a graphical interface
make qemu-nox # Bould the source and start the virtualization in the terminal
```

### Applying the Diffs
Both Stride Schedule and Lottery Schedule can be accessed at their respective branches [stride-scheduling](https://github.com/mateusKoppe/xv6-schedulers/tree/stride-scheduling) and [lottery-scheduling](https://github.com/mateusKoppe/xv6-schedulers/tree/stride-scheduling).

Alternatively, you can use one of the diff files: [0001-Stride-scheduling.diff](./0001-Stride-scheduling.diff) and [0001-Lottery-scheduling.diff](./0001-Lottery-scheduling.diff).

To apply a diff run the git command:
```bash
git apply <diff-file>

# Being:

git apply 0001-Stride-scheduling.diff # For stride scheduling
git apply 0001-Lottery-scheduling.diff # For lottery scheduling
```

Note that this will not add any commits or stage the changes in the git repository. Trying to merge both will generate a conflicts, the implementations are not mean to, and cannot be used together.

A easy way to revert the diff (if not staged):
```bash
git restore .
```

Learn more about diff patches on:
- [git-diff --patch](https://git-scm.com/docs/git-diff#Documentation/git-diff.txt---patch)
- [git-apply](https://git-scm.com/docs/git-apply)

## Running
XV6 will bahave similar to a unix like OS in a very minimal way.

To see the scheduling in actions (if you applied the diffs) you can run `schedulingtest` and see something like this:
```bash
$ schedulingtest
> schedulingtest - the next lines should be displayed in order
> 1 - proccess finished.
> 2 - proccess finished.
> 3 - proccess finished.
```

As described, if the number of the proccess are in order it means that the scheduler worked.

The command `schedulingtest` will run the [schedulingtest.c](https://github.com/mateusKoppe/xv6-schedulers/blob/stride-scheduling/schedulingtest.c), which can only be seeing in one of the branches or diffs. This file contains the logic to run forks assigning to each a different number of tickets, giving priotiry to respectively the first, second and thirt proccess.
