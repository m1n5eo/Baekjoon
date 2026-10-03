#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    string str = "SciComLove";
    int n, len = str.length();

    cin >> n;

    if(n%2 == 0) {
        for(int i = 0; i < len; i++) {
            cout << str[i];
        }
    } 
    else if(n%2 == 1) {
        for(int i = len-1; i >= 0; i--) {
            cout << str[i];
        }
    }

    return 0;
}