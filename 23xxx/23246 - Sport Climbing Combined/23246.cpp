#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int number, lead, speed, bouldering;
};

bool compare(type a, type b) {
    int ag = a.lead * a.speed * a.bouldering;
    int bg = b.lead * b.speed * b.bouldering;
    int ah = a.lead + a.speed + a.bouldering;
    int bh = b.lead + b.speed + b.bouldering;
    if(ag != bg) return ag < bg;
    else if(ah != bh) return ah < bh;
    else return a.number < b.number;
}

int main() {
    FASTIO
    int n;
    cin >> n;
    vector<type> player(n, {0, 0, 0});
    for(int i = 0; i < n; i++) cin >> player[i].number >> player[i].lead >> player[i].speed >> player[i].bouldering;
    sort(player.begin(), player.end(), compare);
    cout << player[0].number << " " << player[1].number << " " << player[2].number;
}