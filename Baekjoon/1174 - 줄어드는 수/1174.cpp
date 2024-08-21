#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int n, cnt = 1;
priority_queue<lli, vector<lli>, greater<lli>> pq;

void backtracking(string a) {
    if(a != "") {
        lli temp = stoll(a);
        pq.push(temp);
    }

    if(a == "") {
        for(char i = '0'; i <= '9'; i++) {
            backtracking(a+i);
        }
    }
    else {
        for(char i = a[a.size()-1]-1; i >= '0'; i--) {
            backtracking(a+i);
        }
    }
}

int main() {
    FASTIO

    cin >> n;

    backtracking("");

    while(pq.size()) {
        if(cnt == n) {
            cout << pq.top();
            exit(0);
        }

        pq.pop();
        cnt += 1;
    }

    cout << -1;
}