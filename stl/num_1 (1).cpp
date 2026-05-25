#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    vector<int> vec;
    int v;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> v;
        vec.push_back(v);
    }

    cout << "Исходный вектор: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;

    int X;
    cout << "X = ";
    cin >> X;

    int max_v = *max_element(vec.begin(), vec.end());
    cout << "Максимальный элемент: " << max_v << endl;

    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        if (*it % X == 0) {
            *it = max_v;
        }
    }

    cout << "Результат: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;

    system("pause");
    return 0;
}