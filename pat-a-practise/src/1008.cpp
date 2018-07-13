#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int now  = 0;
    int floor = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> floor;
        if (floor > now) {
            ans += (floor - now) * 6;
        } else if (floor < now) {
            ans += (now - floor) * 4;
        }
        ans += 5;
        now = floor;
    }
    cout << ans;
    return  0;
}