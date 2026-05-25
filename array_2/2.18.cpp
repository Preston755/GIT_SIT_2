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
    
    
    int num = 0;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { 
            int start_value = (i + 1) * n - 1; 
            for (int j = 0; j < n; j++) {
                a[i][j] = start_value - j;
            }
        } else {  
            int start_value = i * n; 
            for (int j = 0; j < n; j++) {
                a[i][j] = start_value + j;
            }
        }
    }
    
    cout << "Заполненный массив:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Все числа от 0 до " << (n*n - 1) << " присутствуют.\n";
    
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    
    return 0;
}