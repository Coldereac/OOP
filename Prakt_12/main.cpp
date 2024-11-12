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

    void reduce() {
        int gcd = findGcd(std::abs(numerator), denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Fraction(int numerator = 0, int denominator = 1) {
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

    Fraction(double value, int precision = 1000000000) {
        denominator = 1000000;
        numerator = static_cast<int>(value * denominator);
        reduce();
    }

    Fraction(const Fraction &fraction) = default;


    friend const Fraction operator+(const Fraction &first, const Fraction &second);

    friend const Fraction operator-(const Fraction &first, const Fraction &second);

    friend const Fraction operator*(const Fraction &first, const Fraction &second);

    friend const Fraction operator/(const Fraction &first, const Fraction &second);

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

const Fraction operator+(const Fraction &first, const Fraction &second) {
    return Fraction{
        first.numerator * second.denominator + second.numerator * first.denominator,
        first.denominator * second.denominator
    };
}

const Fraction operator*(const Fraction &first, const Fraction &second) {
    return Fraction{first.numerator * second.numerator, first.denominator * second.denominator};
}

const Fraction operator/(const Fraction &first, const Fraction &second) {
    if (second.numerator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return Fraction{first.numerator * second.denominator, first.denominator * second.numerator};
}

const Fraction operator-(const Fraction &first, const Fraction &second) {
    return Fraction{
        first.numerator * second.denominator - second.numerator * first.denominator,
        first.denominator * second.denominator
    };
}

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
    std::cout << "int + Fraction: " << 2 + fraction1 << std::endl;
    std::cout << "Fraction - int: " << fraction1 - 1 << std::endl;
    std::cout << "Fraction * int: " << fraction1 * 3 << std::endl;
    std::cout << "Fraction / int: " << fraction1 / 2 << std::endl;

    std::cout << "Fraction + float: " << fraction1 + 0.1f << std::endl;
    std::cout << "double + Fraction: " << 0.1 + fraction1 << std::endl;
    std::cout << "Fraction - double: " << fraction1 - 0.75 << std::endl;
    std::cout << "Fraction * double: " << fraction1 * 1.5 << std::endl;
    std::cout << "Fraction / double: " << fraction1 / 0.25 << std::endl;

    std::cout << "Both prefix and postfix increment for f1: " << ++fraction1 << " " << fraction1++ << std::endl;
    std::cout << "Bout prefix and postfix decrement for f2: " << --fraction2 << " " << fraction2-- << std::endl;
}
