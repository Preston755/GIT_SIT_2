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
    
    // Поиск первого минимального четного в заштрихованной области (левый треугольник)
    int minEven = INT_MAX;
    int minI = -1, minJ = -1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i && j <= n - 1 - i; j++) {
            if (a[i][j] % 2 == 0 && a[i][j] < minEven) {
                minEven = a[i][j];
                minI = i;
                minJ = j;
            }
        }
    }
    
    // Поиск первого максимального нечетного в незаштрихованной области (правый треугольник)
    int maxOdd = INT_MIN;
    int maxI = -1, maxJ = -1;
    
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i && j >= n - 1 - i; j--) {
            if (j < 0 || j >= n) continue;
            if (a[i][j] % 2 != 0 && a[i][j] > maxOdd) {
                maxOdd = a[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }
    
    // Выполняем замену, если нашли оба элемента
    if (minI != -1 && maxI != -1) {
        a[minI][minJ] = maxOdd;
        cout << "Элемент a[" << minI << "][" << minJ << "] заменен на " << maxOdd << endl;
    } else {
        if (minI == -1) cout << "Четных элементов в заштрихованной области нет.\n";
        if (maxI == -1) cout << "Нечетных элементов в незаштрихованной области нет.\n";
    }
    
    cout << "Массив после замены:\n";
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