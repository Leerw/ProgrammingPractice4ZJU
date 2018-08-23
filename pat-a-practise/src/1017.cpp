#include <algorithm>
#include <cstdio>
#include <queue>
#include <numeric>
using namespace std;

struct Customer {
    int arriveH, arriveM, arriveS;
    int arriveT;
    int processT;
    int waitT;
    Customer (int h, int m, int s, int t) : arriveH(h), arriveM(m), arriveS(s) { arriveT = h * 3600 + m * 60 + s;}
};

struct Window {
    int startT = 8 * 3600;
    int processT = 0;
    int endT = startT;
};

vector<int> waitT;

int main(int argc, char const* argv[]) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<Customer> customers;
    queue<Customer> waitline;
    vector<Window> windows(k);
    int h, m, s, t;
    int closeT = 17 * 3600;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d", &h, &m, &s, &t);
        if (h * 3600 + m * 60 + s > closeT) {
            continue;
        }
        Customer customer(h, m, s, t);
        customers.push_back(customer);
    }
    std::sort(customers.begin(), customers.end(), [](Customer a, Customer b) {
        return a.arriveH*3600 + a.arriveM*60 + a.arriveS < b.arriveH*3600 + b.arriveM*60 + b.arriveS;
    });
    for (auto customer : customers) {
        waitline.push(customer);
    }
    while (!waitline.empty()) {
        for (int windex = 0; windex < k; windex = (windex + 1) % k) {
            Customer tmp = waitline.front();
            if (windows[windex].endT < tmp.arriveT) {
                windows[windex].startT = tmp.arriveT;
                windows[windex].processT = tmp.processT;
                windows[windex].endT = windows[windex].startT + windows[windex].processT;
                tmp.waitT = windows[windex].endT - tmp.arriveT;
                waitT.push_back(tmp.waitT);
            }
        }
    }
    double averageWaitT = accumulate(waitT.begin(), waitT.end(), 0) / waitT.size();
    printf("%.1f\n", averageWaitT);
    return 0;
}
