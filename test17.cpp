/*Konkurs.
На студентите-състезатели от N-ския университет им омръзнало да решават чужди 
задачи. Затова организирали конкурс за съставяне на задачи. Главното изискване 
било условията да са кратки, като протест против дългите и често безсмислени 
условия на състезателните задачи. А една задача участвала в класирането само ако 
била решена от по-малко от половината участници на реално организираното 
състезание с участващите в конкурса задачи. Вашата задача е да напишете 
програма за решаване на спечелилата конкурса задача:

Колко са простите числа в редицата ak+b за  k= 0,1,... , n-1.

Input Format

За всеки тестов пример на отделен ред са дадени числата a, b и n.

Constraints

1 <= b <a <= 10 и 1 <= n <=10 000.

Output Format

За всеки тестов пример на отделен ред да се изведе търсеното число.

Sample Input 0

2 1 10
Sample Output 0

7

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool is_prime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;  
    if (num % 2 == 0) return false; 

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b, n;
    while (cin >> a >> b >> n) {
        int prime_count = 0;
        
        for (int k = 0; k < n; ++k) {
            int value = a * k + b;
            if (is_prime(value)) {
                prime_count++;
            }
        }
        
        cout << prime_count << endl;
    }
    return 0;
}
