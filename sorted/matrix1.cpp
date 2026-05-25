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

void quick_sort(vector<int>& v, int left, int right) {
    int i = left;
    int j = right;
    int p = v[(left + right) / 2];

    while (i <= j) {
        while (v[i] < p) i++;
        while (v[j] > p) j--;
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    if (left < j) quick_sort(v, left, j);
    if (i < right) quick_sort(v, i, right);
}

int main() {
    int n;
    vector<vector<int>> a = inFile(n);

    out << "QUICK SORT: ";

    for (int j = 0; j < n; j++) {
        vector<int> col(n);
        for (int i = 0; i < n; i++)
            col[i] = a[i][j];

        quick_sort(col, 0, n - 1);

        for (int i = 0; i < n; i++)
            a[i][j] = col[i];
    }

    printMatrix(a, n);
    return 0;
}
