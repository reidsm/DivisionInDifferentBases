#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <bitset>
using namespace std;

int getNumDigits (int dividend) {
    return dividend > 0 ? (int) log10 ((double) dividend) + 1 : 1;
}

void divide(vector<int> splitNum, int dividend, int divisor) {
    vector<int> answer;
    int remainder = 0;
    int numToSubtract = 0;
    dividend = splitNum.at(0);
    for(int i = 0; i < splitNum.size(); i++) {
        int multiplier = 10;
        cout << "Divisor: " << divisor << " "<< endl;
        cout << "Goes into: " << dividend << " ";
        cout << dividend / divisor << "times " << endl;
        answer.push_back(dividend / divisor);
        numToSubtract = (dividend / divisor) * divisor;
        remainder = dividend - numToSubtract;
        if(i < splitNum.size() - 1) {
            cout << "----" << endl;
            cout << "Remainder " << remainder << endl;
            cout << "Subrtract: " << numToSubtract << endl;
            cout << "Adding " << splitNum.at(i + 1) << endl;
            dividend = remainder * multiplier + splitNum.at(i + 1);
            cout << "New dividend: " << dividend << endl;
            cout << "-------------------" << endl;
        }
    }
    for(int n : answer)
        cout << n;
    int sum = 0;

    int j = answer.size() - 1;
    for(int i = 0; i < answer.size(); i++) {
        sum += answer.at(j) * pow(10, i);
        j--;
    }
    cout << "Sum: " << sum << endl;
    cout << "Remainder: " << bitset<8>(remainder) << endl;
}

vector<int> splitNum(int dividend) {
    vector<int> digits;
    int numDigitsInDividend = getNumDigits(dividend);
    int temp = dividend;

    for(int i = 0; i < numDigitsInDividend; i++) {
        digits.push_back(temp % 10);
        temp /= 10;
    }

    vector<int> numDigitsInOrder;
    for(int i = digits.size() - 1; i >= 0; i--) {
        numDigitsInOrder.push_back(digits.at(i));
    }

    return numDigitsInOrder;

}

int main() {

    int dividend;
    int divisor;

    cout << "Enter your dividend." << endl;

    cin >> dividend;

    cout << "Enter your divisor." << endl;

    cin >> divisor;


    vector<int> digits = splitNum(dividend);
    divide(digits, dividend, divisor);


    return 0;
}
