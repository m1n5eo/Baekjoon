#include <iostream>
#include <string>
using namespace std;

int n, cnt[2];
string str[2], temp;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> str[0] >> str[1];

    temp = str[0];

    if(str[0][0] == '0') str[0][0] = '1';
    else if(str[0][0] == '1') str[0][0] = '0';

    if(str[0][1] == '0') str[0][1] = '1';
    else if(str[0][1] == '1') str[0][1] = '0';

    cnt[0] += 1;

    for(int i = 0; i < n-1; i++) {
        if(str[0][i] != str[1][i]) {
            for(int j = 0; j < 3; j++) {
                if(i == n-2 && j == 2) break;

                if(str[0][i+j] == '0') str[0][i+j] = '1';
                else if(str[0][i+j] == '1') str[0][i+j] = '0';
            }
            cnt[0] +=1;
        }
    }

    if(str[0] != str[1]) cnt[0] = -1;

    str[0] = temp;

    for(int i = 0; i < n-1; i++) {
        if(str[0][i] != str[1][i]) {
            for(int j = 0; j < 3; j++) {
                if(i == n-2 && j == 2) break;

                if(str[0][i+j] == '0') str[0][i+j] = '1';
                else if(str[0][i+j] == '1') str[0][i+j] = '0';
            }
            cnt[1] +=1;
        }
    }

    if(str[0] != str[1]) cnt[1] = -1;

    if(cnt[0] != -1 && cnt[1] != -1) cout << min(cnt[0], cnt[1]);
    else if(cnt[0] == -1) cout << cnt[1];
    else if(cnt[1] == -1) cout << cnt[0];
    else cout << -1;

    return 0;
}