#include <iostream>
#include <queue>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int main() {
    FASTIO
    
    lli n;
    int q_size, cnt = 0;

    cin >> n;

    if(n == 1) {
        cout << cnt;
        exit(0);
    }

    queue<lli> q;
    map<lli, bool> m;

    q.push(n);
    m.insert({n, true});

    while(q.size()) {
        q_size = q.size();
        cnt += 1;

        for(int _ = 0; _ < q_size; _++) {
            lli x = q.front();
            q.pop();

            if(x%3 == 0 && m.find(x/3) == m.end()) {
                if(x/3 == 1) {
                    cout << cnt;
                    exit(0);
                }

                q.push(x/3);
                m.insert({x/3, true});
            }
            if(x%2 == 0 && m.find(x/2) == m.end()) {
                if(x/2 == 1) {
                    cout << cnt;
                    exit(0);
                }

                q.push(x/2);
                m.insert({x/2, true});
            }
            if(m.find(x-1) == m.end()) {
                if(x-1 == 1) {
                    cout << cnt;
                    exit(0);
                }

                q.push(x-1);
                m.insert({x-1, true});
            }
        }
    }
}