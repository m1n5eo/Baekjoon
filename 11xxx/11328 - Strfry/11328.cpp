#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int n;
    string str1, str2;

    cin >> n;
    for(int t = 0; t < n; t++) {
        cin >> str1 >> str2;

        int sw = 1;

        if(str1.length() != str2.length()) sw = 0;
        else {
            int len = str1.length(), cnt[33] = {0, };

            for(int i = 0; i < len; i++) {
                cnt[str1[i]-'a'] += 1;
            }

            for(int i = 0; i < len; i++) {
                if(cnt[str2[i]-'a']) cnt[str2[i]-'a'] -= 1;
                else {
                    sw = 0;
                    break;
                }
            }
        }

        if(sw == 0) cout << "Impossible\n";
        else if(sw == 1) cout << "Possible\n";
    }

    return 0;
}