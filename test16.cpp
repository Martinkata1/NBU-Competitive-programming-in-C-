/*Minimal time
Станчо е започнал нова работа, като доставчик на бира. За първия работен ден 
неговият шеф му дава задача да достави възможно най-бързо бира в N,
2 <= N <= 10 000 , магазина, номерирани с числата от 1 до N. Магазините са 
разделени в две множества A и B, и са свързани с M двупосочни улици. 
Преминаването през улица става за определено време, което е цяло положително 
число <= 1000. Напишете програма, която да помогне на Станчо да определи 
мнималното време за предвижване от магазин от множеството A до някой магазин 
от множеството B.

Input Format

На първия ред на стандартния вход ще бъде зададен броят на тестовите случай. 
Всеки тестови случай започва с ред, съдържащ броя на магазините N. Следва ред с 
N символа 'А' или 'В', определящи принадлежността на поредния магазин към 
съответното множество. Следва ред с броя на улиците M. На следващите M реда са 
зададени номерата на два магазина и времето за преминаване между тях по тази 
улица.

Output Format

За всеки тестови пример извеждайте на стандартния изход толкова реда, колкото са 
магазините от множеството A. На всеки от тези редове трябва да има по две числа – 
номер на връх от множеството A и минималното време, за придвижване от него до 
някой връх от множеството B или -1, ако такъв връх не съществува. Върховете 
трябва да са подредени в нарастващ ред на номерата им.

Sample Input 0

1
8
BABABAAB
10
1 6 10
2 3 21
2 4 2
2 6 7
4 7 7
4 5 18
6 8 3
6 7 6
8 7 10
7 3 11
Sample Output 0

2 10
4 12
6 3
7 9
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


const int INF = 1000000000;

struct Edge {
    int to, weight;
};

void dijkstra(int N, const vector<vector<Edge>>& graph, const vector<int>& startNodes, vector<int>& dist) {
    vector<bool> visited(N + 1, false);
    for (int node : startNodes) {
        dist[node] = 0;
    }

    for (int i = 1; i <= N; ++i) {
        int u = -1;
        for (int j = 1; j <= N; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) break; 

        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        string membership;
        cin >> membership;
        int M;
        cin >> M;

        vector<vector<Edge>> graph(N + 1);
        vector<int> dist(N + 1, INF);
        vector<int> startNodes;

        for (int i = 0; i < M; ++i) {
            int u, v, weight;
            cin >> u >> v >> weight;
            graph[u].push_back({v, weight});
            graph[v].push_back({u, weight});
        }

        for (int i = 0; i < N; ++i) {
            if (membership[i] == 'B') {
                startNodes.push_back(i + 1);
            }
        }

        dijkstra(N, graph, startNodes, dist);

        for (int i = 0; i < N; ++i) {
            if (membership[i] == 'A') {
                int node = i + 1;
                int minTime = dist[node];
                if (minTime == INF) {
                    cout << node << " -1" << endl;
                } else {
                    cout << node << " " << minTime << endl;
                }
            }
        }
    }
    return 0;
}
