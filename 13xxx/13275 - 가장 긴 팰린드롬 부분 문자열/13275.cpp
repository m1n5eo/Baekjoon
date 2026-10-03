#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solution() {
    string temp, word;
    cin >> temp;
    for(char t : temp) {
        word += '#';
        word += t;
    }
    word += '#';
    
    int n = word.size(), p, r = -1, ret = 0;
    vector<int> res(n, 0);
    for(int i = 0; i < n; i++) {
        if(r < i) {
            p = r = i;
            while(r < n && r <= 2*p && word[r] == word[2*p-r]) r += 1;
            r -= 1;
            res[i] = r-p;
        }
        else {
            int j = 2*p-i;
            if(res[j] < r-i) res[i] = res[j];
            else if(res[j] > r-i) res[i] = r-i;
            else {
                p = i;
                while(r < n && r <= 2*p && word[r] == word[2*p-r]) r += 1;
                r -= 1;
                res[i] = r-p;
            }
        }
        ret = max(ret, res[i]);
    }
    return ret;
}

int main() {
    FASTIO
    cout << solution();
}