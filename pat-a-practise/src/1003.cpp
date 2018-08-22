
// The MIT License (MIT)

// Copyright (c) 2018 Lee.rw

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

/* PAT Advanced 1003 Emergency */


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXV = 510;
const int INF = 1000000000;

int n, m, st, ed, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], w[MAXV], num[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    fill(vis, vis + MAXV ,false);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                } else if (d[u] + G[u][v] == d[v]) {
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    int u,v;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}