#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

vector<vector<int>> inFile(int& n) {
    in >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            in >> a[i][j];
    return a;
}

void printMatrix(const vector<vector<int>>& a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            out << setw(6) << a[i][j];
        out << endl;
    }
}

void merge(vector<int>& v, int l, int m, int r, bool ascending) {
    int size = r - l + 1;
    vector<int> u(size);
    int c = 0;
    int i = l, j = m + 1;

    while (c < size) {
        if (i > m) {
            u[c++] = v[j++];
        } else if (j > r) {
            u[c++] = v[i++];
        } else if (ascending ? (v[i] <= v[j]) : (v[i] >= v[j])) {
            u[c++] = v[i++];
        } else {
            u[c++] = v[j++];
        }
    }

    for (int k = 0; k < size; k++)
        v[l + k] = u[k];
}

void merge_sort(vector<int>& v, int l, int r, bool ascending) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(v, l, m, ascending);
    merge_sort(v, m + 1, r, ascending);
    merge(v, l, m, r, ascending);
}

int main() {
    int n;
    vector<vector<int>> a = inFile(n);

    out << "MERGE SORT: ";

    for (int i = 0; i < n; i++) {
        bool descending = ((i + 1) % 3 == 0);
        merge_sort(a[i], 0, n - 1, !descending);
    }

    printMatrix(a, n);
    return 0;
}
