#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, sum, temp_day, temp_money;
priority_queue<pair<int, int>> now, res;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp_money >> temp_day;

        now.push({-temp_day, temp_money});
    }

    while(now.size()) {
        if(-now.top().first > res.size()) {
            res.push({-now.top().second, now.top().first});
        }
        else {
            if(now.top().second > -res.top().first) {
                res.push({-now.top().second, now.top().first});
                res.pop();
            }
        }

        now.pop();
    }

    while(res.size()) {
        sum += (-res.top().first);
        res.pop();
    }

    cout << sum;

    return 0;
}