#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int n, team, member;
    int pen[1111];

    cin >> n;
    cin >> team >> member;
    for(int i = 0; i < n; i++) {
        cin >> pen[i];
    }

    int total = team*member, cnt = 0;

    sort(pen, pen+n, compare);

    for(int i = 0; i < n; i++) {
        total = total-pen[i];
        cnt = cnt+1;

        if(total <= 0) {
            cout << cnt;
            break;
        }
        else if(i == n-1) {
            cout << "STRESS";
        }
    }
    
    return 0;
}