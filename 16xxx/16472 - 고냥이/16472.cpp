#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n;
    string str;

    cin >> n;
    cin >> str;
    
    int start = 0, end = 0, cnt = 0;
    vector<int> check(33, -1);

    check[str[start]-'a'] = 0;
    cnt = 1;

    int str_size = str.size(), result = 0;

    while(end < str_size) {
        if(cnt <= n) result = max(result, end-start+1);

        if(cnt > n) {
            if(check[str[start]-'a'] == start) {
                cnt -= 1;
                check[str[start]-'a'] = -1;
            }

            start += 1;
        }
        else if(cnt <= n) {
            end += 1;
            if(check[str[end]-'a'] == -1) cnt += 1;
            check[str[end]-'a'] = end;
        }
    }

    cout << result;
}