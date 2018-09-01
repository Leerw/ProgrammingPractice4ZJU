#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int INF = 0x3fffffff;
double cmax, d, davg, n, pi, di;
struct Station {
    double price, dis;
}tempstation;
vector<Station> stations;
int main() {
    scanf("%lf %lf %lf %lf", &cmax, &d, &davg, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &tempstation.price, &tempstation.dis);
        stations.push_back(tempstation);
    }
    tempstation.dis = d; tempstation.price = 0;
    stations.push_back(tempstation);
    sort(stations.begin(), stations.end(), [](const Station a, const Station b) {
        return a.dis < b.dis;
    });
    if (stations.empty() || stations[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    double nowdis = 0, maxdis = 0, nowprice = stations[0].price, totalprice = 0.0, nowgas = 0.0;
    int i = 0;
    for (i = 0; i < n; ) {
        if (stations[i + 1].dis - stations[i].dis > cmax * davg) {
            printf("The maximum travel distance = %.2lf\n", cmax * davg + stations[i].dis);
            return 0;
        }
        bool flag = false;
        maxdis = nowdis + davg * cmax;
        int minstation = i;
        double minprice = INF;
        for (int j = i + 1; j <= n && stations[j].dis <= maxdis; j++) {
            if (stations[j].price < nowprice) {
                totalprice += ((stations[j].dis - nowdis) / davg - nowgas) * nowprice;
                nowprice = stations[j].price;
                nowdis = stations[j].dis;
                nowgas = 0;
                i = j;
                flag = true;
                break;
            }
            if (stations[j].price < minprice) {
                minprice = stations[j].price;
                minstation = j;
            }
        }
        if (flag == false && minprice != INF) {
            totalprice += (cmax - nowgas) * nowprice;
            nowgas = cmax - (stations[minstation].dis - nowdis) / davg;
            nowdis = stations[minstation].dis;
            nowprice = minprice;
            i = minstation;
        }
    }
    printf("%.2lf", totalprice);
    return 0;
}