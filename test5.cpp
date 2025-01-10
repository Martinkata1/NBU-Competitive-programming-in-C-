/*Test 5 exercise*/
/*Posledovatelni glasni
Намерете броя на низовете, съставени от малки латински букви с N символа, такива, че не съдържат повече от K последователни гласни. Гласни са латинските букви ‘a’, ‘e’, ‘o’, ‘u’, ‘i’, ‘y’.

Input Format

На първия ред на стандартния вход е зададен броят тестове T. Всеки от следващите T реда съдържа по две цели числа N и K - съответно дължината на низа, който трябва да се състави, и колко най-много последователни гласни може да има в него.

Constraints

 1 <= N, K <= 1000 

Output Format

За всеки тест на отделен ред изведете по едно цяло число - броя възможни низове. Тъй като това число може да е много голямо, го изведете по модул 1000000009.

Sample Input 0

3
3 1 
5 2 
666 42
Sample Output 0

15920
11510720
88651987
*/
/*
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000009;
const int VOWELS = 6;  
const int CONSONANTS = 20;  

int countValidStrings(int N, int K) {
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;

    for (int n = 1; n <= N; ++n) {
        for (int v = 0; v <= K; ++v) {
            dp[n][0] = (dp[n][0] + dp[n - 1][v] * CONSONANTS) % MOD;
        }

        for (int v = 1; v <= K; ++v) {
            dp[n][v] = (dp[n][v] + dp[n - 1][v - 1] * VOWELS) % MOD;
        }
    }

    int result = 0;
    for (int v = 0; v <= K; ++v) {
        result = (result + dp[N][v]) % MOD;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        cout << countValidStrings(N, K) << endl;
    }
    return 0;
}*/
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000009;
const int VOWELS = 6;  
const int CONSONANTS = 20;  

int countValidStrings(int N, int K) {
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    
    dp[0][0] = 1;

    for (int n = 1; n <= N; ++n) {
        for (int v = 0; v <= K; ++v) {
            dp[n][0] = (dp[n][0] + (1LL * dp[n - 1][v] * CONSONANTS) % MOD) % MOD;
        }
        for (int v = 1; v <= K; ++v) {
            dp[n][v] = (dp[n][v] + (1LL * dp[n - 1][v - 1] * VOWELS) % MOD) % MOD;
        }
    }

    int result = 0;
    for (int v = 0; v <= K; ++v) {
        result = (result + dp[N][v]) % MOD;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        cout << countValidStrings(N, K) << endl;
    }
    return 0;
}
