#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

// неориентированный граф (Эйлер)
vector<vector<int>> Gr_undir;
vector<int> deg;

// ориентированный граф (топосорт)
vector<vector<int>> Gr_dir;
vector<int> used;
vector<int> topo;
bool has_cycle = false;

// неориентированный граф (для Эйлера)
void create_undirected() {
    cout << "НЕОРИЕНТИРОВАННЫЙ граф (для Эйлера)\n";
    cin >> N >> M;
    Gr_undir.assign(N, vector<int>());
    deg.assign(N, 0);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        Gr_undir[x].push_back(y);
        Gr_undir[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
}

void dfs_check(int v, vector<int>& vis) {
    vis[v] = 1;
    for (int i = 0; i < Gr_undir[v].size(); i++) {
        int to = Gr_undir[v][i];
        if (!vis[to]) {
            dfs_check(to, vis);
        }
    }
}

void find_path(int v, vector<vector<int>>& temp, vector<int>& path) {
    for (int i = 0; i < temp[v].size(); i++) {
        int to = temp[v][i];
        if (to != -1) {
            temp[v][i] = -1;
            for (int j = 0; j < temp[to].size(); j++) {
                if (temp[to][j] == v) {
                    temp[to][j] = -1;
                    break;
                }
            }
            find_path(to, temp, path);
        }
    }
    path.push_back(v);
}

void euler() {
    int odd = 0;
    for (int i = 0; i < N; i++) {
        if (deg[i] % 2 != 0) {
            odd++;
        }
    }
    vector<int> vis(N, 0);
    int start_check = -1;
    for (int i = 0; i < N; i++) {
        if (deg[i] > 0) {
            start_check = i;
            break;
        }
    }
    if (start_check != -1) {
        dfs_check(start_check, vis);
        for (int i = 0; i < N; i++) {
            if (deg[i] > 0 && vis[i] == 0) {
                cout << "Граф несвязный\n";
                return;
            }
        }
    }
    if (odd != 0 && odd != 2) {
        cout << "Эйлеров путь не существует\n";
        return;
    }
    int start = -1;
    for (int i = 0; i < N; i++) {
        if (deg[i] % 2 != 0) {
            start = i;
            break;
        }
    }
    if (start == -1) {
        for (int i = 0; i < N; i++) {
            if (deg[i] > 0) {
                start = i;
                break;
            }
        }
    }
    if (odd == 0) cout << "Эйлеров цикл:\n";
    else cout << "Эйлеров путь:\n";
    vector<vector<int>> temp = Gr_undir;
    vector<int> path;
    find_path(start, temp, path);
    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << "\n";
}

// ориентированный граф (для топосорта)

void create_directed() {
    cout << "\nОРИЕНТИРОВАННЫЙ граф (для топосорта)\n";
    cin >> N >> M;
    Gr_dir.assign(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        Gr_dir[x].push_back(y);
    }
}

void dfs_topo(int v) {
    used[v] = 1;
    for (int i = 0; i < Gr_dir[v].size(); i++) {
        int to = Gr_dir[v][i];
        if (used[to] == 0) {
            dfs_topo(to);
        }
        else if (used[to] == 1) {
            has_cycle = true;
        }
    }
    used[v] = 2;
    topo.push_back(v);
}

void topological_sort() {
    used.assign(N, 0);
    topo.clear();
    has_cycle = false;
    for (int i = 0; i < N; i++) {
        if (used[i] == 0) {
            dfs_topo(i);
        }
    }
    if (has_cycle) {
        cout << "Топосорт невозможен (есть цикл)\n";
        return;
    }
    reverse(topo.begin(), topo.end());

    cout << "Топологический порядок:\n";
    for (int i = 0; i < topo.size(); i++) {
        cout << topo[i] << " ";
    }
    cout << "\n";
}

int main() {

    create_undirected();
    euler();

    create_directed();
    topological_sort();

    return 0;
}