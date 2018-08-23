#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, postl, postr, inl, inr;
int post[30];
int in[30];

struct node {
    int data;
    node* lchild;
    node* rchild;
};

node* create(int postl, int postr, int inl, int inr) {
    if (postl > postr) {
        return NULL;
    }
    node* root = new node;
    root->data = post[postr];
    int k;
    for (k = inl; k <= inr; k++) {
        if (in[k] == root->data) {
            break;
        }
    }
    int numLeft = k - inl;
    root->lchild = create(postl, postl + numLeft -1, inl, k-1);
    root->rchild = create(postl + numLeft, postr - 1, k + 1, inr);
    return root;
}

int num = 0;
void BFS(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        printf("%d", now->data);
        num++;
        if (num < n) {
            printf(" ");
        }
        if (now->lchild != NULL) { q.push(now->lchild); }
        if (now->rchild != NULL) { q.push(now->rchild); } 
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    postl = 0; postr = n-1;
    inl = 0; inr = n-1;
    node* root = create(postl, postr, inl, inr);
    BFS(root);
    return 0;
}