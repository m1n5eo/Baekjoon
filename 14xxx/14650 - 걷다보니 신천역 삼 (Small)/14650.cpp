#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, result;

void bruteforcing(int cnt, string now) {
    if(cnt == n) {
        if(stoi(now)%3 == 0) result += 1;
        return;
    }

    for(char i = '0'; i <= '2'; i++) {
        if(cnt == 0 && i == '0') continue;
        bruteforcing(cnt+1, now+i);
    }
}

int main() {
    FASTIO
    
    cin >> n;

    bruteforcing(0, "");

    cout << result;
}