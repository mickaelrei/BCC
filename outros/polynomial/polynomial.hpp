#pragma once

#include <array>
#include <iostream>

//----------------------------------------------------------//
//                     CLASS DEFINITION                     //
//----------------------------------------------------------//

/// @brief Class that represents a polynomial
/// @tparam T coefficient type
/// @tparam N degree of the polynomial (highest possible exponent term)
template<typename T, size_t N>
class Polynomial {
public:
    /// @brief Default constructor
    Polynomial() = default;

    /// @brief Copy constructor
    /// @param p polynomial to be copied
    Polynomial(const Polynomial<T, N> &p);

    /// @brief Constructor with initializer list
    /// @param list list of coefficients, starting by constant term and going up
    Polynomial(const std::initializer_list<T> list);

    /// @brief Gets coefficient for specified degree
    /// @param n degree of corresponding term
    /// @return Coefficient of term
    T coefficientAt(size_t n) const;

    /// @brief Sets coefficient for specified degree
    /// @param n degree of corresponding term
    void coefficientAt(size_t n, T coefficient);

    Polynomial<T, N> &operator+= (const Polynomial<T, N> &p);
    Polynomial<T, N>  operator+  (const Polynomial<T, N> &p);
    Polynomial<T, N> &operator-= (const Polynomial<T, N> &p);
    Polynomial<T, N>  operator-  (const Polynomial<T, N> &p);

private:
    /// @brief Array containing coefficients of the polynomial
    /// @note Term power goes up, starting at zero (constant term)
    T coefficients[N + 1] = { T{0} };
};

//----------------------------------------------------------//
//                        OPERATORS                         //
//----------------------------------------------------------//

/// @brief Outputs a polynomial
/// @tparam T coefficient type
/// @tparam N degree of the polynomial
/// @param os output stream
/// @param p polynomial to output
/// @return Stream with outputted polynomial
template<typename T, size_t N>
std::ostream &operator<<(std::ostream &os, const Polynomial<T, N> &p);

/// @brief Addition between two polynomials of different degrees
/// @tparam T coefficient type
/// @tparam M degree of first polynomial
/// @tparam N degree of second polynomial
/// @param p0 first polynomial
/// @param p1 second polynomial
/// @return polynomial addition result
template<typename T, size_t M, size_t N>
Polynomial<T, std::max(M, N)> operator+(
    const Polynomial<T, M> &p0,
    const Polynomial<T, N> &p1
);

/// @brief Difference between two polynomials of different degrees
/// @tparam T coefficient type
/// @tparam M degree of first polynomial
/// @tparam N degree of second polynomial
/// @param p0 first polynomial
/// @param p1 second polynomial
/// @return polynomial difference result
template<typename T, size_t M, size_t N>
Polynomial<T, std::max(M, N)> operator-(
    const Polynomial<T, M> &p0,
    const Polynomial<T, N> &p1
);

//----------------------------------------------------------//
//                      IMPLEMENTATION                      //
//----------------------------------------------------------//

template<typename T, size_t N>
Polynomial<T, N>::Polynomial(const Polynomial<T, N> &p) {
    for (size_t i = 0; i < N; ++i) {
        coefficients[i] = p.coefficientAt(i);
    }
}

template<typename T, size_t N>
Polynomial<T, N>::Polynomial(const std::initializer_list<T> list) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        size_t i = std::distance(list.begin(), it);
        if (i >= N) return;

        coefficients[i] = *it;
    }
}

template<typename T, size_t N>
T Polynomial<T, N>::coefficientAt(size_t n) const {
    if (n >= N) {
        return T{0};
    }
    return coefficients[n];
}

template<typename T, size_t N>
void Polynomial<T, N>::coefficientAt(size_t n, T coefficient) {
    if (n >= N) return;

    coefficients[n] = coefficient;
}

template<typename T, size_t N>
std::ostream& operator<<(std::ostream &os, const Polynomial<T, N> &p) {
    for (size_t i = N - 1; i > 0; --i) {
        // Skip null coefficients
        if (p.coefficientAt(i) == T{0}) continue;

        // Output coefficient
        os << p.coefficientAt(i) << "x";

        // If not linear term, output exponent
        if (i > 1) {
            os << "^" << i;
        }

        os << " ";
        if (p.coefficientAt(i - 1UL) >= T{0}) {
            os << "+";
        }
    }

    // Output constant term
    os << p.coefficientAt(0);

    return os;
}

template<typename T, size_t N>
Polynomial<T, N> &Polynomial<T, N>::operator+=(const Polynomial<T, N> &p) {
    for (size_t i = 0; i < N; ++i) {
        coefficients[i] += p.coefficientAt(i);
    }

    return *this;
}

template<typename T, size_t N>
Polynomial<T, N> Polynomial<T, N>::operator+(const Polynomial<T, N> &p) {
    Polynomial<T, N> tmp{*this};
    tmp += p;
    return tmp;
}

template<typename T, size_t N>
Polynomial<T, N> &Polynomial<T, N>::operator-=(const Polynomial<T, N> &p) {
    for (size_t i = 0; i < N; ++i) {
        coefficients[i] -= p.coefficientAt(i);
    }

    return *this;
}

template<typename T, size_t N>
Polynomial<T, N> Polynomial<T, N>::operator-(const Polynomial<T, N> &p) {
    Polynomial<T, N> tmp{*this};
    tmp -= p;
    return tmp;
}

template<typename T, size_t M, size_t N>
Polynomial<T, std::max(M, N)> operator+(
    const Polynomial<T, M> &p0,
    const Polynomial<T, N> &p1
) {
    const size_t S = std::max(M, N);
    Polynomial<T, S> p;

    for (size_t i = 0; i < S; ++i) {
        p.coefficientAt(i, p0.coefficientAt(i) + p1.coefficientAt(i));
    }

    return p;
}

template<typename T, size_t M, size_t N>
Polynomial<T, std::max(M, N)> operator-(
    const Polynomial<T, M> &p0,
    const Polynomial<T, N> &p1
) {
    const size_t S = std::max(M, N);
    Polynomial<T, S> p;

    for (size_t i = 0; i < S; ++i) {
        p.coefficientAt(i, p0.coefficientAt(i) - p1.coefficientAt(i));
    }

    return p;
}