#include <iostream>
using namespace std;

double w, h, x, y, a, b, r;
double x1, y1, x2, y2;
int player, cnt;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> w >> h >> x >> y >> player;

    x1 = x, y1 = y+h/2;
    x2 = x+w, y2 = y+h/2;
    r = h/2;

    for(int t = 0; t < player; t++) {
        cin >> a >> b;

        if((x <= a && a <= x+w) && (y <= b && b <= y+h)) {
            cnt += 1;
            continue;
        }
        else if((a-x1)*(a-x1) + (b-y1)*(b-y1) <= r*r) {
            cnt += 1;
            continue;
        }
        else if((a-x2)*(a-x2) + (b-y2)*(b-y2) <= r*r) {
            cnt += 1;
            continue;
        }
    }

    cout << cnt;

    return 0;
}