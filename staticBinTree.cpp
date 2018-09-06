struct node {
    typedef data;
    int lchild;
    int rchild;
} Node[maxn];

int index = 0;
int newNode(int v) {
    Node[index].data = x;
    Node[index].lchild = -1;
    Node[index].rchild = -1;
    return index++;
}

void search(int root, int x, int newdata) {
    if (root == -1) return;
    if (Node[root].data == x) Node[root].data = newdata;
    search(Node[root].lchild, x, newdata);
    search(Node[root].rchild, x, newdata);
}

void insert(int &root, int x) {
    if (root == -1) {
        root = newNode(x);
        return;
    }
    if (xxx) {
        insert(Node[root].lchild, x);
    } else {
        insert(Node[root].rchild, x);
    }
}

int Create(int data[], int n) {
    int root = -1;
    for (int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

void preOrder(int root) {
    if (root == -1) {
        return;
    }
    printf("%d\n", Node[root].data);
    preOrder(Node[root].lchild);
    preOrder(Node[root].rchild);
}

void inOrder(int root) {
    if (root == -1) {
        return;
    }
    inOrder(Node[root].lchild);
    printf("%d\n", Node[root].data);
    inOrder(Node[root].rchild);
}

void postOrder(int root) {
    if (root == -1) {
        return;
    }
    postOrder(Node[root].lchild);
    postOrder(Node[root].rchild);
    printf("%d\n", Node[root].data);
}

void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        printf("%d ", Node[now].data);
        if (Node[now].lchild != -1) q.push(Node[root].lchild);
        if (Node[now].rchild != -1) q.push(Node[root].rchild);
    }
}
