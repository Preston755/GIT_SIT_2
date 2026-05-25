#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    set<string> vopr;
    set<string> voskl;
    set<string> point;

    string razd = "!?.";

    string str;
    getline(cin, str);

    int pos = 0;
    int k = str.find_first_of(razd, pos);

    while (k != string::npos) {
        char tmp = str[k];
        string temp = str.substr(pos, k - pos);
        temp += ' ';

        int pos1 = 0;
        int kl = temp.find_first_of(" ", pos1);

        while (kl != string::npos) {
            string w = temp.substr(pos1, kl - pos1);

            if (!w.empty()) {
                for (char& c : w) {
                    c = tolower(c);
                }

                switch (tmp) {
                case '?':
                    vopr.insert(w);
                    break;
                case '!':
                    voskl.insert(w);
                    break;
                case '.':
                    point.insert(w);
                    break;
                }
            }

            pos1 = kl + 1;
            kl = temp.find_first_of(" ", pos1);
        }

        pos = k + 1;
        k = str.find_first_of(razd, pos);
    }

    vector<string> res;

    for (const string& w : point) {
        if (vopr.find(w) == vopr.end() && voskl.find(w) == voskl.end()) {
            res.push_back(w);
        }
    }

    for (const string& w : res) {
        cout << w << " ";
    }

    return 0;
}