#include <iostream>
#include <deque>
using namespace std;

int n, command, k;
deque<int> dq;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> command;

        if(command == 1) {
            cin >> k;
            dq.push_front(k);
        }
        else if(command == 2) {
            cin >> k;
            dq.push_back(k);
        }
        else if(command == 3) {
            if(dq.size() == 0) cout << "-1\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if(command == 4) {
            if(dq.size() == 0) cout << "-1\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if(command == 5) {
            cout << dq.size() << "\n";
        }
        else if(command == 6) {
            if(dq.size() == 0) cout << "1\n";
            else cout << "0\n";
        }
        else if(command == 7) {
            if(dq.size() == 0) cout << "-1\n";
            else cout << dq.front() << "\n";
        }
        else if(command == 8) {
            if(dq.size() == 0) cout << "-1\n";
            else cout << dq.back() << "\n";
        }
    }

    return 0;
}