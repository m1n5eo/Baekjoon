#include <iostream>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

double solution() {
    double x, y, h;
    cin >> x >> y >> h;

    double left = 0, right = 3000000000, w;
    for(int i = 0; i < (1<<10); i++) {
        w = (left+right)/2;
        if(x*x < w*w || y*y < w*w) right = w;
        else if(1/h == 1/sqrt(x*x-w*w) + 1/sqrt(y*y-w*w)) return w;
        else if(1/h > 1/sqrt(x*x-w*w) + 1/sqrt(y*y-w*w)) left = w;
        else right = w;
    }
    return w;
}

int main() {
    FASTIO
    cout << solution();
}