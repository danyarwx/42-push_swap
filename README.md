*This project has been created as part of the 42 curriculum by dzhukov.*

# push_swap

## Description

`push_swap` is a sorting project from the 42 curriculum. The goal is to sort a stack of integers in ascending order using only a limited set of stack operations and to output the smallest possible sequence of instructions.

This repository contains a `push_swap` program that:

- parses integer arguments from the command line
- validates input and rejects invalid or duplicate values
- sorts very small inputs with a dedicated tiny-sort routine
- sorts larger inputs by moving values between stack `a` and stack `b` and choosing efficient rotations before each push

The project focuses on algorithmic thinking, cost evaluation, input validation, and writing clean low-level C code under constrained rules.

## Instructions

### Requirements

- A C compiler such as `cc`
- `make`
- The bundled `ft_printf` library included in this repository

### Build

Build the project from the repository root:

```sh
make
```

The root `Makefile` automatically:

- builds `ft_printf`
- compiles the project source files into `obj/`
- links the final executable as `push_swap`

Useful maintenance targets:

```sh
make clean
make fclean
make re
```

### Run

Pass the numbers to sort as command-line arguments:

```sh
./push_swap 2 1 3 6 5 8
```

You can also pass them as a single quoted string:

```sh
./push_swap "2 1 3 6 5 8"
```

The program prints the list of stack operations needed to sort the input.

### Accepted operations

The program uses the standard `push_swap` instruction set:

- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

### Validation

The program should print `Error` when:

- a value is not a valid integer
- a value is outside the `int` range
- duplicate numbers are provided

### Local testing

Example:

```sh
ARG="3 2 5 1 4"
./push_swap $ARG
```

If you want to validate the output with the checker included in this repository:

```sh
ARG="3 2 5 1 4"
./push_swap $ARG | ./checker_Mac $ARG
```

## Resources

### Useful links

- [Oceano push_swap video](https://youtu.be/OaG81sDEpVk?si=k_rcP2AcNKTou5fu)
- [push_swap tutorial video](https://youtu.be/wRvipSG4Mmk?si=ly63yTJ5nk460cIx)
- [push_swap article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [push_swap visualizer](https://push.eliotlucas.ch/)

### AI usage

AI was used in this project as a support tool for:

- explaining push_swap sorting algorithms in simpler terms
- giving examples and test cases to try out the sorting algorithms
- helping understand the logic behind the sorting strategies before coding them
- suggesting documentation structure and drafting this README
