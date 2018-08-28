const int maxn = 110;
int heap[maxn], n = 10;

void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void downAdjust(int low, int high) {
    int i = low, j = 2 * i;
    while (j <= high) {
        if (j + 1 <= high && heap[j + 1] > heap[j]) {
            j = j + 1;
        }
        if (heap[j] > heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
}

void createHeap() {
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i);
    }
}

void deleteTop() {
    heap[1] = heap[n--];
    downAdjust(1, n);
}

void upAdjust(int low, int high) {
    int i = high, j = i / 2;
    while (j >= low) {
        if (heap[j] < heap[i]) {
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        } else {
            break;
        }
    }
}

void insert(int x) {
    heap[++n] = x;
    upAdjust(1, n);
}

void heapSort() {
    createHeap();
    for (int i = n; i >= 1; i--) {
        swap(heap[1], heap[i]);
        downAdjust(1, i - 1);
    }
}