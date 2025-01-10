/*Otsechki

Върху числовата права са дадени N отсечки с целочислени координати на 
краищата си. Напишете програма, която за всяка целочислена точка от правата, 
пресмята броят на дадените отсечки към които тя принадлежи. Нека максималната 
стойност на този брой е m, a броят на целочислените точки, принадлежащи към точно m отсечки е p.

Input Format

От първия ред програмата прочита броя на тестовите примери. Всеки тестов 
пример започва с ред, съдържащ броя N на дадените отсечки и на следващите N 
реда са дадени по две цели числа – координатите на левия и на десния край на 
поредната отсечка.

Constraints

Броят на тестовите примери е по-малък от 15;

1 <= N <= 100 000;

стойностите на координатите са в интервала [-1 000 000 000, 1 000 000 000];

координатата на левия край на всяка отсечка е по-малка от координатата на десния край;

Output Format

За всеки тестов пример да се изведат на един ред стойностите на m и p, като цели числа, разделени с един интервал.

Sample Input 0

2
2
1 2
3 4
3
1 5
1 4
3 4
Sample Output 0

1 4
3 2
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int N;
        cin >> N;

        vector<pair<int, int>> events;

        for (int i = 0; i < N; ++i) {
            int left, right;
            cin >> left >> right;
            events.push_back({left, 1});
            events.push_back({right + 1, -1});
        }

        sort(events.begin(), events.end());

        int currentCount = 0, maxCount = 0, maxCountPoints = 0;
        int lastPoint = events[0].first;

        for (size_t i = 0; i < events.size(); ++i) {
            if (currentCount == maxCount) {
                maxCountPoints += events[i].first - lastPoint;
            } else if (currentCount > maxCount) {
                maxCount = currentCount;
                maxCountPoints = events[i].first - lastPoint;
            }

            currentCount += events[i].second;
            lastPoint = events[i].first;
        }

        cout << maxCount << " " << maxCountPoints << endl;
    }

    return 0;
}