#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date {
    int dd, mm, yy;
};

struct people {
    string Surname;
    string Position;
    date DateOfBirth;
    int Experience;
    int Salary;
};

date Str_to_Date(string str) {
    date x;
    x.dd = stoi(str.substr(0, 2));
    x.mm = stoi(str.substr(3, 2));
    x.yy = stoi(str.substr(6, 4));
    return x;
}

vector<people> inFile() {
    vector<people> x;
    people temp;
    while (in >> temp.Surname >> temp.Position) {
        string tmp;
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.Experience;
        in >> temp.Salary;
        x.push_back(temp);
    }
    return x;
}

void print(people x) {
    out << setw(12) << left << x.Surname;
    out << setw(12) << left << x.Position;

    if (x.DateOfBirth.dd < 10) out << "0";
    out << x.DateOfBirth.dd << ".";

    if (x.DateOfBirth.mm < 10) out << "0";
    out << x.DateOfBirth.mm << ".";

    out << x.DateOfBirth.yy << "   ";

    out << setw(6) << left << x.Experience;
    out << setw(8) << left << x.Salary << endl;
}

void counting_sort(vector<people>& x) {
    int minYear = x[0].DateOfBirth.yy;
    int maxYear = x[0].DateOfBirth.yy;
    for (int i = 1; i < (int)x.size(); i++) {
        if (x[i].DateOfBirth.yy < minYear) minYear = x[i].DateOfBirth.yy;
        if (x[i].DateOfBirth.yy > maxYear) maxYear = x[i].DateOfBirth.yy;
    }

    int k = maxYear - minYear + 1;

    vector<vector<people>> g(k);

    for (int i = 0; i < (int)x.size(); i++) {
        int idx = x[i].DateOfBirth.yy - minYear;
        g[idx].push_back(x[i]);
    }

    int pos = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (int)g[i].size(); j++) {
            x[pos++] = g[i][j];
        }
    }
}

int main() {
    vector<people> x = inFile();
    out << "Отсортированно подсчётом: ";
    counting_sort(x);
    for (int i = 0; i < (int)x.size(); i++)
        print(x[i]);
    return 0;
}
