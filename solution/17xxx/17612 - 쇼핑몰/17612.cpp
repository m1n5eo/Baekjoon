#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define lli long long int
#define MAX 111111

struct type {
    lli id;
    int now, where;
};

struct compare1 {
    bool operator() (pii &x, pii &y) {
        if(x.second != y.second) return x.second > y.second;
        else return x.first > y.first;
    }
};

struct compare2 {
    bool operator() (type &x, type &y) {
        if(x.now != y.now) return x.now > y.now;
        else if(x.where != y.where) return x.where < y.where;
    }
};

int main() {
    FASTIO

    int n, k, w;
    lli d, result = 0;
    priority_queue<pii, vector<pii>, compare1> time;
    priority_queue<type, vector<type>, compare2> desk;

    cin >> n >> k;

    for(int i = 1; i <= k; i++) {
        time.push({i, 0});
    }

    for(int _ = 0; _ < n; _++) {
        cin >> d >> w;

        pii t = time.top();
        time.pop();

        desk.push({d, w+t.second, t.first});
        time.push({t.first, w+t.second});
    }
    
    for(lli i = 1; i <= n; i++) {
        result += desk.top().id * i;
        desk.pop();
    }

    cout << result;
}