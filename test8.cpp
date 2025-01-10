/*Test Exercise 8*/
/*ТОТО-2
В играта Тото-2 се избират 6 числа от 49. Нека а1 < а2 < а3 < а4 < а5 < а6 и б1 < б2 < б3 < б4 < б5 < б6 са две комбинации, които означаваме с A и B, съответно. Казваме, че A < B, когато aj = bj, при j < i и ai < bi, за някоя стойност на i от 1 до 6. Да се напише програма, която по дадени две комбинации А и В, намира броя на комбинациите X, за които А < X < B.

Input Format

За всеки тестов пример от първия ред на стандартния вход се въвеждат числата от комбинация А, а от втория ред – числата от комбинация B, като А < B. Числата във всяка комбинация са различни и са подредени по големина.

Constraints

.

Output Format

На стандартния изход за всеки тестов пример на отделен ред да се изведе търсения брой.

Sample Input 0

2 9 17 28 34 46
2 9 17 30 32 45
Sample Output 0

328
*/
/*
#include <iostream>
#include <vector>

using namespace std;

bool isBetween(const vector<int>& A, const vector<int>& B, const vector<int>& X) {
    for (int i = 0; i < 6; i++) {
        if (X[i] < A[i]) return false;
        if (X[i] > B[i]) return false;
        if (X[i] > A[i] && X[i] < B[i]) return true; 
    }
    return false;
}

void countCombinations(vector<int>& combination, int start, int depth,
                       const vector<int>& A, const vector<int>& B, int& count) {
    if (depth == 6) {
        if (isBetween(A, B, combination)) {
            count++;
        }
        return;
    }
    for (int i = start; i <= 49; i++) {
        combination[depth] = i;
        countCombinations(combination, i + 1, depth + 1, A, B, count);
    }
}

int main() {
    vector<int> A(6), B(6);
    for (int i = 0; i < 6; i++) cin >> A[i];
    for (int i = 0; i < 6; i++) cin >> B[i];

    int count = 0;
    vector<int> combination(6);
    countCombinations(combination, 1, 0, A, B, count);

    cout << count << endl;

    return 0;
}*/
#include <iostream>
#include <vector>

using namespace std;

// Function to compute factorial
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to compute combinations C(n, k)
long long combinations(int n, int k) {
    if (k > n || k < 0) return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    vector<int> A(6), B(6);
    
    // Input combination A and B
    for (int i = 0; i < 6; i++) cin >> A[i];
    for (int i = 0; i < 6; i++) cin >> B[i];

    // Calculate the valid range
    int low = A[5];  // The last number in A
    int high = B[0]; // The first number in B

    // Calculate the number of available numbers in the range (low, high)
    int totalNumbers = high - low - 1; // Numbers strictly between A and B

    // We need to choose 6 numbers from the available numbers
    long long result = combinations(totalNumbers, 6);

    cout << result << endl;

    return 0;
}

