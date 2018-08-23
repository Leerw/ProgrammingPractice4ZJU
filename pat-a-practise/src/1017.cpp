#include <algorithm>
#include <cstdio>
#include <queue>
#include <numeric>
using namespace std;

struct Customer {
    int arriveT;
    int processT;
    int waitT;
    Customer (int h, int m, int s, int t) : processT(t*60) { arriveT = h * 3600 + m * 60 + s;}
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
    int openT = 8 * 3600;
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
        return a.arriveT < b.arriveT;
    });
    for (auto customer : customers) {
        waitline.push(customer);
    }
    while (!waitline.empty()) {
        auto windex = min_element(windows.begin(), windows.end(), [](Window a, Window b) {
            return a.endT < b.endT;
        });
        Customer tmp = waitline.front();
        waitline.pop();
        windex->startT = windex->endT;
        if (tmp.arriveT > windex->startT) {
            windex->startT = tmp.arriveT;
        }
        windex->processT = tmp.processT;
        windex->endT = windex->startT + windex->processT;
        tmp.waitT = windex->startT - tmp.arriveT;
        waitT.push_back(tmp.waitT);
    }
    double averageWaitT = accumulate(waitT.begin(), waitT.end(), 0) / 60.0 / waitT.size();
    printf("%.1f\n", averageWaitT);
    return 0;
}