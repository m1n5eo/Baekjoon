#include <bits/stdc++.h>
using namespace std;

int main() {
    int ax, ay, az, cx, cy, cz;
    scanf("%d %d %d", &ax, &ay, &az);
    scanf("%d %d %d", &cz, &cy, &cx);
    printf("%d %d %d", cz-az, cy/ay, cx-ax);
}
