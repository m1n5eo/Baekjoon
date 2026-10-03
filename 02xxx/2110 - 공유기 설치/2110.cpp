#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m, temp;
vector<int> house;

int Find(int start, int end) {
    int mid = (start + end) / 2;
    int dist = mid - house[0];

    if(start > end) {
        return dist;
    }

    int base = house[0];
    int cnt = 1;

    for(int i = 1; i < n; i++) {
        if(house[i] - base >= dist) {
            base = house[i];
            cnt += 1;
        }
    }

    if(m <= cnt) return Find(mid + 1, end);
    else return Find(start, mid - 1);
}

bool compare(int a, int b) {
    return a < b;
}

int main() {
    FASTIO

    cin >> n >> m;

    for(int _ = 0; _ < n; _++) {
        cin >> temp;
        house.push_back(temp);
    }

    sort(house.begin(), house.end(), compare);

    cout << Find(house[0], house[n-1]);
}