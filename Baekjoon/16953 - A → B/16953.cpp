#include <iostream>
#include <queue>
using namespace std;

int n, m, cnt;
queue<int> q;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    q.push(n);

    while(q.size()) {
        int q_size = q.size();
        cnt += 1;
        
        for(int i = 0; i < q_size; i++) {
            long long int num = q.front();
            q.pop();

            if(num*2 == m || num*10+1 == m) {
                cout << cnt+1;
                return 0;
            }
            if(num*2 < m) {
                q.push(num*2);
            }
            if(num*10+1 < m) {
                q.push(num*10+1);
            }
        }
    }

    cout << -1;
    return 0;
}