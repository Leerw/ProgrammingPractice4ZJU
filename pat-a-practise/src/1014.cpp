#include <cstdio>
#include <queue>

using namespace std;

#define INF 0x7fffffff

struct Window {
    int finishTime;
    queue<int> q;
};

struct Customer {
    int starttime;
    int processtime;
    int finishTime;
};

Customer customers[1005];
Window windows[25];

int main() {

    for (int i = 0; i < 25; i++) {
        windows[i].finishTime = 0;
    }

    int N, M, K, Q;
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    for (int i = 0; i < K; i++) {
        scanf("%d", &customers[i].processtime);
    }
    int i, j;
    for (i = 0, j = 0; i < N * M && i < K; i++) {
        customers[i].starttime = windows[j].finishTime;
        customers[i].finishTime = windows[j].finishTime + customers[i].processtime;
        windows[j].finishTime = windows[j].finishTime + customers[i].processtime;
        windows[j].q.push(i);
        j = (j + 1) % N;
    }
    for (; i < K; i++) {
        int time = INF;
        int pos = 0;
        for (j = 0; j < N; j++) {
            int front = windows[j].q.front();
            if (customers[front].finishTime < time) {
                time = customers[front].finishTime;
                pos = j;
            }
        }
        customers[i].starttime = windows[pos].finishTime;
        customers[i].finishTime = customers[i].starttime + customers[i].processtime;
        windows[pos].finishTime = windows[pos].finishTime + customers[i].processtime;
        windows[pos].q.push(i);
        windows[pos].q.pop();
    }
    while (Q--) {
        int index;
        scanf("%d", &index);
        index -= 1;
        if (customers[index].starttime >= 540) {
            printf("Sorry\n");
        } else {
            int hour = 8 + customers[index].finishTime / 60;
            int minute = customers[index].finishTime % 60;
            printf("%02d:%02d\n", hour, minute);
        }
    }
    return 0;
}
