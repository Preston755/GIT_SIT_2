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

    int Y;
    cout << "Введите Y: ";
    cin >> Y;

    int* X = new int[n];
    cout << "Введите столбец X из " << n << " элементов: ";
    for (int i = 0; i < n; i++)
        cin >> X[i];

    int count_y = 0;
    for (int j = 0; j < n; j++) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == Y) {
                found = 1;
                break;
            }
        }
        if (found == 1) count_y++;
    }
    
    int new_m = n + count_y;
    int** new_a = new int*[n];
    for (int i = 0; i < n; i++)
        new_a[i] = new int[new_m];

    for (int i = 0; i < n; i++) {
        int new_j = 0;
        for (int j = 0; j < n; j++) {
            new_a[i][new_j] = a[i][j];
            new_j++;

            int found = 0;
            for (int k = 0; k < n; k++) {
                if (a[k][j] == Y) {
                    found = 1;
                    break;
                }
            }
            
            if (found == 1) {
                new_a[i][new_j] = X[i];
                new_j++;
            }
        }
    }

    cout << "Результат:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < new_m; j++)
            cout << new_a[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    
    for (int i = 0; i < n; i++)
        delete[] new_a[i];
    delete[] new_a;
    
    delete[] X;
    
    return 0;
}