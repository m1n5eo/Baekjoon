#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct type {
    int country, student, score;
};

int number, n, m, k;
vector<type> v;
queue<type> qq;

bool compare(type a, type b) {
    return a.score > b.score;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> number;
    for(int i = 0; i < number; i++) {
        cin >> n >> m >> k;
        v.push_back({n, m, k});
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < 2; i++) {
        cout << v[i].country << " " << v[i].student << "\n";
    }

    int idx = 2;
    if(v[0].country == v[1].country) {
        while(v[0].country == v[idx].country) {
            idx += 1;
        }
    }

    cout << v[idx].country << " " << v[idx].student << "\n";

    return 0;
}