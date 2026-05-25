#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int k;
    cin >> k;

    map<string, int> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        bool f = true;
        for (string::iterator it = s.begin(); it != s.end(); it++) {
            if (*it < '0' || *it > '9') {
                f = false;
                break;
            }
        }

        if (!f) {
            m[s] = m[s] + 1;
        }
    }

    bool found = false;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        if ((*it).second == k) {
            cout << (*it).first << " ";
            found = true;
        }
    }

    if (!found) {
        cout << endl;
    }

    return 0;
}