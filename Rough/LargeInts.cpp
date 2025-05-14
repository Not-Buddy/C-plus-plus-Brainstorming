#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Remove leading zeros; if all zeros, leave a single "0"
string trimLeadingZeros(const string &s) {
    size_t pos = s.find_first_not_of('0');
    if (pos == string::npos) 
        return "0";
    return s.substr(pos);
}

// Pad two strings with leading zeros so they have the same length
void makeEqualLength(string &a, string &b) {
    int diff = a.size() - b.size();
    if (diff > 0) 
        b = string(diff, '0') + b;
    else if (diff < 0) 
        a = string(-diff, '0') + a;
}

// Add two non-negative integer strings
string addStrings(string a, string b) {
    makeEqualLength(a, b);
    int carry = 0;
    string res;
    for (int i = a.size() - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        res.push_back(char('0' + (sum % 10)));
        carry = sum / 10;
    }
    if (carry) res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}

// Subtract b from a (assumes a >= b)
string subtractStrings(string a, string b) {
    makeEqualLength(a, b);
    string res;
    int borrow = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        int diff = (a[i] - '0') - (b[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.push_back(char('0' + diff));
    }
    reverse(res.begin(), res.end());
    // Trim leading zeros
    return trimLeadingZeros(res);
}

// Karatsuba multiply two non-negative integer strings
string karatsuba(string x, string y) {
    // Remove leading zeros
    x = trimLeadingZeros(x);
    y = trimLeadingZeros(y);
    if (x == "0" || y == "0") 
        return "0";
    if (x.size() == 1 && y.size() == 1) 
        return to_string((x[0] - '0') * (y[0] - '0'));

    // Make lengths equal and even
    int m = max(x.size(), y.size());
    if (m & 1) ++m;
    x = string(m - x.size(), '0') + x;
    y = string(m - y.size(), '0') + y;

    int half = m / 2;
    string xL = x.substr(0, half), xR = x.substr(half);
    string yL = y.substr(0, half), yR = y.substr(half);

    string p1 = karatsuba(xL, yL);
    string p2 = karatsuba(xR, yR);
    string p3 = karatsuba(addStrings(xL, xR), addStrings(yL, yR));
    p3 = subtractStrings(subtractStrings(p3, p1), p2);

    // Shift p1 by 10^m, p3 by 10^half
    p1 += string(m, '0');
    p3 += string(half, '0');

    string result = addStrings(addStrings(p1, p3), p2);
    return trimLeadingZeros(result);
}

int main() {
    string num1, num2;
    cout << "Enter first large number: ";
    cin >> num1;
    cout << "Enter second large number: ";
    cin >> num2;

    cout << "Product: " << karatsuba(num1, num2) << endl;
    return 0;
}

