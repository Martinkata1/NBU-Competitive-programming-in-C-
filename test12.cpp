/* SQUARES

Разглеждат се всички квадрати в равнината, 
които имат целочислени координати на върховете 
си и лица, по-малки или равни на S. Напишете програма, която 
въвежда цялото число S и извежда броя на нееднаквите квадрати от разглеждания вид.

Input Format

Първият ред на стандарния вход представлява броят T 
на тестовите случай(не повече от 10). Следват T реда, 
като всеки ред съдържа цяло число, представляващо стойноста на S.

Constraints

0 < S < 10^8

Output Format

За всеки тестови случай програмата извежда на отделен ред броя на нееднаквите квадрати от разглеждания вид.

Sample Input 0

2
4
25
Sample Output 0

3
13
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    if(T > 10){
        return 0;
    }
    while (T--) {
        int S;
        cin >> S;
        if(S < 0 || S > 100000000){
            return 0;
        }
        int count = 0;
        
        for (int a = 0; a * a <= S; a++) {
            //count += a ; 
            for (int b = 0; b * b <= S; b++) {
                int area = a * a + b * b;
                if (area <= S) {
                    count++;
                    
                }
            
            }

        }
        
        cout << count/2 << "\n";
        
        
    }
    return 0;
}
