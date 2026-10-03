#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAX 200001

int t, n, parent[MAX], cnt[MAX];

int Find(int x) {
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x != y) {
        parent[x] = y;
        cnt[x] += cnt[y];
        cnt[y] = cnt[x];
    }

    cout << cnt[x] << "\n";
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        int idx = 1;
        map<string, int> name;

        for(int i = 0; i < MAX; i++) {
            parent[i] = i;
            cnt[i] = 0;
        }
        name.clear();

        cin >> n;

        for(int i = 0; i < n; i++) {
            string name1, name2;
            cin >> name1 >> name2;

            if(name.find(name1) == name.end()) {
                name.insert({name1, idx});
                cnt[idx] = 1;
                idx += 1;
            }
            if(name.find(name2) == name.end()) {
                name.insert({name2, idx});
                cnt[idx] = 1;
                idx += 1;
            }

            Union(name[name1], name[name2]);
        }
    }
}