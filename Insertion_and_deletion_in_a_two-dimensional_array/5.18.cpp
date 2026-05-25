#include <iostream>
#include <limits>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите размер массива n: ";
    cin >> n;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    int** a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
    
    int X;
    cout << "Введите X: ";
    cin >> X;
    
    int cols_left = 0;
    for (int j = 0; j < n; j++) {
        int has_multiple = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] % X == 0) {
                has_multiple = 1;
                break;
            }
        }
        if (has_multiple == 0) cols_left++;
    }
    
    int** new_a = new int*[n];
    for (int i = 0; i < n; i++)
        new_a[i] = new int[cols_left];
    
    for (int i = 0; i < n; i++) {
        int new_j = 0;
        for (int j = 0; j < n; j++) {
            int has_multiple = 0;
            for (int k = 0; k < n; k++) {
                if (a[k][j] % X == 0) {
                    has_multiple = 1;
                    break;
                }
            }
            
            if (has_multiple == 0) {
                new_a[i][new_j] = a[i][j];
                new_j++;
            }
        }
    }
    
    if (cols_left > 0) {
        cout << "Результат:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < cols_left; j++)
                cout << new_a[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "Все столбцы удалены" << endl;
    }
    
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    
    for (int i = 0; i < n; i++)
        delete[] new_a[i];
    delete[] new_a;
    
    return 0;
}