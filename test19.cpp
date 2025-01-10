/*X2017
Даден е низ от десетични цифри. Напишете програма, която определя по колко 
различни начина може да се получи 2017 от четири от дадените цифри, като се 
разположат в същата последователност, както в началния низ.

Input Format

От първия ред на стандартния вход се въвежда броят на тестовите примери. Всеки 
тестов пример се състои от един ред, на който e записан низ от десетични цифри.

Constraints

Дължината на низовете е най-много 4000.

Output Format

За всеки тестов пример да се изведе търсеният брой на отделен ред на стандартния
 изход.

Sample Input 0

2
352906120127
22001177
Sample Output 0

4
16
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <string>

int main() {
    int64_t testCases;
    cin >> testCases;

    while (testCases--) {
        string input;
        cin >> input;

        int64_t count = 0;
        int64_t count_2 = 0, count_20 = 0, count_201 = 0;

        for (size_t i = 0; i < input.size(); ++i) {
            if (input[i] == '7') {
                count += count_201; 
            } else if (input[i] == '1') {
                count_201 += count_20; 
            } else if (input[i] == '0') {
                count_20 += count_2;
            } else if (input[i] == '2') {
                ++count_2; 
            }
        }

        cout << count << endl;
    }

    return 0;
}