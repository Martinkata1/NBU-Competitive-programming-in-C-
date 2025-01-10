/*Test 6 exercise*/
/*Стоки, предлагани от автомат се продават за цяло число левове. Автоматът връща ресто под формата на монети от един лев, както и банкноти от по пет и по десет лева. Напишете програма за автомата, като сe спазват следните две условия:
1. При всяка отделна покупка рестото съдържа по-малко от 5 монети.
2. При всяка отделна покупка рестото съдържа по-малко от две банкноти от 5 лева.

Input Format

Всеки отделен ред на стандартния вход описва един тестов пример, съдържащ две цели положителни числа. Първото е стойността на покупката, а второто - парите въведени в автомата. Краят на входа е ред, съдържащ две нули.

Constraints

Автоматът съдържа стоки за 10000 лева и може да връща неограничен брой банкноти и монети.

Output Format

За всеки тестов пример извеждайте по един отделен ред, състоящ се от: номера на поредния тест, рестото, броят на десет и пет левовите банкноти, както и този на монетите от един лев, върнати от автомата за конкретния пример. Изходът да бъде форматиран, както е показано по-долу.

Sample Input 0

72 100
37 200
5 50
0 0    
Sample Output 0

Case 1: 28 = 2 * 10 + 1 * 5 + 3 * 1
Case 2: 163 = 16 * 10 + 0 * 5 + 3 * 1
Case 3: 45 = 4 * 10 + 1 * 5 + 0 * 1
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
    int purchase, inserted, test_case = 1;
    while (cin >> purchase >> inserted && (purchase != 0 || inserted != 0)) {
        int change = inserted - purchase;
        int tens = change / 10;
        int fives = 0, ones = 0;
    
        if (tens > 0) {
            if (change % 10 >= 5 && tens > 1) {
                tens--;
                fives = 1;
                ones = (change - tens * 10 - fives * 5);
            } else {
                ones = change % 10;
            }
        } else {
            fives = change / 5;
            ones = change % 5;
        }

        if (ones >= 5) {
            ones -= 5;
            fives++;
        }

        cout << "Case " << test_case++ << ": " << change 
             << " = " << tens << " * 10 + " << fives 
             << " * 5 + " << ones << " * 1" << endl;
    }
    
    return 0;*/
     int purchase, inserted, test_case = 1;
    while (cin >> purchase >> inserted && (purchase != 0 || inserted != 0)) {
        int change = inserted - purchase;

        int tens = change / 10;        
        change %= 10;                   
        
        int fives = change / 5;         
        change %= 5;                    
        int ones = change;              

        cout << "Case " << test_case++ << ": " << (inserted - purchase)
             << " = " << tens << " * 10 + " << fives 
             << " * 5 + " << ones << " * 1" << endl;
    }
    
    return 0;
}
