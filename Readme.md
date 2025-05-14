
# push_swap

## Overview

`push_swap` is a project that sorts a stack of integers using a limited set of operations.

## Features

- Efficient sorting algorithms for different stack sizes (special handling for small inputs)
- Input validation: checks for numeric input, integer overflow, and duplicates
- Bonus: `checker` program to validate operation sequences
- Bonus: Visualizes stack states after each operation

## Build

Clone the repository and run:

```bash
make
```

To build the bonus checker:

```bash
make bonus
```

## Usage

### Sorting

To output the operations needed to sort a list:

```bash
./push_swap 3 2 1
```

### Checking (Bonus)

To check if a sequence of operations sorts the stack:

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker $ARG
```

If the sequence is correct, `checker` prints `OK`, otherwise `KO`.

### Visualizing (Bonus)

The bonus checker prints the stack state after each operation.

### Example

```bash
ARG="51 21 33 5 1 56"
./push_swap $ARG | ./checker $ARG
```

## Project Structure

- `srcs/` – Main source code (sorting, stack operations, parsing, etc.)
- `bonus/` – Bonus features and checker implementation
- `inc/` – Header files
- `libft/` – Custom libft library


## License

This project is licensed under the MIT License. See the LICENSE file for details.


## Author

- **lakdogan** ([lakdogan@student.42heilbronn.de](mailto:lakdogan@student.42heilbronn.de))
