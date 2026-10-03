#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 1000001

struct type {
    lli idx, left, right;
};

lli sqrtn;

bool comp(type a, type b) {
    if(a.left/sqrtn != b.left/sqrtn) return a.left < b.left;
    else return a.right < b.right;
}

vector<lli> solution() {
    lli n, m;
    cin >> n >> m;
    vector<lli> a(n);
    vector<type> query;
    for(lli i = 0; i < n; i++) cin >> a[i];
    for(lli i = 0; i < m; i++) {
        lli l, r; cin >> l >> r;
        query.push_back({i, l-1, r-1});
    }

    vector<lli> answer(m), count(MAX);
    sqrtn = sqrt(n);
    sort(query.begin(), query.end(), comp);

    lli l = query[0].left, r = query[0].right, value = 0;
    for(lli i = l; i <= r; i++) {
        value -= count[a[i]]*count[a[i]]*a[i];
        count[a[i]] += 1;
        value += count[a[i]]*count[a[i]]*a[i];
    }
    answer[query[0].idx] = value;
    for(lli i = 1; i < m; i++) {
        type now = query[i];
        while(now.left < l) {
            l -= 1;
            value -= count[a[l]]*count[a[l]]*a[l];
            count[a[l]] += 1;
            value += count[a[l]]*count[a[l]]*a[l];
        }
        while(now.left > l) {
            value -= count[a[l]]*count[a[l]]*a[l];
            count[a[l]] -= 1;
            value += count[a[l]]*count[a[l]]*a[l];
            l += 1;
        }
        while(now.right > r) {
            r += 1;
            value -= count[a[r]]*count[a[r]]*a[r];
            count[a[r]] += 1;
            value += count[a[r]]*count[a[r]]*a[r];
        }
        while(now.right < r) {
            value -= count[a[r]]*count[a[r]]*a[r];
            count[a[r]] -= 1;
            value += count[a[r]]*count[a[r]]*a[r];
            r -= 1;
        }
        answer[now.idx] = value;
    }
    return answer;
}

int main() {
    FASTIO
    for(lli s : solution()) cout << s << "\n";
}