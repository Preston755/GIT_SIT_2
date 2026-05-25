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

tree *find(tree *tr, int x) {
    if (!tr || x == tr->inf) return tr;
    if (x < tr->inf) return find(tr->left, x);
    else             return find(tr->right, x);
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

    int X;
    cout << "Введите значение узла X: ";
    cin >> X;

    tree *nodeX = find(root, X);
    if (!nodeX) {
        cout << "Узел " << X << " не найден в дереве." << endl;
    } else {
        cout << "Внуки узла " << X << ": ";
        bool hasGrandchildren = false;

        if (nodeX->left) {
            if (nodeX->left->left) {
                cout << nodeX->left->left->inf << " ";
                hasGrandchildren = true;
            }
            if (nodeX->left->right) {
                cout << nodeX->left->right->inf << " ";
                hasGrandchildren = true;
            }
        }
        if (nodeX->right) {
            if (nodeX->right->left) {
                cout << nodeX->right->left->inf << " ";
                hasGrandchildren = true;
            }
            if (nodeX->right->right) {
                cout << nodeX->right->right->inf << " ";
                hasGrandchildren = true;
            }
        }

        if (!hasGrandchildren) cout << "нет";
        cout << endl;
    }
    return 0;
}
