#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli solution() {
    string temp, word = "";
    cin >> temp;
    for(char t : temp) {
        word += '#';
        word += t;
    }
    word += '#';

    lli n = word.size(), r = -1, p;
    vector<lli> res(n, 0);
    for(lli i = 0; i < n; i++) {
        if(r < i) {
            p = r = i;
            while(r < n && r <= 2*p && word[r] == word[2*p-r]) r += 1;
            r -= 1;
            res[i] = r-p;
        }
        else {
            lli j = 2*p-i;
            if(res[j] < r-i) res[i] = res[j];
            else if(res[j] > r-i) res[i] = r-i;
            else {
                p = i;
                while(r < n && r <= 2*p && word[r] == word[2*p-r]) r += 1;
                r -= 1;
                res[i] = r-p;
            }
        }
    }

    lli ret = 0;
    for(lli i = 0; i < n; i++) ret += (res[i]+1)/2;
    return ret;
}

int main() {
    FASTIO
    cout << solution();
}