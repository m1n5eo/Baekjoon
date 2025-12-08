#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli count(vector<lli> video, lli s) {
    lli n = video.size(), now = 0, ret = 0;
    for(lli i = 0; i < n; i++) {
        if(now + video[i] > s) {
            now = video[i];
            ret += 1;
        }
        else now += video[i];
    }
    return ret+1;
}

lli solve() {
    lli n, m, left = 0, right = 0;
    cin >> n >> m;
    vector<lli> video;
    for(lli i = 0; i < n; i++) {
        lli temp; cin >> temp;
        video.push_back(temp);
        left = max(left, temp);
        right += temp;
    }

    lli ret = right;
    while(left < right) {
        lli mid = (left+right)/2;
        lli cl = count(video, left), cm = count(video, mid), cr = count(video, right);

        if(cl <= m) ret = min(ret, left);
        if(cm <= m) ret = min(ret, mid);
        if(cr <= m) ret = min(ret, right);

        if(cm > m) left = mid+1;
        else right = mid-1;
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}