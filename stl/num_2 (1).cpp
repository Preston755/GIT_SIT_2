#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    vector<int> vec;
    int val;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> val;
        vec.push_back(val);
    }

    cout << "Исходный вектор: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "В обратном порядке: ";
    for (int i = vec.size() - 1; i >= 0; i--)
        cout << vec[i] << " ";
    cout << endl;

    int a, b, X;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "X = ";
    cin >> X;

    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        if (*it >= a && *it <= b) {
            *it = X;
        }
    }

    cout << "После замены: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;

    sort(vec.begin(), vec.end());

    cout << "После сортировки: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;

    int new_elem;
    cout << "Новый элемент для вставки = ";
    cin >> new_elem;

    vector<int>::iterator pos = vec.begin();
    while (pos != vec.end() && *pos < new_elem) {
        ++pos;
    }
    vec.insert(pos, new_elem);

    cout << "После вставки: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;

    vector<int>::iterator it1 = unique(vec.begin(), vec.end());
    vec.erase(it1, vec.end());

    cout << "После удаления дубликатов: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;

    system("pause");
    return 0;
}