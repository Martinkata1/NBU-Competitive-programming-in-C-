/* Test 3 exercise*/
/*Дадени са два правоъгълника със страни успоредни на координатните оси. Да се намерят: сумата от лицата им, лицето на обединението и сечението им.

Input Format

На всеки от редовете на стандартния вход ще бъде зададена по една двойка правоъгълници с осем цели неотрицателни числа - координати на горния ляв и долния десен ъгъл на единия и другия правоъгълник.

Constraints

Всички числа са по-малки или равни на 100.

Output Format

За всяка двойка правоъгълници, на един ред на стандартния изход програмата трябва да изведе 3 числа – сумата от лицата на двата правоъгълника, лицето на обединението и лицето на сечението им.

Sample Input 0

0 1 1 0 0 2 2 0
0 1 1 0 2 1 3 0
0 2 3 1 1 3 2 0
Sample Output 0

5 4 1
2 2 0
6 5 1
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x1_1, y1_1, x2_1, y2_1;
    int x1_2, y1_2, x2_2, y2_2;
    
    while (cin >> x1_1 >> y1_1 >> x2_1 >> y2_1 >> x1_2 >> y1_2 >> x2_2 >> y2_2) {
        int area1 = (x2_1 - x1_1) * (y1_1 - y2_1);
        int area2 = (x2_2 - x1_2) * (y1_2 - y2_2);
        
        int x_left = max(x1_1, x1_2);
        int y_top = min(y1_1, y1_2);
        int x_right = min(x2_1, x2_2);
        int y_bottom = max(y2_1, y2_2);

        int intersectionArea = 0;
        if (x_left < x_right && y_bottom < y_top) {
            intersectionArea = (x_right - x_left) * (y_top - y_bottom);
        }

        int unionArea = area1 + area2 - intersectionArea;

        cout << (area1 + area2) << " " << unionArea << " " << intersectionArea << endl;
    }

    return 0;
}
