#include <iostream>
#include <climits>
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
    
    int min_val = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < min_val) {
                min_val = a[i][j];
            }
        }
    }
    
    int rows_left = 0;
    for (int i = 0; i < n; i++) {
        int has_min = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == min_val) {
                has_min = 1;
                break;
            }
        }
        if (has_min == 0) rows_left++;
    }
    
    int** new_a = new int*[rows_left];
    for (int i = 0; i < rows_left; i++)
        new_a[i] = new int[n];
    
    int new_i = 0;
    for (int i = 0; i < n; i++) {
        int has_min = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == min_val) {
                has_min = 1;
                break;
            }
        }
        
        if (has_min == 0) {
            for (int j = 0; j < n; j++)
                new_a[new_i][j] = a[i][j];
            new_i++;
        }
    }
    
    if (rows_left > 0) {
        cout << "Результат:" << endl;
        for (int i = 0; i < rows_left; i++) {
            for (int j = 0; j < n; j++)
                cout << new_a[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "Все строки удалены" << endl;
    }
    
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    
    for (int i = 0; i < rows_left; i++)
        delete[] new_a[i];
    delete[] new_a;
    
    return 0;
}