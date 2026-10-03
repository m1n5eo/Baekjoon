#include <iostream>
#include <string>
using namespace std;

#define MAX 1111111

int n, max_failure = -1, failure[MAX] = {-1, };
string str;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> str;

    for(int i = 1; i < n; i++) {
        int j = failure[i-1];

        while(str[i] != str[j+1] && j >= 0) j = failure[j];

        if(str[i] == str[j+1]) failure[i] = j+1;
        else failure[i] = -1;
    }

    if(failure[n-1] != -1) cout << n-failure[n-1]-1;
    else cout << n;
}