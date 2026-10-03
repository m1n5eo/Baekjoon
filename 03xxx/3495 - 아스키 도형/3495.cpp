#include <iostream>
#include <string>
using namespace std;

string str;
int n, m, sw, cnt;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str;
        sw = 0;
        for(int j = 0; j < m; j++) {
            if(str[j] == '/' || str[j] == '\\') {
                sw = 1-sw;
                cnt += 1;
            }
            else if(str[j] == '.' && sw == 1) {
                cnt += 2;
            }
        }
    }

    cout << cnt/2;

    return 0;
}