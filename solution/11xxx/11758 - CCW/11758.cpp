#include <iostream>
using namespace std;

struct point {
    int x, y, z;
};

int ccw(point a, point b, point c) {
    int CrossProduct = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);

    if(CrossProduct > 0) return 1;
    else if(CrossProduct < 0) return -1;
    else return 0;
}

int main() {
    point a, b, c;

    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    int res = ccw(a, b, c);

    cout << res;

    return 0;
}