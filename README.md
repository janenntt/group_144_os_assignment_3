## Parallel Merge Sort

* Authors:
  - Ngoc Thuy Tram Nguyen
  - Thi Phuong Thao Truong
  - Omar Mahmood Humaid Abdulla Alhammadi

* Group name: Group 144

## Overview

This project implements a parallel merge sort algorithm using the POSIX Threads (pthreads) library in C.
The program demonstrates how the traditional divide-and-conquer merge sort can be parallelised to improve performance on multi-core systems.

Instead of recursively sorting subarrays in a single thread, the program creates new threads at each recursive level (up to a user-defined cutoff) to sort smaller subarrays concurrently. When the cutoff level is reached, the algorithm switches back to a serial merge sort. This approach significantly reduces sorting time by utilising multiple CPU cores efficiently.

## Manifest

| File Name            | Description                                                                                                                            |
| -------------------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| **mergesort.c**      | Implements the serial and parallel merge sort functions (`mergesort`, `merge`, `parallel_mergesort`, `buildArgs`).                     |
| **mergesort.h**      | Contains global variable and struct definitions (`A`, `B`, `cutoff`, and `struct argument`). **Must not be modified.**                 |
| **test-mergesort.c** | Testing program that generates random arrays and measures sorting time. Takes 3 parameters: array size, cutoff level, and random seed. |
| **Makefile**         | Automates the build process for compiling the merge sort and testing program.                                                          |
| **README.md**        | Documentation file explaining project overview, usage, testing, and reflections.                                                       |


## Building the project

To compile the project, navigate to the project directory and run:
```bash
make
```
This will generate an executable file called `test-mergesort`

To run the program, run:
```bash
./test-mergesort <input size> <cutoff level> <seed>
```

Example:
```bash
./test-mergesort 100000000 3 1234
```
This command sorts 100 million randomly generated integers using parallel merge sort up to level 3 with a seed of `1234`.


## Features and usage

**Main Features**
* **Serial merge sort (cutoff = 0):** Standard single-threaded merge sort.
* **Parallel merge sort (cutoff ≥ 1):** Spawns new threads recursively to handle left and right subarrays concurrently.
* **Dynamic thread control:** Thread creation stops at the specified cutoff level to prevent excessive thread overhead.
* **Performance reporting:** Automatically measures and displays sorting time for each configuration.


## Testing

This section should detail how you tested your code. Simply stating "I ran
it a few times and it seems to work" is not sufficient. Your testing needs
to be detailed here.

## Known Bugs

List known bugs that you weren't able to fix (or ran out of time to fix).

## Reflection and Self Assessment

Discuss the issues you encountered during development and testing. What
problems did you have? What did you have to research and learn on your own?
What kinds of errors did you get? How did you fix them?

What parts of the project did you find challenging? Is there anything that
finally "clicked" for you in the process of working on this project? How well
did the development and testing process go for you?

## Sources Used

If you used any sources outside of the textbook, you should list them here.
If you looked something up on stackoverflow.com or you use help from AI, and
fail to cite it in this section, it will be considered plagiarism and dealt
with accordingly. So be safe CITE!
