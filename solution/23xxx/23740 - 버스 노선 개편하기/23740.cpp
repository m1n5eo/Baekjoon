#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000

struct type {
    int start, end, cost;
};

bool compare(type x, type y) {
    return x.start < y.start;
}

int main() {
    FASTIO

    int n, a, b, c, sum = 0;
    vector<type> point, result;
    type now = {-INF, -INF, INF};

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        cin >> a >> b >> c;
        point.push_back({a, b, c});
    }

    sort(point.begin(), point.end(), compare);

    for(int i = 0; i < n; i++) {
        if(now.end < point[i].start) {
            if(i != 0) result.push_back(now);
            now = {point[i].start, point[i].end, point[i].cost};
        }
        else {
            now.end = max(now.end, point[i].end);
            now.cost = min(now.cost, point[i].cost);
        }
    }

    result.push_back(now);

    cout << result.size() << "\n";

    for(type results : result) {
        cout << results.start << " " << results.end << " " << results.cost << "\n";
    }
}