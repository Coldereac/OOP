#include <iostream>
#include <sstream>
#include <stdexcept>


class Fraction {
    int numerator;
    int denominator;

    static int findGcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        if (a == 0) {
            return b;
        }
        if (a < b) {
            std::swap(a, b);
        }
        while (a % b != 0) {
            a = a % b;
            std::swap(a, b);
        }
        return b;
    }

public:
    explicit Fraction(int numerator = 0, int denominator = 1) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        this->numerator = numerator;
        this->denominator = denominator;
        if (numerator != 0) {
            reduce();
        }
    }

    explicit Fraction(double value, int precision = 1000000000) {
        this->numerator = static_cast<int>(value * precision);
        this->denominator = precision;
        reduce();
    }

    explicit Fraction(float value, int precision = 1000000000) {
        this->numerator = static_cast<int>(value * precision);
        this->denominator = precision;
        reduce();
    }

    Fraction(const Fraction &fraction) {
        this->numerator = fraction.numerator;
        this->denominator = fraction.denominator;
    }

    void reduce() {
        int gcd = findGcd(std::abs(numerator), denominator);
        numerator /= gcd;
        denominator /= gcd;
    }


    Fraction operator+(const Fraction &other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator-(const Fraction &other) const {
        return Fraction{numerator * other.denominator - other.numerator * denominator, denominator * other.denominator};
    }

    Fraction operator*(const Fraction &other) const {
        return Fraction{numerator * other.numerator, denominator * other.denominator};
    }

    Fraction operator/(const Fraction &other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return Fraction{numerator * other.denominator, denominator * other.numerator};
    }

    template<typename T>
    std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, Fraction>
    operator+(T value) const {
        return *this + Fraction(value);
    }

    template<typename T>
    std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, Fraction>
    operator-(T value) const {
        return *this - Fraction(value);
    }

    template<typename T>
    std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, Fraction>
    operator*(T value) const {
        return *this * Fraction(value);
    }

    template<typename T>
    std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>, Fraction>
    operator/(T value) const {
        if (value == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }
        return *this / Fraction(value);
    }

    friend Fraction &operator++(Fraction &frac);

    friend Fraction operator++(Fraction &frac, int);

    friend Fraction &operator--(Fraction &frac);

    friend Fraction operator--(Fraction &frac, int);

    friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);

    friend std::istream &operator>>(std::istream &is, Fraction &fraction);

    friend bool operator==(const Fraction &left, const Fraction &right);

    friend bool operator!=(const Fraction &left, const Fraction &right);

    friend bool operator<(const Fraction &left, const Fraction &right);

    friend bool operator<=(const Fraction &left, const Fraction &right);

    friend bool operator>(const Fraction &left, const Fraction &right);

    friend bool operator>=(const Fraction &left, const Fraction &right);
};

Fraction &operator++(Fraction &frac) {
    frac.numerator += frac.denominator;
    return frac;
}

Fraction operator++(Fraction &frac, int) {
    Fraction temp(frac);
    ++frac;
    return temp;
}

Fraction &operator--(Fraction &frac) {
    frac.numerator -= frac.denominator;
    return frac;
}

Fraction operator--(Fraction &frac, int) {
    Fraction fraction(frac);
    --frac;
    return fraction;
}


std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}

std::istream &operator>>(std::istream &is, Fraction &fraction) {
    std::cout << "Input numerator: ";
    int numerator, denominator;
    is >> numerator;
    std::cout << "Input denominator: ";
    is >> denominator;
    fraction = Fraction(numerator, denominator);
    return is;
}

bool operator==(const Fraction &left, const Fraction &right) {
    return left.numerator == right.numerator
           && left.denominator == right.denominator;
}

bool operator!=(const Fraction &left, const Fraction &right) {
    return !(left == right);
}

bool operator<(const Fraction &left, const Fraction &right) {
    return left.numerator * right.denominator < right.numerator * left.denominator;
}

bool operator<=(const Fraction &left, const Fraction &right) {
    return left < right || left == right;
}

bool operator>(const Fraction &left, const Fraction &right) {
    return right < left;
}

bool operator>=(const Fraction &left, const Fraction &right) {
    return left > right || left == right;
}

int main() {
    Fraction fraction1 = Fraction(6, 9);
    std::cout << fraction1 << std::endl;
    Fraction fraction2;
    try {
        fraction2 = Fraction(-20, 0);
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
    std::cin >> fraction2;
    std::cout << "Fraction 1: " << fraction1 << std::endl;
    std::cout << "Fraction 2: " << fraction2 << std::endl;
    std::cout << "f1 + f2: " << fraction1 + fraction2 << std::endl;
    std::cout << "f1 - f2: " << fraction1 - fraction2 << std::endl;
    std::cout << "f1 * f2: " << fraction1 * fraction2 << std::endl;
    std::cout << "f1 / f2: " << fraction1 / fraction2 << std::endl;
    std::cout << "Trying to divide f1 by 0/1" << std::endl;
    try {
        std::cout << fraction1 / Fraction() << std::endl;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Fraction + int: " << fraction1 + 2 << std::endl;
    std::cout << "Fraction - int: " << fraction1 - 1 << std::endl;
    std::cout << "Fraction * int: " << fraction1 * 3 << std::endl;
    std::cout << "Fraction / int: " << fraction1 / 2 << std::endl;

    std::cout << "Fraction + float: " << fraction1 + 0.1f << std::endl;
    std::cout << "Fraction - double: " << fraction1 - 0.75 << std::endl;
    std::cout << "Fraction * double: " << fraction1 * 1.5 << std::endl;
    std::cout << "Fraction / double: " << fraction1 / 0.25 << std::endl;

    std::cout << "Both prefix and postfix increment for f1: " << ++fraction1 << " " << fraction1++ << std::endl;
    std::cout << "Bout prefix and postfix decrement for f2: " << --fraction2 << " " << fraction2-- << std::endl;
}
