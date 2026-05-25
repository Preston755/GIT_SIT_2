#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, start;

// граф: куда, вес
vector<vector<pair<int, int>>> Gr;

vector<int> dist;
vector<int> parent;
vector<int> used;

// создание неориентированного взвешенного графа
void create_graph() {
    cout << "Неориентированный взвешенный граф\n";
    cin >> N >> M;
    Gr.assign(N, vector<pair<int, int>>());
    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        Gr[x].push_back(make_pair(y, w));
        Gr[y].push_back(make_pair(x, w));
    }
    cout << "Стартовая вершина: ";
    cin >> start;
}

// дейкстра
void deikstr() {
    dist.assign(N, 1000000000);
    parent.assign(N, -1);
    used.assign(N, 0);
    dist[start] = 0;
    for (int i = 0; i < N; i++) {
        int v = -1;

        // ищем вершину с минимальным расстоянием
        for (int j = 0; j < N; j++) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
        if (dist[v] == 1000000000) {
            break;
        }
        used[v] = 1;
        for (int j = 0; j < Gr[v].size(); j++) {
            int to = Gr[v][j].first;
            int len = Gr[v][j].second;
            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                parent[to] = v;
            }
        }
    }
}

void print_path(int v) {
    if (v == -1) return;
    print_path(parent[v]);
    cout << v << " ";
}

void print_result() {
    cout << "\nРезультат:\n";
    for (int i = 0; i < N; i++) {
        cout << "Вершина " << i << ": ";
        if (dist[i] == 1000000000) {
            cout << "нет пути\n";
            continue;
        }
        cout << "длина = " << dist[i] << ", путь: ";
        print_path(i);
        cout << "\n";
    }
}

int main() {
    create_graph();
    deikstr();
    print_result();
    return 0;
}