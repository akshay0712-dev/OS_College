
# OS Lab Programming Assignment - fork()

## Problem Statement
Write a C program that utilises `fork()` to perform a distributed sum calculation on a dataset. The program must demonstrate sequential execution.

## Requirements

1. **Array Initialisation**: Populate an integer array of size 30 with random values between 1 and 50.

2. **Sequential Execution**:
    - Create Child 1 to calculate the sum of even integers in indices 0–14
    - Parent must use `waitpid()` to ensure Child 1 completes before starting Child 2
    - Create Child 2 to calculate the sum of even integers in indices 15–29

3. **Data Retrieval**: Use `WEXITSTATUS` to collect results from both children and print them from the Parent process.

## Solution Guide

### Key Concepts
- **fork()**: Creates a child process; returns 0 in child, child's PID in parent
- **waitpid()**: Blocks parent until child exits
- **WEXITSTATUS()**: Extracts exit status from child process

### Implementation Tips

**Child 1 block** (`if (p1 == 0)`):
- Calculate sum of even numbers in `arr[0]` to `arr[14]`
- Exit with sum using `exit(sum)`

**Child 2 block** (`if (p2 == 0)`):
- Calculate sum of even numbers in `arr[15]` to `arr[29]`
- Exit with sum using `exit(sum)`

### Expected Output
```
Array initialized by Parent
Total Even Sum of left side and right side are: [sum1] and [sum2]
```
