/*T9

T9 е система, разработена да задоволява растящите нужди за бързо изпращане на текстови съобщения. Системата е базирана на речник в паметта на мобилен телефон. По време на писането е най-добре за всяка буква да се прави само по едно натискане на клавиш (въпреки, че клавишите не стигат...). Извежда се първата дума от речника, която започва с букви, съответстващи на натиснатите клавиши. Подредбата на буквите на клавишите на телефона е показана на таблицата:


1 - space
ABC - 2
DEF - 3
GHI - 4
JKL - 5
MNO - 6
PQRS - 7
TUV - 8
WXYZ - 9

Всяко съобщение се състои от поредица думи, разделени с по един интервал. Напишете програма, която да симулира системата T9, базирана на даден речник.

Input Format

На първия ред на стандартния вход се въвежда цяло число K – броят на тестовите примери. Всеки тестов пример има следната структура:

Първият ред се състои от естествено число M, 1 <= M <= 100, съответстващо на броя на думите в речника. Следващите M реда съдържат самите думи, по една на ред, подредени лексикографски. Думите се състоят от не повече от 100 главни латински букви (A- Z) . На следващия ред е записано естественото число N, 1 <= N <= 100, броят на кликванията по малката и неудобна клавиатурка. На следващия ред има N естествени числа от 1 до 9, разделени с по един интервал. Всяко число съответства на натиснат бутон в реда на писането.

Output Format

За всеки тестов пример се извежда на стандартния изход единствен ред, който по принцип би трябвало да съдържа съобщението, получено от T9. Всяка буква от дума, която не е от речника трябва да бъде заменена със звездичка (*). Ако може да се изведе повече от една дума, то се извежда първата в лексикографска наредба

Sample Input 0

3
3
ABC
BBB
DEF
10
2 2 2 1 2 3 1 2 2 2
4
BOK
GDJE
KAKO
STO
11
2 6 5 1 5 2 5 6 1 7 4
5
GGTMM
GOTOVO
HITNO
ME
NAZOVI
15
6 2 9 6 8 4 1 6 3 1 4 4 8 6 6
Sample Output 0

ABC ** ABC
BOK KAKO ** 
NAZOVI ME GGTMM  
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string convertToT9(string word) {
    string t9;
    for (char c : word) {
        if (c == ' ') t9 += '1';
        else if (c >= 'A' && c <= 'C') t9 += '2';
        else if (c >= 'D' && c <= 'F') t9 += '3';
        else if (c >= 'G' && c <= 'I') t9 += '4';
        else if (c >= 'J' && c <= 'L') t9 += '5';
        else if (c >= 'M' && c <= 'O') t9 += '6';
        else if (c >= 'P' && c <= 'S') t9 += '7';
        else if (c >= 'T' && c <= 'V') t9 += '8';
        else if (c >= 'W' && c <= 'Z') t9 += '9';
    }
    return t9;
}

int main() {
    int K;
    cin >> K;
    while (K--) {
        int M;
        cin >> M;
        vector<string> dictionary(M);
        for (int i = 0; i < M; i++) {
            cin >> dictionary[i];
        }

        int N;
        cin >> N;
        vector<int> clicks(N);
        for (int i = 0; i < N; i++) {
            cin >> clicks[i];
        }

        string input;
        for (int click : clicks) {
            if (click == 1) input += ' ';
            else input += (char)('0' + click);
        }

        string result, word = "";
        for (char c : input) {
            if (c == ' ') {
                if (!word.empty()) {
                    string t9 = convertToT9(word);
                    bool found = false;
                    for (string dictWord : dictionary) {
                        if (convertToT9(dictWord).substr(0, t9.size()) == t9) {
                            result += dictWord + " ";
                            found = true;
                            break;
                        }
                    }
                    if (!found) result += string(word.size(), '*') + " ";
                    word.clear();
                }
            } else {
                word += c;
            }
        }

        if (!word.empty()) {
            string t9 = convertToT9(word);
            bool found = false;
            for (string dictWord : dictionary) {
                if (convertToT9(dictWord).substr(0, t9.size()) == t9) {
                    result += dictWord + " ";
                    found = true;
                    break;
                }
            }
            if (!found) result += string(word.size(), '*') + " ";
        }

        if (!result.empty() && result.back() == ' ') result.pop_back();
        cout << result << endl;
    }
    return 0;
}