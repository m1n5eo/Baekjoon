#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define lli long long int
#define MAX 3333

int n, group, parent[MAX], cnt[MAX], result;
vector<pair<pair<lli, lli>, pair<lli, lli>>> point;

int ccw(pair<lli, lli> a, pair<lli, lli> b, pair<lli, lli> c) {
    lli CrossProduct = (b.first-a.first)*(c.second-a.second) - (c.first-a.first)*(b.second-a.second);

    if(CrossProduct < 0) return -1;
    else if(CrossProduct > 0) return 1;
    else return 0;
}

int Find(int a) {
    if(a == parent[a]) return a;

    int p = Find(parent[a]);
    parent[a] = p;

    return p;
}

bool isSame(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        point.push_back({{a, b}, {c, d}});
        parent[i] = i;

        if(point[i].first > point[i].second) swap(point[i].first, point[i].second);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int ABC = ccw(point[i].first, point[i].second, point[j].first);
            int ABD = ccw(point[i].first, point[i].second, point[j].second);

            int CDA = ccw(point[j].first, point[j].second, point[i].first);
            int CDB = ccw(point[j].first, point[j].second, point[i].second);

            if(ABC*ABD <= 0 && CDA*CDB <= 0) {
                if(ABC*ABD == 0 && CDA*CDB == 0) {
                    if(point[i].first > point[i].second) swap(point[i].first, point[i].second);
                    else if(point[j].first > point[j].second) swap(point[j].first, point[j].second);

                    if(point[i].first <= point[j].second && point[j].first <= point[i].second) {
                        if(isSame(i, j) == false) {
                            Union(i, j);
                        }
                    }
                }
                else {
                    if(isSame(i, j) == false) {
                        Union(i, j);
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        parent[i] = Find(i);
    }

    for(int i = 0; i < n; i++) {
        if(cnt[parent[i]] == 0) {
            group += 1;
        }

        cnt[parent[i]] += 1;
        result = max(result, cnt[parent[i]]);
    }

    cout << group << "\n" << result;

    return 0;
}