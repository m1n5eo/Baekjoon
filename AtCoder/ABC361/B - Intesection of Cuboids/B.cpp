#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct point {
    int x, y, z;
};

point a1, a2, b1, b2;
point final1, final2;

int main() {
    FASTIO

    cin >> a1.x >> a1.y >> a1.z >> a2.x >> a2.y >> a2.z;
    cin >> b1.x >> b1.y >> b1.z >> b2.x >> b2.y >> b2.z;

    final1.x = max(a1.x, b1.x);
    final1.y = max(a1.y, b1.y);
    final1.z = max(a1.z, b1.z);

    final2.x = min(a2.x, b2.x);
    final2.y = min(a2.y, b2.y);
    final2.z = min(a2.z, b2.z);

    if(final1.x < final2.x && final1.y < final2.y && final1.z < final2.z) cout << "Yes";
    else cout << "No";
}