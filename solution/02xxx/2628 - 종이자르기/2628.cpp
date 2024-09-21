#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, m, k, mode, a;
    vector<int> garo, sero;

    cin >> m >> n;
    cin >> k;

    garo.push_back(0);
    garo.push_back(m);
    sero.push_back(0);
    sero.push_back(n);

    for(int _ = 0; _ < k; _++) {
        cin >> mode >> a;

        if(mode == 0) sero.push_back(a);
        else garo.push_back(a);
    }

    sort(sero.begin(), sero.end());
    sort(garo.begin(), garo.end());

    int g = 0, s = 0;
    int garo_size = garo.size(), sero_size = sero.size();

    for(int i = 0; i < garo_size-1; i++) {
        if(garo[i+1]-garo[i] > g) g = garo[i+1]-garo[i];
    }

    for(int i = 0; i < sero_size-1; i++) {
        if(sero[i+1]-sero[i] > s) s = sero[i+1]-sero[i];
    }

    cout << g*s;
}