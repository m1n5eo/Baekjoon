#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int idx, ranking;
};

int n, m;
vector<type> player;

bool compare(type a, type b) {
    return a.ranking > b.ranking;
}

bool compare2(type a, type b) {
    return a.ranking < b.ranking;
}

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        player.push_back({i, 0});
    }

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        player[i].ranking = temp;

        for(int j = 0; j < i; j++) {
            if(player[j].ranking >= player[i].ranking) {
                player[j].ranking += 1;
            }
        }
    }

    sort(player.begin(), player.end(), compare);

    for(int i = 0; i < n-m; i++) player.erase(player.begin());
    for(int i = 0; i < m; i++) player[i].ranking = 0;

    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;

        player[i].ranking = temp;

        for(int j = 0; j < i; j++) {
            if(player[j].ranking >= player[i].ranking) {
                player[j].ranking += 1;
            }
        }
    }

    sort(player.begin(), player.end(), compare2);

    for(int i = 0; i < 3; i++) {
        cout << player[i].idx+1 << "\n";
    }

    return 0;
}