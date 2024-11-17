#include <cstring>
#include <stdexcept>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class BigInt {
    string digits;

public:
    BigInt(long long nr = 0) {
        do {
            digits.push_back(nr % 10);
            nr /= 10;
        } while (nr);
    }

    BigInt(const char *s) {
        digits = "";
        for (int i = strlen(s) - 1; i >= 0; i--) {
            if (!isdigit(s[i]))
                throw invalid_argument("Wrong number");
            char digit = (s[i] - '0') + '0';
            digits.push_back(digit);
        }
    }

    BigInt(const BigInt &a) {
        digits = a.digits;
    }

    friend bool empty(const BigInt &a);

    friend int Length(const BigInt &a);

    int operator[](const int index) const {
        if (digits.size() <= index || index < 0)
            throw invalid_argument("ERROR");
        return digits[index];
    }

    friend const BigInt operator+(const BigInt &, const BigInt &);

    friend const BigInt operator-(const BigInt &, const BigInt &);

    friend const BigInt operator*(const BigInt &, const BigInt &);

    friend const BigInt operator/(const BigInt &, const BigInt &);

    friend bool operator<(const BigInt &, const BigInt &);

    friend bool operator==(const BigInt &, const BigInt &);

    friend ostream &operator<<(ostream &, const BigInt &);
};

bool operator<(const BigInt &a, const BigInt &b) {
    int n = Length(a), m = Length(b);
    if (n != m)
        return n < m;
    while (n--)
        if (a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}

bool operator==(const BigInt &a, const BigInt &b) {
    return a.digits == b.digits;
}

bool empty(const BigInt &a) {
    if (a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}

int Length(const BigInt &a) {
    return a.digits.size();
}


const BigInt operator+(const BigInt &a, const BigInt &b) {
    BigInt temp(a);
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if (m > n)
        temp.digits.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n; i++) {
        if (i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        temp.digits[i] = (s % 10);
    }
    if (t)
        temp.digits.push_back(t);
    return temp;
}

const BigInt operator-(const BigInt &a, const BigInt &b) {
    BigInt temp(a);
    if (a < b)
        throw underflow_error("Underflow");
    int n = Length(a), m = Length(b);
    int t = 0, s;
    for (int i = 0; i < n; i++) {
        if (i < m)
            s = a.digits[i] - b.digits[i] + t;
        else
            s = a.digits[i] + t;
        if (s < 0) {
            s += 10;
            t = -1;
        } else
            t = 0;
        temp.digits[i] = s;
    }
    while (n > 1 && a.digits[n - 1] == 0) {
        temp.digits.pop_back();
        n--;
    }
    return temp;
}

const BigInt operator*(const BigInt &a, const BigInt &b) {
    BigInt temp(a);
    if (empty(a) || empty(b)) {
        temp = 0ll;
        return temp;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            v[i + j] += (a.digits[i]) * (b.digits[j]);
        }
    n += m;
    temp.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++) {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        temp.digits[i] = v[i];
    }
    for (int i = n - 1; i >= 1 && !v[i]; i--)
        temp.digits.pop_back();
    return temp;
}

const BigInt operator/(const BigInt &a, const BigInt &b) {
    if (empty(b))
        throw invalid_argument("Arithmetic Error: Division By 0");
    BigInt temp(a);
    if (a < b) {
        temp = BigInt();
        return temp;
    }
    if (a == b) {
        temp = BigInt(1);
        return temp;
    }

    int i, lgcat = 0, cc;
    int n = Length(a);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t = t * 10;
        t = t * a.digits[i];
    }
    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; t < (cc * b); cc--);
        t = t - cc * b;
        cat[lgcat++] = cc;
    }
    temp.digits.resize(cat.size());
    for (i = 0; i < lgcat; i++)
        temp.digits[i] = cat[lgcat - i - 1];
    temp.digits.resize(lgcat);
    return temp;
}

ostream &operator<<(ostream &os, const BigInt &a) {
    for (int i = a.digits.size() - 1; i >= 0; i--)
        os << static_cast<short>(a.digits[i]);
    return os;
}

int main() {
    BigInt a("12345678901234567890");
    BigInt b("98765432109876543210");
    try {
        BigInt c("Hello");
    } catch (exception &e) {
        cout << "Creating BigInt with non-number string: " << e.what() << endl;
    }
    char *number = "98765432109876543210";
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << b - a << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "a - 1234567890(long) = " << a - 1234567890ll << endl;
    cout << "1234567890(long) - a = " << 1234567890ll + a << endl;
    cout << "b * 987654321(char*) = " << b * number << endl;
    cout << "98765432109876543210(char*) / b = " << number / b << endl;

    //Errors
    try {
        cout << a / 0ll;
    } catch (exception &e) {
        cout << "Dividing by zero error: " << e.what() << endl;
    }
    try {
        cout << a - b;
    } catch (exception &e) {
        cout << "Subtracting when first number is smaller than second(BigInt is unsigned): " << e.what() << endl;
    }
}
