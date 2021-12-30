#include <bits/stdc++.h>
using namespace std;

#define mod 1234567891

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    string str;

    cin >> n >> str;
    long long int print = 0, temp = 1;
    for(int i = 0; i < n; i++) {
        print += ((str[i]-'a'+1) * temp) % mod;
        temp = (temp * 31) % mod;
    }
   cout << print%mod;
}