#include <iostream>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

struct coordinate {
    lli x, y, r;
};

int main() {
    FASTIO
    
    coordinate a, b;

    cin >> a.x >> a.y >> a.r;
    cin >> b.x >> b.y >> b.r;

    lli dist = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));

    if(dist < a.r+b.r) cout << "YES";
    else cout << "NO";
}