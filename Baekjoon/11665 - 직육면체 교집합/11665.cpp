#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
    int x, y, z;
};

int n;
type point[2], min_point, max_point;

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> point[0].x >> point[0].y >> point[0].z;
        cin >> point[1].x >> point[1].y >> point[1].z;

        if(i == 0) {
            min_point = point[0];
            max_point = point[1];
        }
        else {
            min_point.x = max(min_point.x, point[0].x);
            min_point.y = max(min_point.y, point[0].y);
            min_point.z = max(min_point.z, point[0].z);

            max_point.x = min(max_point.x, point[1].x);
            max_point.y = min(max_point.y, point[1].y);
            max_point.z = min(max_point.z, point[1].z);
        }
    }

    int result = (max_point.x-min_point.x)*(max_point.y-min_point.y)*(max_point.z-min_point.z);

    if(max_point.x-min_point.x < 0) cout << 0;
    else if(max_point.y-min_point.y < 0) cout << 0;
    else if(max_point.z-min_point.z < 0) cout << 0;
    else cout << result;
}