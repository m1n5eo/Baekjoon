#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int day, homework, a, b, c, d;

    cin >> day;
    cin >> a >> b >> c >> d;
    if(a%c) homework = a/c+1;
    else homework = a/c;
    if(b%d) homework = max(homework, b/d+1);
    else homework = max(homework, b/d);
    cout << day-homework;
}