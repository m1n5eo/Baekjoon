#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55

int n, m, k;
vector<int> parent, real, party[MAX];

int Find(int a) {
    if(parent[a] == a) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

bool Same(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    cin >> k;

    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;

        real.push_back(temp);

        if(i != 0) Union(real[i-1], real[i]);
    }

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;

        for(int j = 0; j < num; j++) {
            int temp;
            cin >> temp;

            party[i].push_back(temp);

            if(j > 0) Union(party[i][j-1], party[i][j]);
        }
    }

    int cnt = 0;

    if(k != 0) {
        for(int i = 0; i < m; i++) {
            int partySize = party[i].size();

            for(int j = 0; j < partySize; j++) {
                if(Same(party[i][j], real[0]) == true) {
                    cnt += 1;
                    break;
                }
            }
        }
    }

    cout << m-cnt << "\n";
}