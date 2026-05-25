#include <iostream>
#include <set>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    set<int> all;
    set<int> all23;

    int n;
    cout << "Введите количетсво чисел: ";
    cin >> n;

    cout << "Введите число: ";
    for (int i = 0; i < n; i++) {
        int n;
        cin >> n;

        int a = n;
        if (a == 0) {
            all.insert(0);
        }
        else {
            while (a > 0) {
                all.insert(a % 10);
                a = a / 10;
            }
        }

        if ((n >= 10 && n <= 99) || (n >= 100 && n <= 999)) {
            int a2 = n;
            if (a2 == 0) {
                all23.insert(0);
            }
            else {
                while (a2 > 0) {
                    all23.insert(a2 % 10);
                    a2 = a2 / 10;
                }
            }
        }
    }
    bool found = false;
    for (set<int>::iterator it = all.begin(); it != all.end(); it++) {
        if (all23.find(*it) == all23.end())
        {
            cout << *it << " ";
            found = true;
        }
    }

    if (!found) cout << "таких цифр нет";
    cout << endl;
}