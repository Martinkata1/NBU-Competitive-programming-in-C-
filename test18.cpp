/*The Mask.
Маска наричаме низ състоящ се от малки латински букви и една звезда (*). По 
зададена маска и редица от низове, да се определят низовете, които отговарят на 
маската. Даден низ отговаря на маската, ако след заместването на звездата с 
подходящо избрани (произволен брой) малки латински букви, маската и низа 
съвпадат. Например hello, homo и hohohoho отговарят на маската h*o, а hoh - не.

Input Format

На първия ред на стандартния вход е зададен броят на тестовите примери. Всеки от 
тях започва с числото N - броят на низовете, които ще се тестват. Вторият ред 
съдържа маската - низ, съставен от малки латински букви и точно една звезда (ACSII 
код 42). Следват N реда, като на всеки от тях е зададен по един тестов низ, съставен 
от не повече от 100 малки латински букви.

Constraints

1<= N <= 100 
Дължината на маската е не повече от 100.

Output Format

На стандартния изход на отделен ред да се извежда YES или NO за поредния низ от 
текущия пример в зависимост от това дали той отговаря на маската или не.

Sample Input 0

2 
4
a*a
alabala
ananas
abracadabra
aaa
6 
h*n
hkjdfjfdshodfhscbajkfnxyemfvsn
honijezakon
atila
je
bio
hun
Sample Output 0

YES
NO
YES
YES
YES
YES
NO
NO
NO
YES
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
        int n;
        cin >> n;
        string mask;
        cin >> mask;

        size_t star_pos = mask.find('*');
        string prefix = mask.substr(0, star_pos);
        string suffix = mask.substr(star_pos + 1);

        for (int i = 0; i < n; ++i) {
            string test;
            cin >> test;

            if (test.size() < prefix.size() + suffix.size()) {
                cout << "NO" << endl;
                continue;
            }

            if (test.substr(0, prefix.size()) == prefix &&
                test.substr(test.size() - suffix.size()) == suffix) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}