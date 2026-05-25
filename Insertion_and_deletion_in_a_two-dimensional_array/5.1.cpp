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
    
    int* X = new int[n];
    cout << "Введите строку X из " << n << " элементов: ";
    for (int i = 0; i < n; i++)
        cin >> X[i];
    
    int count_pos = 0;
    for (int i = 0; i < n; i++) {
        int positive = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] <= 0) {
                positive = 0;
                break;
            }
        }
        if (positive == 1) count_pos++;
    }
    
    int new_n = n + count_pos;
    int** new_a = new int*[new_n];
    for (int i = 0; i < new_n; i++)
        new_a[i] = new int[n];
    
    int new_i = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            new_a[new_i][j] = a[i][j];
        new_i++;

        int positive = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] <= 0) {
                positive = 0;
                break;
            }
        }
        
        if (positive == 1) {
            for (int j = 0; j < n; j++)
                new_a[new_i][j] = X[j];
            new_i++;
        }
    }

    cout << "Результат:" << endl;
    for (int i = 0; i < new_n; i++) {
        for (int j = 0; j < n; j++)
            cout << new_a[i][j] << " ";
        cout << endl;
    }
    
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    
    for (int i = 0; i < new_n; i++)
        delete[] new_a[i];
    delete[] new_a;
    
    delete[] X;
    
    return 0;
}