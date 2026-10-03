#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1000001

struct type {
    int idx, left, right;
};

int sqrtn;

bool compare(type a, type b) {
    if(a.left/sqrtn != b.left/sqrtn) return a.left < b.left;
    else return a.right < b.right;
}

vector<int> solution() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    vector<type> query;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        query.push_back({i, l-1, r-1});
    }

    vector<int> answer(m), count(MAX, 0);
    sqrtn = sqrt(n);
    sort(query.begin(), query.end(), compare);

    int l = query[0].left, r = query[0].right, value = 0;
    for(int i = l; i <= r; i++) {
        if(count[a[i]] == 0) value += 1;
        count[a[i]] += 1;
    }
    answer[query[0].idx] = value;
    for(int i = 1; i < m; i++) {
        type now = query[i];
        while(now.left < l) {
            l -= 1;
            if(count[a[l]] == 0) value += 1;
            count[a[l]] += 1;
        }
        while(now.left > l) {
            count[a[l]] -= 1;
            if(count[a[l]] == 0) value -= 1;
            l += 1;
        }
        while(now.right > r) {
            r += 1;
            if(count[a[r]] == 0) value += 1;
            count[a[r]] += 1;
        }
        while(now.right < r) {
            count[a[r]] -= 1;
            if(count[a[r]] == 0) value -= 1;
            r -= 1;
        }
        answer[now.idx] = value;
    }
    return answer;
}

int main() {
    FASTIO
    for(int s : solution()) cout << s << "\n";
}