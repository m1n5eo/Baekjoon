#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pil pair<int, long long int>
#define lli long long int
#define weight first
#define price second

int n, k, b, idx = 0;
lli a, result = 0;
vector<pil> jewerly;
vector<lli> backpack;
priority_queue<lli> pq;

bool compare1(pil x, pil y) {
    if(x.weight != y.weight) return x.weight < y.weight;
    return x.price < y.price;
}

bool compare2(lli x, lli y) {
    return x < y;
}

int main() {
    FASTIO

    cin >> n >> k;

    for(int _ = 0; _ < n; _++) {
        cin >> a >> b;
        jewerly.push_back({a, b});
    }

    for(int _ = 0; _ < k; _++) {
        cin >> a;
        backpack.push_back(a);
    }

    sort(jewerly.begin(), jewerly.end(), compare1);
    sort(backpack.begin(), backpack.end(), compare2);

    for(int i = 0; i < k; i++) {
        while(idx < n && jewerly[idx].weight <= backpack[i]) {
            pq.push(jewerly[idx++].price);
        }

        if(pq.size()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result;
}