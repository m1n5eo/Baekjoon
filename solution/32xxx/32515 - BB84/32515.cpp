#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int n;
string a, b, c, d, key = "";

int main() {
    FASTIO

    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    for(int i = 0; i < n; i++) {
        if(a[i] == c[i] && b[i] == d[i]) {
            key = key + b[i];
        }
        else if(a[i] == c[i] && b[i] != d[i]) {
            cout << "htg!";
            exit(0);
        }
    }

    cout << key;
}