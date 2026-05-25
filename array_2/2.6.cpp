#include <iostream>
#include <climits>
#include <limits> 
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите размер массива (n x n): ";
    cin >> n;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    
    cout << "Исходный массив:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    // Поиск первого минимального и первого максимального элемента
    int minVal = INT_MAX, maxVal = INT_MIN;
    int minRow = 0, maxRow = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < minVal) {
                minVal = a[i][j];
                minRow = i;
            }
            if (a[i][j] > maxVal) {
                maxVal = a[i][j];
                maxRow = i;
            }
        }
    }
    
    // Меняем местами строки
    if (minRow != maxRow) {
        for (int j = 0; j < n; j++) {
            swap(a[minRow][j], a[maxRow][j]);
        }
        cout << "Строки " << minRow + 1 << " и " << maxRow + 1 << " поменяны местами.\n";
    } else {
        cout << "Минимальный и максимальный элементы находятся в одной строке.\n";
    }
    
    cout << "Массив после обмена строк:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    
    return 0;
}