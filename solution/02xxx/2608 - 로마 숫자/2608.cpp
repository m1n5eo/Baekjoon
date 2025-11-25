#include <iostream>
#include <string>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    
string convert(int n) {
    string ret;
    int ns = to_string(n).size();
    for(int i = 0; i < ns && n; i++) {
        if(i == 0) {
            if(n%10 == 0) {
                n /= 10;
                continue;
            }
            else if(1 <= n%10 && n%10 <= 3) {
                for(int k = 0; k < n%10; k++) {
                    ret = 'I' + ret;
                }
            }
            else if(n%10 == 4) ret = "IV" + ret;
            else if(n%10 == 5) ret = "V" + ret;
            else if(6 <= n%10 && n%10 <= 8) {
                for(int k = 5; k < n%10; k++) ret = "I" + ret;
                ret = "V" + ret;
            }
            else if(n%10 == 9) ret = "IX" + ret;
        }
        else if(i == 1) {
            if(n%10 == 0) {
                n /= 10;
                continue;
            }
            else if(1 <= n%10 && n%10 <= 3) {
                for(int k = 0; k < n%10; k++) {
                    ret = "X" + ret;
                }
            }
            else if(n%10 == 4) ret = "XL" + ret;
            else if(n%10 == 5) ret = "L" + ret;
            else if(6 <= n%10 && n%10 <= 8) {
                for(int k = 5; k < n%10; k++) ret = "X" + ret;
                ret = "L" + ret;
            }
            else if(n%10 == 9) ret = "XC" + ret;
        }
        else if(i == 2) {
            if(n%10 == 0) {
                n /= 10;
                continue;
            }
            else if(1 <= n%10 && n%10 <= 3) {
                for(int k = 0; k < n%10; k++) {
                    ret = "C" + ret;
                }
            }
            else if(n%10 == 4) ret = "CD" + ret;
            else if(n%10 == 5) ret = "D" + ret;
            else if(6 <= n%10 && n%10 <= 8) {
                for(int k = 5; k < n%10; k++) ret = "C" + ret;
                ret = "D" + ret;
            }
            else if(n%10 == 9) ret = "CM" + ret;
        }
        else if(i == 3) {
            for(int k = 0; k < n%10; k++) {
                ret = "M" + ret;
            }
        }
        n /= 10;
    }
    return ret;
}

pair<int, string> solve() {
    map<char, int> latin;
    latin.insert({'M', 1000});
    latin.insert({'D', 500});
    latin.insert({'C', 100});
    latin.insert({'L', 50});
    latin.insert({'X', 10});
    latin.insert({'V', 5});
    latin.insert({'I', 1});

    int ret = 0;
    string number1, number2;
    cin >> number1 >> number2;

    int n1s = number1.size(), n2s = number2.size();
    for(int i = 0; i < n1s; i++) {
        if(i != n1s-1 && latin[number1[i]] >= latin[number1[i+1]]) ret += latin[number1[i]];
        else if(i != n1s-1) ret -= latin[number1[i]];
        else ret += latin[number1[i]];
    }
    for(int i = 0; i < n2s; i++) {
        if(i != n2s-1 && latin[number2[i]] >= latin[number2[i+1]]) ret += latin[number2[i]];
        else if(i != n2s-1) ret -= latin[number2[i]];
        else ret += latin[number2[i]];
    }
    return {ret, convert(ret)};
}

int main() {
    FASTIO
    pair<int, string> sol = solve();
    cout << sol.first << "\n" << sol.second;
}