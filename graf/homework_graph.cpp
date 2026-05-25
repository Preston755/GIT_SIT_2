#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> Gr;
vector<int> used;
vector<int> path;

void create_graph() {
    cout << "Введите количество вершин и рёбер: ";
    cin >> N >> M;
    Gr = vector<vector<int>>(N);
    cout << "Введите рёбра (x y):\n";
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        Gr[x].push_back(y);
    }
    for (int i = 0; i < N; i++) {
        sort(Gr[i].begin(), Gr[i].end());
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
    }
}

void print_graph() {
    cout << "\nСписок смежности:\n";
    for (int i = 0; i < N; i++) {
        cout << i << ": ";
        for (unsigned int j = 0; j < Gr[i].size(); j++) {
            cout << Gr[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int x) {
    used[x] = 1;
    path.push_back(x);
    for (unsigned int i = 0; i < Gr[x].size(); i++) {
        if (!used[Gr[x][i]]) {
            dfs(Gr[x][i]);
        }
    }
}

void bfs(int x) {
    queue<int> q;
    used[x] = 1;
    path.push_back(x);
    q.push(x);
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        for (unsigned int i = 0; i < Gr[y].size(); i++) {
            if (!used[Gr[y][i]]) {
                used[Gr[y][i]] = 1;
                path.push_back(Gr[y][i]);
                q.push(Gr[y][i]);
            }
        }
    }
}

void task1() {
    cout << "\nЗадание 1: количество смежных вершин\n";
    cout << "Введите вершину: ";
    int v; cin >> v;
    cout << "Смежные вершины: ";
    for (unsigned int i = 0; i < Gr[v].size(); i++) {
        cout << Gr[v][i] << " ";
    }
    cout << "\nКоличество смежных вершин: " << Gr[v].size() << "\n";
}

void task2() {
    cout << "\nЗадание 2: удаление ребра A -> B\n";
    cout << "Введите вершины A и B: ";
    int a, b; cin >> a >> b;
    bool found = false;
    for (unsigned int i = 0; i < Gr[a].size(); i++) {
        if (Gr[a][i] == b) {
            Gr[a].erase(Gr[a].begin() + i);
            found = true;
            break;
        }
    }
    if (found) {cout << "Ребро " << a << " -> " << b << " удалено\n";}
    else {cout << "Такого ребра нет\n";}
    print_graph();
}

void task3() {
    cout << "\nЗадание 3: полустепень исхода каждой вершины\n";
    for (int i = 0; i < N; i++) {
        cout << "Вершина " << i << ": " << Gr[i].size() << "\n";
    }
}

// Задание 4
// вывести все вершины, недостижимые из данной
// запускаем DFS из данной вершины и смотрим какие не посещены
void task4() {
    cout << "\nЗадание 4: вершины, недостижимые из данной\n";
    cout << "Введите вершину: ";
    int v; cin >> v;

    used = vector<int>(N, 0);
    path = vector<int>();

    dfs(v);
    cout << "Недостижимые вершины из " << v << ": ";
    bool any = false;
    for (int i = 0; i < N; i++) {
        if (!used[i]) {cout << i << " "; any = true;}
    }
    if (!any) {cout << "все достижимы";}
    cout << "\n";
}

// Задание 5
// вывести все вершины, из которых существует путь во все остальные
// запускаем BFS из каждой вершины и проверяем достигает ли она всех остальных
void task5() {
    cout << "\nЗадание 5: вершины с путём во все остальные\n";
    bool any = false;
    for (int v = 0; v < N; v++) {
        used = vector<int>(N, 0);
        path = vector<int>();

        bfs(v);
        bool reaches_all = true;    // флаг достигает ли вершина всех остальных
        for (int i = 0; i < N; i++) {
            if (!used[i]) {reaches_all = false; break;}
        }
        if (reaches_all) {cout << v << " "; any = true;}
    }
    if (!any) {cout << "таких вершин нет";}
    cout << "\n";
}

int main() {
    create_graph();
    print_graph();

    task1();
    task2();
    task3();
    task4();
    task5();

    return 0;
}