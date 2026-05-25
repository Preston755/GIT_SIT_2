#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int table_size = 13;

struct employee {
    string surname;
    string position;
    int birth_day;
    int birth_month;
    int birth_year;
    int experience;
    int salary;
};

struct node {
    employee data;
    node* next;
    node* prev;
};

node* hash_table[table_size];

int hash_function(int birth_month) {
    return birth_month % table_size;
}

void init_table() {
    for (int i = 0; i < table_size; i++) {
        hash_table[i] = nullptr;
    }
}

void insert_employee(employee worker) {
    int hash_index = hash_function(worker.birth_month);
    node* new_node = new node;
    new_node->data = worker;
    new_node->next = hash_table[hash_index];
    new_node->prev = nullptr;

    if (hash_table[hash_index] != nullptr) {
        hash_table[hash_index]->prev = new_node;
    }
    hash_table[hash_index] = new_node;
}

void print_table() {
    cout << "\nХЕШ-ТАБЛИЦА:\n";
    for (int i = 0; i < table_size; i++) {
        cout << i << ": ";
        node* current_node = hash_table[i];
        while (current_node != nullptr) {
            cout << current_node->data.surname;
            cout << "(";
            cout << current_node->data.birth_month;
            cout << ") -> ";
            current_node = current_node->next;
        }
        cout << "NULL\n";
    }
}

void search_employee(string surname) {
    bool is_found = false;
    for (int i = 0; i < table_size; i++) {
        node* current_node = hash_table[i];
        while (current_node != nullptr) {
            if (current_node->data.surname == surname) {
                cout << "\nСОТРУДНИК НАЙДЕН\n";
                cout << "Фамилия: ";
                cout << current_node->data.surname;
                cout << endl;

                cout << "Должность: ";
                cout << current_node->data.position;
                cout << endl;

                cout << "Дата рождения: ";
                cout << current_node->data.birth_day;
                cout << ".";
                cout << current_node->data.birth_month;
                cout << ".";
                cout << current_node->data.birth_year;
                cout << endl;

                cout << "Стаж: ";
                cout << current_node->data.experience;
                cout << endl;

                cout << "Зарплата: ";
                cout << current_node->data.salary;
                cout << endl;

                is_found = true;
            }
            current_node = current_node->next;
        }
    }
    if (!is_found) {
        cout << "\nСотрудник не найден\n";
    }
}

void delete_employee(string surname) {
    for (int i = 0; i < table_size; i++) {
        node* current_node = hash_table[i];
        while (current_node != nullptr) {
            if (current_node->data.surname == surname) {
                if (current_node->prev != nullptr) {
                    current_node->prev->next = current_node->next;
                }
                else {
                    hash_table[i] = current_node->next;
                }
                if (current_node->next != nullptr) {
                    current_node->next->prev = current_node->prev;
                }
                delete current_node;
                cout << "\nСотрудник удалён\n";
                return;
            }
            current_node = current_node->next;
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
        insert_employee(worker);
    }
    input_file.close();
    print_table();

    string surname;
    cout << "\nВведите фамилию для поиска: ";
    cin >> surname;

    search_employee(surname);
    cout << "\nВведите фамилию для удаления: ";
    cin >> surname;

    delete_employee(surname);
    print_table();
    return 0;
}