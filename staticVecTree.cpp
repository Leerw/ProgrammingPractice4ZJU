struct node {
    typename data;
    vector<int> child;
} Node[maxn];

int index = 0;
int newNode(int v) {
    Node[index].data = v;
    Node[index].child.clear();
    return index++;
}

void preOrder(int root) {
    printf("%d ", Node[root].data);
    for (int i = 0; i < Node[root].size(); i++) {
        preOrder(Node[root].child[i]);
    }
}

void layerOrder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int front = q.front();
        printf("%d ", Node[front].data);
        q.pop();
        for (int i = 0; i < Node[root].child.size(); i++) {
            q.push(Node[fron].child[i]);
        }
    }
}

struct node {
    int layer;
    int data;
    vector<int> child;
}

void LayerOrder(int root)  {
    queue<int> q;
    q.push(root);
    Node[root].layer = 0;
    while (!q.empty()) {
        int front = q.front();
        printf("%d ", Node[front].data);
        q.pop();
        for (int i = 0; i < Node[front].child.size(); i++) {
            int child  Node[root].child[i];
            Node[child].layer = Node[root].layer + 1;
            q.push(child);
        }
    }
}

