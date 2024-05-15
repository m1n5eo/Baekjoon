#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n;
vector<pair<long long int, long long int>> v;
stack<pair<long long int, long long int>> st;

long long int ccw(pair<long long int, long long int> a, pair<long long int, long long int> b, pair<long long int, long long int> c) {
    long long int CrossProduct = (b.first-a.first)*(c.second-a.second) - (c.first-a.first)*(b.second-a.second);

    return CrossProduct;
}

bool compare(pair<long long int, long long int> a, pair<long long int, long long int> b) {
    long long int standard = ccw(v[0], a, b);

    if(standard) return standard > 0;
    else if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for(int i = 1; i < n; i++) {
        if(v[i].second < v[0].second || (v[i].second == v[0].second && v[i].first < v[0].first)) {
            swap(v[i], v[0]);
        }
    }

    sort(v.begin()+1, v.end(), compare);

    st.push({v[0].first, v[0].second});
    st.push({v[1].first, v[1].second});

    int idx = 2;

    while(idx < n) {
        if(st.size() > 1) {
            pair<long long int, long long int> c = {v[idx].first, v[idx].second};
            pair<long long int, long long int> b = {st.top().first, st.top().second};
            st.pop();
            pair<long long int, long long int> a = {st.top().first, st.top().second};

            long long int sw = ccw(a, b, c);

            if(sw > 0) {
                st.push(b);
                st.push(c);
                idx += 1;
                continue;
            }
            else if(sw < 0) {
                continue;
            }
            else if(sw == 0) {
                st.push(c);
                idx += 1;
                continue;
            }
        }
        else {
            st.push(v[idx]);
            idx += 1;
        }
    }

    cout << st.size();

    return 0;
}