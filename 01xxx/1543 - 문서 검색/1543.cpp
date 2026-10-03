#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    int len1 = str1.length(), len2 = str2.length();
    int res = 0;

    for(int i = 0; i <= len1-len2; i++) {
        int cnt = 0;

        for(int j = i; j < i+len2; j++) {
            if(str1[j] == str2[j-i]) cnt += 1;
        }

        if(cnt == len2) {
            res += 1;
            i += len2-1;
        }
    }

    cout << res;

    return 0;
}