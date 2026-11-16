# Complex Number Calculator

A C++ project that models complex numbers and demonstrates arithmetic with operator overloading.

## Features

- Addition, subtraction, multiplication, and division of complex numbers
- Arithmetic between complex numbers and supported real-number types
- Division-by-zero exception handling
- Readable display of complex numbers
- Comparison, increment/decrement, and compound-assignment operators
- Magnitude calculation using the call operator

## Complex Number Representation

A complex number is represented as:

```text
z = a + bj
```

Where:

- `a` is the real part.
- `b` is the imaginary part.
- `j` is the imaginary unit.

## Requirements

- A C++ compiler, such as GCC or Clang
- C++11 or later

## Build and Run

Compile the program from the project directory:

```bash
g++ -std=c++11 complex_operations.cpp -o complex_operations
```

Run the executable:

```bash
./complex_operations
```

## Example

Given:

```text
c1 = 1 + 2j
c2 = 7 + 5j
```

Multiplication:

```text
c2 * c1 = -3 + 19j
```

Division:

```text
c2 / c1 = 3.4 - 1.8j
```

The program's `main` currently demonstrates calculating the magnitude of a complex number.

## Concepts Practiced

- Classes and objects
- Constructors and encapsulation
- Getters and setters
- Operator overloading
- Constant member functions
- Exception handling
- Floating-point arithmetic
