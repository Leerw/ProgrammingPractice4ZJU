#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct ID_COME {
    string ID;
    string COME;
    ID_COME (string id, string come) {
        ID = id;
        COME = come;
    }
    friend bool operator < (ID_COME s1, ID_COME s2) {
        int hour1 = stoi(s1.COME.substr(0, 2));
        int hour2 = stoi(s2.COME.substr(0, 2));
        if (hour1 != hour2) { return hour1 > hour2; };
        int minute1 = stoi(s1.COME.substr(3, 2));
        int minute2 = stoi(s2.COME.substr(3, 2));
        if (minute1 != minute2) { return minute1 > minute2; }
        int second1 = stoi(s1.COME.substr(6, 2));
        int second2 = stoi(s2.COME.substr(6, 2));
        return second1 > second2;
    }
};

struct ID_OUT {
    string ID;
    string OUT;
    ID_OUT (string id, string out) {
        ID = id;
        OUT = out;
    }
    friend bool operator < (ID_OUT s1, ID_OUT s2) {
        int hour1 = stoi(s1.OUT.substr(0, 2));
        int hour2 = stoi(s2.OUT.substr(0, 2));
        if (hour1 != hour2) { return hour1 < hour2; };
        int minute1 = stoi(s1.OUT.substr(3, 2));
        int minute2 = stoi(s2.OUT.substr(3, 2));
        if (minute1 != minute2) { return minute1 < minute2; }
        int second1 = stoi(s1.OUT.substr(6, 2));
        int second2 = stoi(s2.OUT.substr(6, 2));
        return second1 < second2;
    }
};



int main() {
    priority_queue<ID_COME> come;
    priority_queue<ID_OUT> out;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string id;
        string come_time;
        string out_time;
        cin >> id >> come_time >> out_time;
        ID_COME id_come(id, come_time);
        ID_OUT id_out(id, out_time);
        come.push(id_come);
        out.push(id_out);
    }
    cout << come.top().ID << " " << out.top().ID;
    return 0;
}
