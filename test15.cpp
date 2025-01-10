/*Putni otsechki

N-те населени места на район, номерирани от 1 до N (N < 1000), са свързани с 
пътища. След като падна сняг, останали проходими само M пътни отсечки, всяка от 
които свързва две различни населени места. Изнервени граждани, които пътуват,
атакуват телефон 112 с въпроси "Може ли да стигнем от X до Y?". Почистващите
служби успяват от време-навреме да почистят някоя от пътните отсечки и 
съобщават на 112: "Пътната отсечка от U до V вече е проходима". Граждани, които 
са се доверили на информацията и са тръгнали на път, обаче, също се обаждат на 
телефон 112 за да поискат помощ с оплакването "Пътната отсечка от U до V отново 
е затрупана". Напишете програма, която да помага на операторите на телефон 112 
да отговарят бързо на въпросите на гражданите за актуалното състояние на 
пътищата.

Input Format

На първия ред на стандартния вход е зададен броят на тестовите случай. 
Стандартния вход за всеки тестови случай започва с ред с числата N и M. На всеки 
от следващите M реда има по два номера на град, свързани с проходима пътна 
отсечка. Следват ред с броя Q на обажданията - както от граждани, така и от пътните служби и Q реда със съдържанието на обажданията - вид на обаждането и двата 
номера на населените места за които се отнася съответното обаждане. Ако 
обаждането е въпрос на гражданин - кодът е 1, ако е съобщение от пътните служби - кодът е 2, а ако е информация от закъсал на пътя гражданин - кодът е 3

Constraints

2 <= N <= 1000
1 <= Q <= 100 000

Output Format

За всеки тестов пример програмата трябва да изведе на стандартния изход битов 
низ с толкова знака, колкото са въпросите на граждани за проходимост на пътната 
мрежа (заявки с код 1), като знак 0 в низа означава, че отговорът на поредния въпрос е "Не", а знак 1 - "Да".

Sample Input 0

1
9 8
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
8
1 1 8
1 6 2
2 7 1
1 4 7
2 2 3
1 4 7
3 3 4
1 4 7
Sample Output 0

10010
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n, m;
        cin >> n >> m;

        UnionFind uf(n);
        vector<pair<int, int>> edges;

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
            edges.push_back({u, v});
        }

        int q;
        cin >> q;
        vector<char> result;

        while (q--) {
            int type, u, v;
            cin >> type >> u >> v;

            if (type == 1) {
                result.push_back(uf.find(u) == uf.find(v) ? '1' : '0');
            } else if (type == 2) {
                uf.unite(u, v);
            } else if (type == 3) {
                vector<pair<int, int>> newEdges;
                for (auto &e : edges) {
                    if ((e.first != u || e.second != v) && (e.second != u || e.first != v)) {
                        newEdges.push_back(e);
                    }
                }

                UnionFind tempUf(n);
                for (auto &e : newEdges) {
                    tempUf.unite(e.first, e.second);
                }
                uf = tempUf;
            }
        }

        for (char c : result) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}