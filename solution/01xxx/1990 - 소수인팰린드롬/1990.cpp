#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111111

bool isPalindrome(int num) {
    string n = to_string(num);
    int ns = n.size();
    for(int i = 0; i < ns/2; i++) {
        if(n[i] != n[ns-i-1]) {
            return false;
        }
    }
    return true;
}

vector<int> solve() {
    vector<bool> check(MAX, true);
    check[0] = check[1] = false;
    for(int i = 2; i*i < MAX; i++) {
        if(check[i] == true) {
            for(int j = i*2; j < MAX; j+=i) {
                check[j] = false;
            }
        }
    }

    int a, b;
    vector<int> ret;
    cin >> a >> b;
    for(int i = a; i <= b; i++) {
        if(check[i] && isPalindrome(i)) {
            ret.push_back(i);
        }
    }
    ret.push_back(-1);
    return ret;
}

int main() {
    FASTIO
    vector<int> sol = solve();
    for(int s : sol) cout << s << "\n";
}