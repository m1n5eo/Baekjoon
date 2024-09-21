#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pi;

#define fi first
#define se second

pi rtg[4];

int length(int on, int tw) {
    ///  (rtg[on].fi - rtg[tw].fi)
    ///  (rtg[on].se - rtg[tw].se)
    /// printf("length(%d %d). %d %d\n", on, tw, rtg[on].fi - rtg[tw].fi, rtg[on].se - rtg[tw].se);
    return (rtg[on].fi - rtg[tw].fi)*(rtg[on].fi - rtg[tw].fi) + (rtg[on].se - rtg[tw].se)*(rtg[on].se - rtg[tw].se);
}

bool cmp(pi a, pi b) {
    if(a.fi < b.fi) {
        return 1;
    }
    if(a.fi == b.fi) {
        if(a.se < b.se) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int t, bb[4], dd[2]; /// bb.변    dd.대각선
    scanf("%d", &t);
    for (int testcase = 0; testcase < t; testcase++) {
        for(int i = 0; i < 4; i++) {
            scanf("%d %d", &rtg[i].fi, &rtg[i].se);
        }
        sort(rtg, rtg+4, cmp);

        bb[0] = length(0, 1);
        bb[1] = length(0, 2);
        bb[2] = length(1, 3);
        bb[3] = length(2, 3);

        dd[0] = length(0, 3);
        dd[1] = length(1, 2);

        /// printf("%d %d %d %d / %d %d\n", bb[0], bb[1], bb[2], bb[3], dd[0], dd[1]);
        if(bb[0] == bb[1] && bb[1] == bb[2] && bb[2] == bb[3] && dd[0] == dd[1]) printf("1\n");
        else printf("0\n");
    }
}
