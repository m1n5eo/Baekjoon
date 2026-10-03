#include <iostream>
#include <string>
using namespace std;

int n;
string str;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;

        if(6 <= str.length() && str.length() <= 9) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}