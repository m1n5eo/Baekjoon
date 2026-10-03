#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
    int x, y;
};

int n, r, a, b, max_cnt, save_x, save_y;
point max_point = {-111, -111}, min_point = {111, 111};
vector<point> v;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> r;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});

        max_point.x = max(max_point.x, a);
        max_point.y = max(max_point.y, b);
        min_point.x = min(min_point.x, a);
        min_point.y = min(min_point.y, b);
    }

    for(int i = min_point.x; i <= max_point.x; i++) {
        for(int j = min_point.y; j <= max_point.y; j++) {
            int cnt = 0;

            for(int k = 0; k < n; k++) {
                if((v[k].x-i)*(v[k].x-i) + (v[k].y-j)*(v[k].y-j) <= r*r) {
                    cnt += 1;
                }
            }

            if(max_cnt < cnt) {
                max_cnt = cnt;
                save_x = i;
                save_y = j;
            }
        }
    }

    cout << save_x << " " << save_y;

    return 0;
}