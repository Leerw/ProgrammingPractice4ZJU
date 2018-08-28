#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 510;
int data[maxn];

struct node {
    int v, height;
    node *lchild, *rchild;
};

node* newNode(int v) {
    node* Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int getHeight(node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int search(node* root, int x) {
    if (root == NULL) {
        return 0;
    }
    if (x == root->v) {
        return 1;
    } else if (x < root->v) {
        search(root->lchild, x);
    } else {
        search(root->rchild, x);
    }
}

void L(node* &root) {
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root) {
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int v) {
    if (root == NULL) {
        root = newNode(v);
        return;
    }
    if (v < root->v) {
        insert(root->lchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) {
                R(root);
            } else if (getBalanceFactor(root->lchild) == -1) {
                L(root->lchild);
                R(root);
            }
        }
    } else {
        insert(root->rchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == -1) {
                L(root);
            } else if (getBalanceFactor(root->rchild) == 1) {
                R(root->rchild);
                L(root);
            }
        }
    }
}

node* create(int data[], int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

int main() {
    int n, k, q;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    node* root = create(data, n);
    for (int i = 0; i < k; i++) {
        scanf("%d", &q);
        if (search(root, q)) {
            printf("1");
        } else {
            printf("0");
        }
        if (i != k - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    return 0;
}