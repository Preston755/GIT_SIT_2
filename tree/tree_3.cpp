#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tree {
    int inf;
    tree *right, *left, *parent;
};

tree *node(int x) {
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = n->parent = NULL;
    return n;
}

void insert(tree *&tr, int x) {
    tree *n = node(x), *y = tr;
    if (!tr) { tr = n; return; }
    while (y) {
        if      (x > y->inf && y->right) y = y->right;
        else if (x > y->inf) { n->parent = y; y->right = n; return; }
        else if (x < y->inf && y->left)  y = y->left;
        else if (x < y->inf) { n->parent = y; y->left  = n; return; }
        else return;
    }
}

tree *Min(tree *tr) {
    return tr->left ? Min(tr->left) : tr;
}

void Delete(tree *&tr, tree *v) {
    if (v->left && v->right) {
        tree *succ = Min(v->right);
        v->inf = succ->inf;
        v = succ; 
    }
    tree *child = v->left ? v->left : v->right;
    tree *p = v->parent;
    if (child) child->parent = p;
    if (!p)                  tr       = child;
    else if (p->left == v)   p->left  = child;
    else                     p->right = child;
    delete v;
}

void collectLevel(tree *tr, int cur, int target, vector<tree*> &nodes) {
    if (!tr) return;
    if (cur == target) { nodes.push_back(tr); return; }
    collectLevel(tr->left,  cur + 1, target, nodes);
    collectLevel(tr->right, cur + 1, target, nodes);
}

void inorder(tree *tr) {
    if (tr) { inorder(tr->left); cout << tr->inf << " "; inorder(tr->right); }
}

int main() {
    tree *root = NULL;
    int n, x;
    cout << "Введите количество элементов: ";
    cin >> n;
    cout << "Введите элементы: ";
    for (int i = 0; i < n; ++i) { cin >> x; insert(root, x); }

    int k;
    cout << "Введите уровень K (>= 2): ";
    cin >> k;
    if (k < 2) { cout << "Ошибка: K должно быть >= 2." << endl; return 0; }

    vector<tree*> nodes;
    collectLevel(root, 0, k, nodes);

    if (nodes.empty()) { cout << "На уровне " << k << " нет узлов." << endl; return 0; }

    sort(nodes.begin(), nodes.end(), [](tree *a, tree *b){ return a->inf < b->inf; });

    tree *mid = nodes[(nodes.size() - 1) / 2];

    cout << "Узлы уровня " << k << " (по возрастанию): ";
    for (tree *t : nodes) cout << t->inf << " ";
    cout << "\nУдаляем среднюю вершину: " << mid->inf << endl;

    Delete(root, mid);

    cout << "Дерево после удаления (симметричный обход): ";
    inorder(root);
    cout << endl;
    return 0;
}
