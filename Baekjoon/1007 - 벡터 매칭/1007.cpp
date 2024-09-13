#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000

struct coordinate {
    double x, y;
};

int t, n;
double _x, _y, result = INF;
vector<coordinate> vec;

void bruteforcing(int cnt, int plus, int minus, coordinate sum) {
    if(cnt == n) {
        double dist = sqrt(sum.x*sum.x + sum.y*sum.y);
        result = min(result, dist);
        return;
    }

    if(plus < n/2) bruteforcing(cnt+1, plus+1, minus, {sum.x+vec[cnt].x, sum.y+vec[cnt].y});
    if(minus < n/2) bruteforcing(cnt+1, plus, minus+1, {sum.x-vec[cnt].x, sum.y-vec[cnt].y});
}

int main() {
    FASTIO

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> _x >> _y;
            vec.push_back({_x, _y});
        }

        bruteforcing(0, 0, 0, {0, 0});

        cout.precision(6);
        cout << fixed;
        cout << result << "\n";

        result = INF;
        vec.clear();
    }
}