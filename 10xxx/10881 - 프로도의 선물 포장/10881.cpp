#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000

struct type {
    int x, y;
};

int t;

int main() {
    FASTIO

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        int result = INF;
        vector<type> v;

        for(int i = 0; i < 3; i++) {
            int a, b;
            cin >> a >> b;

            v.push_back({a, b});
        }

        for(int i = 0; i < 3; i++) {
            v.push_back({v[i].y, v[i].x});
        }

        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                for(int k = 0; k < 6; k++) {
                    if(i%3 == j%3 || j%3 == k%3 || k%3 == i%3) {
                        continue;
                    }

                    result = min(result, (v[i].x+v[j].x+v[k].x)*max({v[i].y, v[j].y, v[k].y}));
                    result = min(result, max(v[i].x+v[j].x, v[k].x)*(max(v[i].y, v[j].y) + v[k].y));
                }
            }
        }

        cout << result << "\n";
    }
}