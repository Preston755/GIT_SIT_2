#include <iostream>
using namespace std;

int** create(int n) {
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    return a;
}

void print(int** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int summa(int** a, int n) {
    int k = 0, sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((j <= i && j <= n - 1 - i) || (j >= i && j >= n - 1 - i))
                if (a[i][j] % 2 == 0) {
                    sum += a[i][j];
                    k++;
                }
    if (k == 0) return -1; // индикатор отсутствия чётных элементов
    return sum;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "n = "; cin >> n;
    int** a = create(n);
    cout << "Массив:\n";
    print(a, n);
    int sum = summa(a, n);
    if (sum != -1)
        cout << "Сумма чётных элементов в заштрихованной области: " << sum << endl;
    else
        cout << "Чётных элементов в заштрихованной области нет.\n";
    return 0;
}