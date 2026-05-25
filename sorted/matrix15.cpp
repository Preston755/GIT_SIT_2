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

void insertion_sort(vector<int>& v) {
    int n = (int)v.size();
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && v[j] < v[j - 1]) {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}

int main() {
    int n;
    vector<vector<int>> a = inFile(n);

    out << "INSERTION SORT: ";

    for (int k = 0; k <= 2 * (n - 1); k++) {
        vector<int> d;
        for (int i = 0; i < n; i++) {
            int j = k - i;
            if (j >= 0 && j < n)
                d.push_back(a[i][j]);
        }

        if ((int)d.size() <= 1) continue;

        insertion_sort(d);

        int idx = 0;
        for (int i = 0; i < n; i++) {
            int j = k - i;
            if (j >= 0 && j < n)
                a[i][j] = d[idx++];
        }
    }

    printMatrix(a, n);
    return 0;
}
