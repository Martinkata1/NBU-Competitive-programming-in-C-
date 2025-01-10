/*K-torki
Дадено е множество, състоящо се от n различни елемента (0 < n < 20). Напишете 
програма, която намира броя на всичките различни ненаредени k-торки (
0 < k < 51) от негови елементи такива, че i-тият елемент на даденото множество 
участва във всяка k-торка точно bi,1 пъти или точно bi,2 пъти, ..., или точно bi,ji  
пъти.

Input Format

Програмата чете данните от стандартния вход, като на първия ред е даден броят на 
тестовете. За всеки тест стойностите на n и k са написани на отделен ред, след който 
следват n реда. На първо място в i-тия от тези редове е записан броят на 
следващите числа в реда, които са стойностите на bi,1 , bi,2 ,... , bi,ji  (цели числа, по-
големи или равни на 0 и по-малки от 10).

Output Format

За всеки тестов пример програмата трябва да изведе на отделен ред на стандартния изход търсения брой.

Sample Input 0

2
3 4
2 0 1
2 0 3
4 1 2 3 4
3 4
2 0 3
2 1 2
2 0 1
Sample Output 0

3
1
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <cinttypes>

int64_t countKTuples(int idx, int remaining, const vector<vector<int>>& b, vector<vector<int64_t>>& dp) {
    if (idx == b.size()) {
        return (remaining == 0) ? 1 : 0;
    }

    if (dp[idx][remaining] != -1) {
        return dp[idx][remaining];
    }

    int64_t result = 0;
    for (int count : b[idx]) {
        if (remaining >= count) {
            result += countKTuples(idx + 1, remaining - count, b, dp);
        }
    }

    return dp[idx][remaining] = result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> b(n);
        for (int i = 0; i < n; i++) {
            int count;
            cin >> count;
            b[i].resize(count);
            for (int j = 0; j < count; j++) {
                cin >> b[i][j];
            }
        }

        vector<vector<int64_t>> dp(n, vector<int64_t>(k + 1, -1));
        cout << countKTuples(0, k, b, dp) << endl;
    }

    return 0;
}