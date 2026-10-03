#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 9999999999
#define MAX 11

int n;
char buho[MAX];
bool check[MAX];
string minNUM = to_string(INF), maxNUM = to_string(-INF);

void backtracking(int cnt, string now) {
    if(cnt == n) {
        minNUM = min(minNUM, now);
        maxNUM = max(maxNUM, now);
    }

    for(int i = 0; i < 10; i++) {
        if(check[i] == false) {
            if(buho[cnt] == '<' && now[now.size()-1]-'0' < i) {
                check[i] = true;
                backtracking(cnt+1, now+to_string(i));
                check[i] = false;
            }
            else if(buho[cnt] == '>' && now[now.size()-1]-'0' > i) {
                check[i] = true;
                backtracking(cnt+1, now+to_string(i));
                check[i] = false;
            }
        }
    }
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> buho[i];
    }

    for(int i = 0; i <= 9; i++) {
        check[i] = true;
        backtracking(0, to_string(i));
        check[i] = false;
    }

    cout << maxNUM << "\n" << minNUM;
}