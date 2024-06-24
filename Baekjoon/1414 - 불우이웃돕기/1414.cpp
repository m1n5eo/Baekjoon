#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55

struct type {
    int a, b, d;
};

int n, total, dist, parent[MAX], line[MAX][MAX];
vector<type> v;

bool compare(type x, type y) {
    return x.d < y.d;
}

int Find(int x) {
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool Same(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for(int j = 0; j < n; j++) {
            if(str[j] == '0') line[i][j] = 0;
            else if('a' <= str[j] && str[j] <= 'z') line[i][j] = str[j]-'a'+1;
            else if('A' <= str[j] && str[j] <= 'Z') line[i][j] = str[j]-'A'+27;

            if(line[i][j] != 0) v.push_back({min(i, j), max(i, j), line[i][j]});
            total += line[i][j];
        }
    }

    sort(v.begin(), v.end(), compare);

    int v_size = v.size();

    for(int i = 0; i < v_size; i++) {
        if(v[i].a != v[i].b) {
            if(Same(v[i].a, v[i].b) == false) {
                Union(v[i].a, v[i].b);
                dist += v[i].d;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(Find(i) != 0) {
            cout << -1;
            exit(0);
        }
    }
    
    cout << total-dist;
}