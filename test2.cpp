/*Test 2 exercise*/
/*Polinom
Да се намери най-малката и най-голямата стойност на полинома
Pn(x)= a0 + a1x + a2x^2 + ... + anx^n

в интервала [a,b] за цели стойности на аргумента.
Input Format

За всеки пример на стандартния вход на един ред са дадени числата a,b,a1,a2,...,an.

Constraints

Числата от входа са цели и в интервала [1, 10^6].
2 <= n <= 10
Output Format

За всеки пример на отделен ред на стандартния изход се изведат двете търсени числа.

Sample Input 0

0 10 3 2 1
-10 5 12 -2 3 -4 1
Sample Output 0

3 123
4 14332
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

long long evaluatePolynomial(const vector<int>& coefficients, int x) {
    long long result = 0;
    long long term = 1; 
    for (int coefficient : coefficients) {
        result += coefficient * term;
        term *= x; 
    }
    return result;
}

int main() {
    int a, b;
    while (cin >> a >> b) {  
        vector<int> coefficients;
        int coef;
        
        while (cin >> coef) {
            coefficients.push_back(coef);
            if (cin.peek() == '\n' || cin.peek() == EOF) break;
        }
        
        long long minValue = numeric_limits<long long>::max();
        long long maxValue = numeric_limits<long long>::min();
        
        for (int x = a; x <= b; ++x) {
            long long value = evaluatePolynomial(coefficients, x);
            minValue = min(minValue, value);
            maxValue = max(maxValue, value);
        }
        
        cout << minValue << " " << maxValue << endl;
    }

    return 0;
}
