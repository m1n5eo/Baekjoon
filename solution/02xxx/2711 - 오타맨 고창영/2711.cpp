#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t, n;
    string str;

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n >> str;

        int len = str.length();

        for(int i = 0; i < len; i++) {
            if(i == n-1) continue;

            cout << str[i];
        }

        cout << "\n";
    }

    return 0;
}