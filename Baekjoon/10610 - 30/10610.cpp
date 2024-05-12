#include <iostream>
#include <string>
using namespace std;

string num;
int sum, cnt[11];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> num;

    int len = num.length();

    for(int i = 0; i < len; i++) {
        cnt[num[i]-'0'] += 1;
        sum += num[i]-'0';
    }
    
    if(cnt[0] == 0 || sum%3 != 0) {
        cout << -1;
    }
    else {
        for(int i = 9; i >= 0; i--) {
            for(int j = 0; j < cnt[i]; j++) {
                cout << i;
            }
        }
    }

    return 0;
}