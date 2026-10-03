#include <bits/stdc++.h>
using namespace std;

int n, k, arr[22];
string str;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int t = 0; t < n; t++) {
        cin >> str;
        if(str == "add") {
            cin >> k;
            arr[k]++;
        }
        else if(str == "remove") {
            cin >> k;
            arr[k] = 0;
        }
        else if(str == "check") {
            cin >> k;
            if(arr[k]) cout << "1\n";
            else cout << "0\n";
        }
        else if(str == "toggle") {
            cin >> k;
            if(arr[k]) arr[k] = 0;
            else arr[k]++;
        }
        else if(str == "all") {
            sort(arr+1, arr+21, compare);
            for(int i = 1; i <= 20; i++) arr[i] = 1;
        }
        else if(str == "empty") {
            for(int i = 1; i <= 20 && arr[i]; i++) arr[i] = 0;
        }
    }
}