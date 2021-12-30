#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, x1, y1, x2, y2;
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x, &y);
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    if(x1 <= x && x <= x2 && y1 <= y && y <= y2) printf("충돌");
    else printf("비충돌");
}