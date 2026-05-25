#include <iostream>
using namespace std;

struct tree {
    int inf;
    tree *right;
    tree *left;
    tree *parent;
};

tree *node(int x) {
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree *&tr, int x) {
    tree *n = node(x);
    if (!tr) tr = n;
    else {
        tree *y = tr;
        while (y) {
            if (n->inf > y->inf) {
                if (y->right) y = y->right;
                else { n->parent = y; y->right = n; break; }
            } else if (n->inf < y->inf) {
                if (y->left) y = y->left;
                else { n->parent = y; y->left = n; break; }
            } else break; 
        }
    }
}

void sumEvenLeaves(tree *tr, int &sum, bool &found) {
    if (tr) {
        sumEvenLeaves(tr->left, sum, found);
        if (!tr->left && !tr->right) {
            if (tr->inf % 2 == 0) {
                sum += tr->inf;
                found = true;
            }
        }
        sumEvenLeaves(tr->right, sum, found);
    }
}

int main() {
    tree *root = NULL;
    int n, x;
    cout << "Введите количество элементов: ";
    cin >> n;
    cout << "Введите элементы: ";
    for (int i = 0; i < n; ++i) {
        cin >> x;
        insert(root, x);
    }

    int sum = 0;
    bool found = false;
    sumEvenLeaves(root, sum, found);

    if (!found)
        cout << "Чётных листьев нет." << endl;
    else
        cout << "Сумма чётных листьев: " << sum << endl;

    return 0;
}
