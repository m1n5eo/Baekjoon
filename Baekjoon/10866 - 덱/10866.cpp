#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num, arr[20001];
    int frontidx = 10000, backidx = 10001;
    string input;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> input;
        if(input == "push_front") {
            cin >> num;
            arr[frontidx] = num;
            frontidx--;
        }
        else if(input == "push_back") {
            cin >> num;
            arr[backidx] = num;
            backidx++;
        }
        else if(input == "pop_front") {
            if(frontidx+1 != backidx) {
                frontidx++;
                cout << arr[frontidx] << "\n";
            }
            else cout << -1 << "\n";
        }
        else if(input == "pop_back") {
            if(frontidx+1 != backidx) {
                backidx--;
                cout << arr[backidx] << "\n";
            }
            else cout << -1 << "\n";
        }
        else if(input == "size") cout << backidx-frontidx-1 << "\n";
        else if(input == "empty") {
            if(backidx-frontidx-1 == 0) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(input == "front") {
            if(frontidx+1 != backidx) cout << arr[frontidx+1] << "\n";
            else cout << -1 << "\n";
        }
        else if(input == "back") {
            if(frontidx+1 != backidx) cout << arr[backidx-1] << "\n";
            else cout << -1 << "\n";
        }
    }
}
