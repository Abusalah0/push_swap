# push_swap

### Brief  

The `push_swap` project is designed to implement a sorting algorithm using two stacks, where the goal is to sort a list of integers in ascending order with the fewest possible operations. The project focuses on optimizing the number of moves required, using a set of predefined operations such as push, swap, rotate, and reverse rotate.  

By applying efficient algorithms, the program outputs a sequence of operations that sort the integers, while adhering to the constraints of the project. This solution is both a challenge in algorithm design and an opportunity to improve performance within specific limits.

---

### Structure  

The project is organized into the following directories and files:

```
project-root/
│
├── Makefile                # Build file
│
├── src/                    # Source files
│
├── libft/                  # Custom library functions
│
├── include/                # Header files
│
└── get_next_line/          # Implementation files for get_next_line
```

---

### Features  

The algorithm used for this project is based on the **Turk Sort** algorithm, which was designed to minimize the number of operations required to sort the stack. The algorithm works by pushing elements from the `STACK_A` to `STACK_B` in descending order, finding the most efficient position for each number, and then pushing them back to `STACK_A` to achieve the desired sorted order.  

The Turk Sort algorithm uses the following principles:  
- Sorting is achieved by using only the allowed operations: `sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, and `rrb`.
- Numbers are pushed in a way that places the minimum and maximum values in their correct positions relative to the others.
- The algorithm adapts to the stack size, optimizing operations when possible.
  
A full explanation of the algorithm can be found [here](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

---

### Usage  

Using the push_swap program is straightforward:  

1. **Build the Project**  
   Compile the project by running the following command in the terminal:  
   ```bash
   make
   ```  

2. **Run the Program**  
   Execute the `push_swap` binary and pass a list of numbers as arguments:  
   ```bash
   ./push_swap (numbers)
   ```  

   **Example:**  
   ```bash
   ./push_swap 4 67 3 87 23
   ```  

This will output the sequence of operations required to sort the given numbers in ascending order using the push_swap algorithm.

---

### Performance  

The push_swap program demonstrates competitive performance metrics when sorting random sets of numbers. Below are the key statistics:  

#### Sorting 500 Random Numbers (-500 to 500)  
- **Average Operations**: 5102.85  
- **Median Operations**: 5111  
- **Maximum Operations**: 5400  
- **Minimum Operations**: 4820  
- **90% Range**: Between 4953 and 5283  
- **95% Range**: Between 4931 and 5324  

#### Sorting 100 Random Numbers (-500 to 500)  
- **Average Operations**: 562.53  
- **Median Operations**: 566  
- **Maximum Operations**: 613  
- **Minimum Operations**: 524  
- **90% Range**: Between 535 and 585  
- **95% Range**: Between 526 and 591  

These results highlight the efficiency of the Turk Sort algorithm in minimizing operations while adhering to the constraints of the push_swap project.  

---
I will add documentation for the bonus part soon
