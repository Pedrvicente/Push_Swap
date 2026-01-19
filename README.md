# Push_swap

A sorting algorithm project that sorts data on a stack with a limited set of operations, using the smallest possible number of actions.

## Table of Contents

- [About](#about)
- [Algorithm](#algorithm)
- [Installation](#installation)
- [Usage](#usage)
- [Operations](#operations)
- [Project Structure](#project-structure)
- [Implementation Details](#implementation-details)
- [Testing](#testing)
- [Resources](#resources)

---

## About

Push_swap is a 42 School project that challenges you to sort a stack of integers using only a specific set of operations, while minimizing the number of moves. The program must output the sequence of operations needed to sort the stack.

### Project Goals

- Sort integers on stack A using stack B as auxiliary storage
- Minimize the number of operations
- Handle edge cases (duplicates, INT_MIN/MAX, invalid input)
- Optimize for different input sizes (3, 5, 100, 500+ numbers)

---

## Algorithm

This implementation uses the **Turk Algorithm** (Cost-Based Sorting), which is an optimized approach that calculates the "cost" of moving each element and always moves the cheapest one first.

### Algorithm Overview

1. **Small Cases (2-3 numbers)**: Direct sorting with hardcoded patterns
2. **Medium Case (5 numbers)**: Push smallest elements to B, sort remaining 3, then push back
3. **Large Cases (>5 numbers)**: Turk Algorithm

### Turk Algorithm Steps

```
1. Push all but 3 elements from A to B
2. Sort the remaining 3 elements in A (tiny_sort)
3. While B is not empty:
   a. Calculate position indices for all nodes
   b. Set target nodes (where each B node should go in A)
   c. Calculate push price for each B node
   d. Find the cheapest node to move
   e. Execute optimal rotations (rotate both when possible)
   f. Push cheapest node from B to A
4. Final rotation to put smallest element on top
```

### Key Concepts

- **Target Node**: For each element in B, find its correct position in A (smallest value greater than current)
- **Push Price**: Cost to move a node = rotations in B + rotations in A
- **Above Median**: Determines whether to use rotate (ra/rb) or reverse rotate (rra/rrb)
- **Cheapest Node**: The node with minimum push price

---

## Installation

### Prerequisites

- GCC compiler
- Make
- Unix-based system (Linux/macOS)

### Compilation

```bash
# Clone the repository
git clone https://github.com/pedrovicente/push_swap.git
cd push_swap

# Compile the project
make

# This creates the executable: push_swap
```

### Make Rules

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

---

## Usage

### Basic Usage

```bash
./push_swap [numbers]
```

### Examples

```bash
# Example 1: Simple case
./push_swap 3 2 1
# Output: sa ra

# Example 2: String argument
./push_swap "5 2 4 1 3"
# Output: [sequence of operations]

# Example 3: Larger set
./push_swap 42 17 88 3 91 25 67 5
# Output: [optimized sequence]

# Example 4: Test with random numbers
ARG=$(shuf -i 0-100 -n 5 | tr '\n' ' '); ./push_swap $ARG
```

### Input Formats

The program accepts two input formats:

1. **Multiple arguments**: `./push_swap 3 2 1`
2. **Single string**: `./push_swap "3 2 1"`

---

## Operations

The program can only use these 11 operations:

### Swap Operations
- `sa`: Swap first 2 elements of stack A
- `sb`: Swap first 2 elements of stack B
- `ss`: sa and sb at the same time

### Push Operations
- `pa`: Push first element of B to A
- `pb`: Push first element of A to B

### Rotate Operations
- `ra`: Rotate stack A up (first → last)
- `rb`: Rotate stack B up
- `rr`: ra and rb at the same time

### Reverse Rotate Operations
- `rra`: Rotate stack A down (last → first)
- `rrb`: Rotate stack B down
- `rrr`: rra and rrb at the same time


## Project Structure

```
push_swap/
├── push_swap.h              # Header file with structures and prototypes
├── main.c                   # Entry point and main logic
├── stack_init.c             # Stack initialization and parsing
├── stack_utils.c            # Stack utility functions
├── error.c                  # Error handling and memory management
├── ft_split.c               # String splitting utility
├── swap_command.c           # Swap operations (sa, sb, ss)
├── push_command.c           # Push operations (pa, pb)
├── rotate_command.c         # Rotate operations (ra, rb, rr)
├── reverse_rotate_command.c # Reverse rotate operations (rra, rrb, rrr)
├── tiny_sort.c              # Sorting for 2-3 elements
├── push_swap_init.c         # Node initialization and price calculation
├── push_swap_command.c      # Main sorting algorithm
└── Makefile                 # Compilation rules
```

---

## Implementation Details

### Data Structure

```c
typedef struct s_stack_node
{
    int                 value;              // The integer value
    int                 current_position;   // Index in current stack
    int                 final_index;        // Target sorted position
    int                 push_price;         // Cost to move this node
    bool                above_median;       // Position relative to median
    bool                cheapest;           // Is this the cheapest to move?
    struct s_stack_node *target_node;       // Where to insert in stack A
    struct s_stack_node *next;              // Next node
    struct s_stack_node *prev;              // Previous node
} t_stack_node;
```

### Core Functions

#### Stack Initialization
```c
void stack_init(t_stack_node **a, char **argv, bool argc_2);
```
- Parses command line arguments
- Validates input (integers, no duplicates, within INT range)
- Creates linked list of nodes

#### Node Initialization
```c
void init_node(t_stack_node *a, t_stack_node *b);
```
- Sets current position for all nodes
- Calculates target nodes
- Computes push prices
- Marks cheapest node

#### Target Setting
```c
static void set_target(t_stack_node *a, t_stack_node *b);
```
- For each node in B, finds its target position in A
- Target = smallest value in A that is greater than current B node
- If no such value exists, target = smallest node in A

#### Price Calculation
```c
void set_price(t_stack_node *a, t_stack_node *b);
```
- Calculates rotation cost for B node
- Adds rotation cost for target node in A
- Uses above_median to determine ra/rra vs rb/rrb

### Error Handling

The program handles:
- Non-numeric arguments
- Duplicate numbers
- Numbers outside INT range
- Empty input
- Invalid characters

All errors print `Error\n` to stderr and exit with status 1.

### Memory Management

- All allocated memory is freed before exit
- No memory leaks (verified with valgrind)
- Proper cleanup on error conditions

---

## Testing

### Manual Testing

```bash
# Test sorted input (should output nothing)
./push_swap 1 2 3 4 5

# Test reverse sorted
./push_swap 5 4 3 2 1

# Test edge cases
./push_swap 2147483647 -2147483648
./push_swap 0
./push_swap "1 2 3"

# Test error cases
./push_swap 1 2 3 2        # Duplicate
./push_swap 1 2 abc        # Non-numeric
./push_swap 9999999999     # Out of INT range
```

### Automated Testing

```bash
# Using a tester (example)
git clone https://github.com/LeoFu9487/push_swap_tester
cd push_swap_tester
./test.sh [path_to_push_swap]
```

### Visualization

You can use a visualizer to see the sorting process:

```bash
# Clone visualizer
git clone https://github.com/o-reo/push_swap_visualizer
cd push_swap_visualizer

# Run with your push_swap
python3 visualizer.py [path_to_push_swap]
```

### Memory Leak Testing

```bash
# Check for memory leaks
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1

# Should show: All heap blocks were freed -- no leaks are possible
```

---

## Resources

### Algorithm Understanding
- [Push_swap Tutorial - 42Docs](https://harm-smits.github.io/42docs/projects/push_swap)
- [Turk Algorithm Explanation](https://github.com/ayogun/push_swap_tutorial)
- [Sorting Algorithms Visualization](https://www.toptal.com/developers/sorting-algorithms)

### Data Structures
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)
- [Linked Lists in C](https://www.geeksforgeeks.org/data-structures/linked-list/)

### Testing Tools
- [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Push_swap Tester](https://github.com/LeoFu9487/push_swap_tester)
- [Another Tester](https://github.com/gemartin99/Push-Swap-Tester)

---

## AI Usage

This project was developed with AI assistance for:
- Understanding the Turk algorithm approach
- Debugging complex pointer operations
- Optimizing the cost calculation logic
- Code structure and organization suggestions
- README documentation

All core logic and implementation decisions were made by the developer, with AI serving as a learning and debugging tool.

---

## Author

**Pedro de Almeida**
- 42 Login: `pedde-al`
- Campus: 42 Lisboa

---

## 📝 License

This project is part of the 42 School curriculum and follows the school's academic integrity policies.

---

## ✅ Project Status

- [x] Mandatory part complete
- [x] Error handling implemented
- [x] Memory management verified
- [x] Performance benchmarks met
- [ ] Bonus (checker) - Optional

**Estimated Grade:** 100/100

---

## 🎓 Learning Outcomes

Through this project, I learned:

1. **Algorithm Optimization**: Understanding trade-offs between simplicity and efficiency
2. **Data Structures**: Deep dive into linked lists and stack operations
3. **Memory Management**: Proper allocation/deallocation in C
4. **Problem Decomposition**: Breaking complex problems into manageable functions
5. **Cost Analysis**: Calculating and minimizing operation costs
6. **Edge Case Handling**: Robust input validation and error management

---

*Last Updated: January 2026*
*Project Completion: Milestone 2 - 42 Common Core*
