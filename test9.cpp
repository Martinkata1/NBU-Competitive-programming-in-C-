/*Test Exercise 9*/
/*В света има 46 страни (включително Боливия и Монголия, например), които са без излаз на море, т.е. нито една част от територията им не граничи с вода. Ако един монголец иска да стигне до вода, може да премине през Русия или Китай. Има страни, на които всички съседи са без излаз на море и за да се отиде на море оттам, трябва да се премине през няколко различни държави.

Вашата задача е, по дадена карта (мрежа от квадратни клетки) да определите отдалечеността на всяка страна от водата, т.е. минималният брой страни, през които трябва да се премине, за да се отиде от тази страна до море. Движението от клетка в клетка е хоризонтално, вертикално или диагонално. Ако една държава се състои от „анклави“ (несвързани едно с друго парчета), тогава отдалечеността ѝ е равна на отдалечеността на най-близкия до вода анклав. Клетките представляващи море са запълнени с буквата 'W', а клетките, представящи държави – с някоя друга буква.

Input Format

Първият ред на стандартния вход ще съдържа броя на тестовите примери. Всеки от тях започва с размерите N и M на картата, 1 ≤ N, M ≤ 1000. Следват N реда с по M главни латински букви на всеки. Различните букви означават различни държави, а единствено буквата 'W' обозначава вода.

Constraints

.

Output Format

За всеки тест програмата трябва да изведе на отделен ред на стандартния изход за всяка участваща държава идентифициращата я буква и отдалечеността ѝ. Държавите трябва да са подредени в лексикографски ред на означаващите ги букви. Извеждайте по един празен ред между всеки два последователни теста.

Sample Input
1
7 10
WWWWWCCDEW
WWWWCCEEEW
WTWWWCCCCW
WWFFFFFFWW
WWFAAAAFWW
WWFABCAFFW
WWFAAAAFWW
Sample Output

A 1
B 2
C 0
D 1
E 0
F 0
T 0
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

struct Cell {
    int row, col;
};

const int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dc[] = {0, 0, -1, 1, -1, 1, -1, 1}; 

void bfsWaterDistance(vector<string>& grid, vector<vector<int>>& distance) {
    int n = grid.size();
    int m = grid[0].size();
    queue<Cell> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'W') {
                distance[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        Cell cell = q.front();
        q.pop();

        for (int d = 0; d < 8; ++d) {
            int nr = cell.row + dr[d];
            int nc = cell.col + dc[d];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (distance[nr][nc] > distance[cell.row][cell.col] + 1) {
                    distance[nr][nc] = distance[cell.row][cell.col] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        bfsWaterDistance(grid, distance);

        map<char, int> countryDistance;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char country = grid[i][j];
                if (country != 'W') {
                    if (countryDistance.find(country) == countryDistance.end()) {
                        countryDistance[country] = distance[i][j];
                    } else {
                        countryDistance[country] = min(countryDistance[country], distance[i][j]);
                    }
                }
            }
        }
        for (const auto& entry : countryDistance) {
            cout << entry.first << " " << entry.second << endl;
        }

        if (t > 0) cout << endl; 
    }

    return 0;
}