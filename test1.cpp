/*Test 1 exercise*/
/*Дадени са  типа монети със стойности съответно: c0, c1,..., cn-1,
 и естествено число S. Да се намери броят на различните представяния на s с монети измежду наличните типове. 
 Стойностите c0, c1, ..., cn-1 са цели положителни числа. Всеки тип монети може да участва в сумата неограничен брой пъти.

Input Format

Всеки тестов пример е зададен на два реда на стандартния вход. Първият ред съдържа стойностите на монетите, а втория - сумите, които трябва да се формират от зададените стйности на монетите. Входът съдържа много примери.

Constraints

1 <= s <= 100, 1 <= n <= 100 

Output Format

За всеки пример на отделен ред на стандартния изход се отпечатва броят на различните представяния за всяка сума.

Sample Input 0

1 2 3 4 6
6 5 4 3 2 1
Sample Output 0

10 6 5 3 2 1
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int countWays(const vector<int>& coins, int s) {
    vector<int> array(s + 1, 0);
    array[0] = 1; 

    for (int coin : coins) {
        for (int i = coin; i <= s; i++) {
            array[i] += array[i - coin];
        }
    }

    return array[s];
}

vector<int> parseInput(const string& line) {
    vector<int> result;
    size_t start = 0;
    size_t end = line.find(' ');

    while (end != string::npos) {
        result.push_back(stoi(line.substr(start, end - start)));
        start = end + 1;
        end = line.find(' ', start);
    }
    result.push_back(stoi(line.substr(start)));

    return result;
}

int main() {
    string coinsLine, sumsLine;
    
    while (getline(cin, coinsLine) && getline(cin, sumsLine)) {
        vector<int> coins = parseInput(coinsLine);
        vector<int> sums = parseInput(sumsLine);

        for (size_t i = 0; i < sums.size(); i++) {
            cout << countWays(coins, sums[i]);
            if (i < sums.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
