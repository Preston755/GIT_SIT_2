#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* a = new int[n];
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    // Удаляем двузначные элементы
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 10 || a[i] > 99) { // Не двузначное
            a[index] = a[i];
            index++;
        }
    }

    cout << "Массив после удаления двузначных элементов:\n";
    for (int i = 0; i < index; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}