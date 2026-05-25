#include <iostream>
#include <list>
#include <numeric>
#include <functional>
using namespace std;

int main() {
    int n;
    cout << "Введите размер списков: ";
    cin >> n;

    list<int> st1, st2;
    int x;

    cout << "Введите элементы первого списка:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "] = ";
        cin >> x;
        st1.push_back(x);
    }

    cout << "Введите элементы второго списка:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "b[" << i << "] = ";
        cin >> x;
        st2.push_back(x);
    }

    int count = 0;
    list<int>::iterator it1 = st1.begin();
    list<int>::iterator it2 = st2.begin();
    for (; it1 != st1.end(); ++it1, ++it2) {
        if (*it1 == *it2) count++;
    }

    cout << "Количество попарно совпадающих элементов: " << count << endl;

    return 0;
}