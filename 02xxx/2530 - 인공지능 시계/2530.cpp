#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m, s, sec;
    scanf("%d %d %d", &h, &m, &s);
    scanf("%d", &sec);
    int k = h*3600+m*60+s+sec;
    printf("%d %d %d", k/3600%24, (k-(k/3600*3600))/60, k-(k/3600*3600)-((k-(k/3600*3600))/60*60));
}
