#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

const int table_size = 41;

struct employee {
    string surname;
    string position;
    int birth_day;
    int birth_month;
    int birth_year;
    int experience;
    int salary;
    bool is_empty = true;
};

employee hash_table[table_size];

int multiplication_hash(int salary) {
    double A = 0.618033;
    double value = salary * A;
    double fractional_part = value - floor(value);
    return int(table_size * fractional_part);
}

void init_table() {
    for (int i = 0; i < table_size; i++) {
        hash_table[i].is_empty = true;
    }
}

void insert_employee(employee worker) {
    int first_hash = multiplication_hash(worker.salary);
    int c1 = 1;
    int c2 = 3;
    for (int i = 0; i < table_size; i++) {
        int hash_index = (first_hash + c1 * i + c2 * i * i) % table_size;
        if (hash_table[hash_index].is_empty) {
            hash_table[hash_index] = worker;
            hash_table[hash_index].is_empty = false;
            return;
        }
    }
    cout << "Переполнение хеш-таблицы\n";
}

void print_table() {
    cout << "\nХЕШ-ТАБЛИЦА:\n";
    for (int i = 0; i < table_size; i++) {
        cout << i << ": ";
        if (hash_table[i].is_empty) {
            cout << "ПУСТО";
        }
        else {
            cout << hash_table[i].surname;
            cout << " ";
            cout << hash_table[i].salary;
        }
        cout << endl;
    }
}

void search_employee(string surname) {
    for (int i = 0; i < table_size; i++) {
        if (!hash_table[i].is_empty &&
            hash_table[i].surname == surname) {
            cout << "\nСОТРУДНИК НАЙДЕН\n";

            cout << "Фамилия: ";
            cout << hash_table[i].surname;
            cout << endl;
            cout << "Должность: ";
            cout << hash_table[i].position;
            cout << endl;

            cout << "Дата рождения: ";
            cout << hash_table[i].birth_day;
            cout << ".";
            cout << hash_table[i].birth_month;
            cout << ".";
            cout << hash_table[i].birth_year;
            cout << endl;

            cout << "Стаж: ";
            cout << hash_table[i].experience;
            cout << endl;

            cout << "Зарплата: ";
            cout << hash_table[i].salary;
            cout << endl;

            return;
        }
    }
    cout << "\nСотрудник не найден\n";
}

int main() {
    ifstream input_file("workers.txt");

    if (!input_file) {
        cout << "Ошибка открытия файла\n";
        return 0;
    }
    init_table();

    employee worker;
    while (input_file >> worker.surname >> worker.position) {
        char dot;
        input_file >> worker.birth_day;
        input_file >> dot;
        input_file >> worker.birth_month;
        input_file >> dot;
        input_file >> worker.birth_year;

        input_file >> worker.experience;
        input_file >> worker.salary;

        worker.is_empty = false;
        insert_employee(worker);
    }
    input_file.close();
    print_table();

    string surname;
    cout << "\nВведите фамилию для поиска: ";
    cin >> surname;

    search_employee(surname);

    return 0;
}