#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> s;
    while(s.size() != 1) {
        cin >> n;
        if(s.size() > n) {
            s.erase(n-1, 1);
        }
        else {
            s.erase(s.size()-1, 1);
        }
        cout << s << "\n";
    }
}