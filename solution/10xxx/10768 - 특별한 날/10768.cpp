#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int month, day;

    cin >> month >> day;
    if(month < 2) cout << "Before";
    else if(month > 2) cout << "After";
    else if(month == 2) {
        if(day < 18) cout << "Before";
        else if(day > 18) cout << "After";
        else cout << "Special";
    }
}