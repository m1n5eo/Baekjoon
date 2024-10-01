#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int ax, ay, az, cx, cy, cz;

    cin >> ax >> ay >> az;
    cin >> cz >> cy >> cx;

    cout << cz-az << " " << cy/ay << " " << cx-ax;
}