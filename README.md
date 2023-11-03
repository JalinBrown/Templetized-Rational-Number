# TempletizedRational C++ Class

Author: Jalin Brown
Email: JalinBrownWorks@gmail.com

## Brief Description

This C++ code provides a templetized implementation of the `Rational` class. The template parameter `T` can perform all required arithmetic operations such as addition, subtraction, division, and multiplication. This class allows you to work with rational numbers and perform various operations on them, ensuring proper handling of sign and simplification of fractions.

## Features

- Templetized `Rational` class for working with rational numbers.
- Support for addition, subtraction, multiplication, and division of rational numbers.
- Automatic simplification of fractions.
- Correct handling of sign for negative fractions.
- Comparison operators for rational numbers.
- Access to the numerator and denominator of the rational number.

## Usage

You can use this `Rational` class by including the "TempletizedRational.h" header file and instantiating objects of the class with the desired data type. Then, you can perform arithmetic operations on these rational numbers and compare them using the provided operator overloads.

## Example

```cpp
#include "TempletizedRational.h"

int main()
{
    Rational<int> a(1, 2);  // Represents 1/2
    Rational<int> b(2, 3);  // Represents 2/3

    Rational<int> c = a + b;  // c now holds 7/6

    if (a < b)
    {
        std::cout << "a is less than b." << std::endl;
    }

    std::cout << "Numerator of c: " << c.numerator() << std::endl;
    std::cout << "Denominator of c: " << c.denominator() << std::endl;

    return 0;
}
```
