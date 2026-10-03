#include <iostream> // 2987
#include <algorithm>
#include <vector>
using namespace std;

#define lli long long int

struct point {
    lli x, y;
};

lli n, a, b;
vector<point> triangle, apple;

lli ccw(point a, point b, point c) {
    lli CrossProduct = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);

    if(CrossProduct < 0) return -1;
    else if(CrossProduct > 0) return 1;
    else return 0;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 0; i < 3; i++) {
        cin >> a >> b;
        triangle.push_back({a, b});
    }

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        apple.push_back({a, b});
    }

    double area = triangle[0].x*(triangle[1].y-triangle[2].y) + triangle[1].x*(triangle[2].y-triangle[0].y) + triangle[2].x*(triangle[0].y-triangle[1].y);

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        lli first = ccw(triangle[0], triangle[1], apple[i]);
        lli second = ccw(triangle[1], triangle[2], apple[i]);
        lli third = ccw(triangle[2], triangle[0], apple[i]);

        if(first <= 0 && second <= 0 && third <= 0) cnt += 1;
        else if(first >= 0 && second >= 0 && third >= 0) cnt += 1;
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(area)/2 << "\n" << cnt;

    return 0;
}