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

bool operator<(people a, people b) {
    if (a.DateOfBirth.yy < b.DateOfBirth.yy) return true;
    if (a.DateOfBirth.yy == b.DateOfBirth.yy && a.Experience < b.Experience) return true;
    return false;
}

void comb_sort(vector<people>& x) {
    int n = (int)x.size();
    double f = 1.247;
    int g = (int)(n / f);

    while (g >= 1) {
        for (int j = 0; j + g < n; j++) {
            if (x[j + g] < x[j]) {
                swap(x[j], x[j + g]);
            }
        }
        if (g == 1) break;
        g = (int)(g / f);
        if (g < 1) g = 1;
    }
}

int main() {
    vector<people> x = inFile();
    out << "Отсортированно расческой ";
    comb_sort(x);
    for (int i = 0; i < (int)x.size(); i++)
        print(x[i]);
    return 0;
}
