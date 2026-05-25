#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "n = "; cin >> n;
    int* a = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;
    int A, B;
    cout << "A = "; cin >> A;
    cout << "B = "; cin >> B;
    if (A > B) swap(A, B);
    int k = 0, sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 5 == 0 && (a[i] < A || a[i] > B)) {
            k++;
            sum += a[i];
        }
    if (k == 0)
        cout << "Элементов, кратных 5 и не входящих в [" << A << ", " << B << "], нет.\n";
    else
        cout << "Сумма элементов, кратных 5 и не входящих в интервал: " << sum << endl;
    delete[] a;
    return 0;
}