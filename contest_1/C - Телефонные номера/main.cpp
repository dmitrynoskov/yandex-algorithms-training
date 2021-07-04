#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

struct PhoneNumber {
    int code;
    int number;
    bool operator == (const PhoneNumber& phoneNumber) const {
        return (code == phoneNumber.code) && (number == phoneNumber.number);
    }
};

istream& operator>>(istream& istream, PhoneNumber& phoneNumber) {
    string inputString;
    istream >> inputString;
    stringstream sstr(inputString);
    deque<int> numbers;
    int code = 495;
    int number = 0;
    if (sstr.peek() == '+') {
        sstr.get();
    }
    string temp = sstr.str();
    while (isprint(sstr.peek())) {
        if (!isdigit(sstr.peek())) {
            sstr.get();
        }
        numbers.push_back(sstr.get() - '0');
    }
    if (numbers.size() == 11){
        numbers.pop_front();
    }
    if (numbers.size() == 10) {
        code = 0;
        for (int i = 0; i < 3; ++i) {
            code *= 10;
            code += numbers.front();
            numbers.pop_front();
        }
    }
    for (int i = 0; i < 7; ++i) {
        number *= 10;
        number += numbers.front();
        numbers.pop_front();
    }
    phoneNumber.code = code;
    phoneNumber.number = number;
    return istream;
}

bool checkNumber(const PhoneNumber& lhs, const PhoneNumber& rhs) {
    if (lhs == rhs) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    PhoneNumber newNumber, oldNumber1, oldNumber2, oldNumber3;
    cin >> newNumber >> oldNumber1 >> oldNumber2 >> oldNumber3;
    checkNumber(newNumber, oldNumber1);
    checkNumber(newNumber, oldNumber2);
    checkNumber(newNumber, oldNumber3);
    return 0;
}

