#include <iostream>

#include "polynomial.hpp"

int main() {
    Polynomial<int, 4> a{-1, -2, 3, -4, 5, -6};
    Polynomial<int, 6> b{1, 4, -5, 2, -12, 5};

    std::cout << "a(x) = " << a << "\n";
    std::cout << "b(x) = " << b << "\n";

    std::cout << "a(x) + b(x) = " << a + b << "\n";
    std::cout << "a(x) - b(x) = " << a - b << "\n";
    std::cout << "b(x) - a(x) = " << b - a << "\n";

}