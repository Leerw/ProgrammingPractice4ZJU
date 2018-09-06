void search(node* root, int x) {
    if (root == NULL) {
        printf("search failed\n");
        return;
    }
    if (x == root->data) {
        printf("%d\n", root->data);
    } else if (x < root->data) {
        search(root->lchild, data);
    } else {
        search(root->rchild, data);
    }
}

void insert(node* &root, int x) {
    if (root == NULL) {
        root = new Node(x);
        return;
    }
    if (x == root->data) {
        return;
    } else if (x < root->data) {
        insert(root->lchild, data);
    } else {
        insert(root->rchild, data);
    }
}

node* create(int data[], int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

node* findMax(node* root) {
    while (root->rchild != NULL) {
        root = root->rchild;
    }
    return root;
}

node* findMin(node* root) {
    while (root->lchild != NULL) {
        root = root->lchild;
    }
    return root;
}

void deleteNode(node* &root, int x) {
    if (root == NULL) return;
    if (root->data == x) {
        if (root->lchild == NULL && root->rchild == NULL) {
            root = NULL;
        } else if (root->lchild != NULL) {
            node* pre = findMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild, pre->data);
        } else {
            node* next = findMin(root->rchild);
            root->data = next->data;
            deleteNode(root->rchild, next->data);
        }
    } else if (root->data > x) {
        deleteNode(root->lchild, x);
    } else {
        deleteNode(root->rchild, x);
    }
}

