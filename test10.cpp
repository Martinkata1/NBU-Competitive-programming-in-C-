/*TEst 10 exercise*/
/*В равнобедрен правоъгълен триъгълник са вписани (без припокриване) n  правоъгълника (0 < n < 200), както е показано на рисунката по-долу. Правоъгълниците имат целочислени координати на върховете си и са със страни, съответно успоредни на катетите на триъгълника, а върховете им лежат върху страните на триъгълника. Напишете програма, която въвежда n и дължината b на катета на триъгълника (цяло положително число, по-малко от 2000), и извежда лицето на най-голямата площ, която може да се покрие с правоъгълниците.


Input Format

Програмата трябва да прочете от стандартния вход броя на тестовите примери (не повече от 10), след което – данните за всеки тестов пример от отделен ред, съдържащ n и b, разделени с интервал

Output Format

На стандарния изход трябва да се изведат търсените лица, всяко на отделен ред, съответно на входните данни.

Sample Input 0

3
1 1
1 2
2 10
Sample Output 0

0
1
33
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; 
    cin >> t;

    while (t--) {
        int n, b; 
        cin >> n >> b;

        int triangleArea = (b * b) / 2;

        if (n == 0 || triangleArea == 0) {
            cout << 0 << endl;
            continue;
        }

        int maxRectangleArea = 0;

        for (int i = 1; i <= n; ++i) {
            int rectWidth = (b / n) * (n - i + 1);
            int rectHeight = (b / n) * (n - i + 1);

            int rectArea = rectWidth * rectHeight;
            maxRectangleArea += rectArea;

            if (maxRectangleArea > triangleArea) {
                maxRectangleArea = triangleArea;
                break;
            }
        }

        cout << maxRectangleArea << endl;
    }

    return 0;
}
