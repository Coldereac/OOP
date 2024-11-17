#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class BigInt {
    string digits;
    bool isNegative; // New member to store the sign

public:
    BigInt(long long nr = 0) {
        isNegative = nr < 0;
        if (isNegative) nr = -nr;
        do {
            digits.push_back(nr % 10 + '0');
            nr /= 10;
        } while (nr);
    }

    BigInt(const char *s) {
        digits = "";
        isNegative = false;
        int start = 0;
        if (s[0] == '-') {
            isNegative = true;
            start = 1;
        }
        for (int i = strlen(s) - 1; i >= start; i--) {
            if (!isdigit(s[i]))
                throw invalid_argument("Invalid character in number");
            digits.push_back(s[i]);
        }
    }

    BigInt(const BigInt &a) {
        digits = a.digits;
        isNegative = a.isNegative;
    }

    BigInt negate() const {
        BigInt result = *this;
        result.isNegative = !result.isNegative;
        return result;
    }

    BigInt abs() const {
        BigInt result = *this;
        result.isNegative = false;
        return result;
    }

    friend bool empty(const BigInt &a) {
        if (a.digits.size() == 1 && a.digits[0] == 0)
            return true;
        return false;
    }

    friend bool operator<(const BigInt &, const BigInt &);

    friend bool operator==(const BigInt &, const BigInt &);

    friend const BigInt operator+(const BigInt &, const BigInt &);

    friend const BigInt operator-(const BigInt &, const BigInt &);

    friend const BigInt operator*(const BigInt &, const BigInt &);

    friend const BigInt operator/(const BigInt &, const BigInt &);

    friend ostream &operator<<(ostream &, const BigInt &);

private:
    // Helper functions
    static bool absLess(const BigInt &a, const BigInt &b) {
        if (a.digits.size() != b.digits.size())
            return a.digits.size() < b.digits.size();
        for (int i = a.digits.size() - 1; i >= 0; i--)
            if (a.digits[i] != b.digits[i])
                return a.digits[i] < b.digits[i];
        return false;
    }
};

bool operator<(const BigInt &a, const BigInt &b) {
    if (a.isNegative != b.isNegative)
        return a.isNegative;
    if (a.isNegative)
        return BigInt::absLess(b, a);
    return BigInt::absLess(a, b);
}

bool operator==(const BigInt &a, const BigInt &b) {
    return a.isNegative == b.isNegative && a.digits == b.digits;
}

bool operator <=(const BigInt &a, const BigInt &b) {
    return a < b || a == b;
}

const BigInt operator+(const BigInt &a, const BigInt &b) {
    if (a.isNegative == b.isNegative) {
        BigInt result;
        result.digits.pop_back();
        result.isNegative = a.isNegative;
        int carry = 0, i;
        int n = a.digits.size(), m = b.digits.size();
        for (i = 0; i < n || i < m || carry; i++) {
            int sum = carry;
            if (i < n) sum += a.digits[i] - '0';
            if (i < m) sum += b.digits[i] - '0';
            carry = sum / 10;
            result.digits.push_back(sum % 10 + '0');
        }
        return result;
    }
    // Handle addition when one number is negative
    if (a.isNegative)
        return b - BigInt(a).abs();
    return a - BigInt(b).abs();
}

const BigInt operator-(const BigInt &a, const BigInt &b) {
    if (a.isNegative != b.isNegative) {
        return a + BigInt(b).negate();
    }
    if (BigInt::absLess(a, b)) {
        BigInt result = b - a;
        result.isNegative = !a.isNegative;
        return result;
    }
    BigInt result;
    result.isNegative = a.isNegative;
    result.digits.pop_back();
    int borrow = 0, i;
    for (i = 0; i < a.digits.size(); i++) {
        int sub = a.digits[i] - '0' - borrow;
        if (i < b.digits.size())
            sub -= b.digits[i] - '0';
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else
            borrow = 0;
        result.digits.push_back(sub + '0');
    }
    while (result.digits.size() > 1 && result.digits.back() == '0')
        result.digits.pop_back();
    return result;
}

const BigInt operator*(const BigInt &a, const BigInt &b) {
    BigInt result;
    result.isNegative = a.isNegative != b.isNegative;
    result.digits = string(a.digits.size() + b.digits.size(), '0');
    for (int i = 0; i < a.digits.size(); i++) {
        int carry = 0;
        for (int j = 0; j < b.digits.size() || carry; j++) {
            int mul = result.digits[i + j] - '0';
            if (j < b.digits.size())
                mul += (a.digits[i] - '0') * (b.digits[j] - '0');
            mul += carry;
            result.digits[i + j] = mul % 10 + '0';
            carry = mul / 10;
        }
    }
    while (result.digits.size() > 1 && result.digits.back() == '0')
        result.digits.pop_back();
    return result;
}

const BigInt operator/(const BigInt &a, const BigInt &b) {
    if (b.digits == "0")
        throw invalid_argument("Division by zero");

    int negativity = (a.isNegative != b.isNegative) ? -1 : 1;

    // We'll handle division with absolute values first
    BigInt dividend = a.abs();
    BigInt divisor = b.abs();
    long long counter = 0;
    while (divisor <= dividend) {
        dividend = dividend - divisor;
        counter++;
    }
    BigInt result = BigInt(counter * negativity);
    // Return the result with the appropriate sign
    return result;
}


ostream &operator<<(ostream &os, const BigInt &a) {
    if (a.isNegative)
        os << '-';
    for (int i = a.digits.size() - 1; i >= 0; i--)
        os << a.digits[i];
    return os;
}

// Приклад використання
int main() {
    BigInt a("12345678901234567890");
    cout << "a = " << a << endl;
    BigInt b("98765432109876543210");
    cout << "b = " << b << endl;
    BigInt c("-12345678901234567890");
    cout << "c = " << c << endl;
    try {
        BigInt d("Hello");
    } catch (exception &e) {
        cout << "Creating BigInt with non-number string: " << e.what() << endl;
    }
    char *number = "98765432109876543210";
    cout << "a + b = " << a + b << endl;
    cout << "b - a = " << b - a << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "a + c = " << a + c << endl;
    cout << "b - c = " << b - c << endl;
    cout << "a / c = " << a / c << endl;
    cout << "b / c = " << b / c << endl;
    cout << "b * c = " << b * c << endl;
    cout << "a - 1234567890(long) = " << a - 1234567890ll << endl;
    cout << "1234567890(long) + b = " << 1234567890ll + b << endl;
    cout << "b * 987654321(char*) = " << b * number << endl;
    cout << "987654321(char*) * b = " << number * b << endl;
    cout << "a / 400000000000000 = " << a / 400000000000000ll << endl;
    cout << "98765432109876543210(char*) / b = " << number / b << endl;

    //Errors
    try {
        cout << a / 0ll;
    } catch (exception &e) {
        cout << "Dividing by zero error: " << e.what() << endl;
    }
    return 0;
}
