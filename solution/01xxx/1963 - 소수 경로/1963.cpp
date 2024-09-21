#include <iostream>
#include <queue>
using namespace std;

int change_num(int n, int jari, int what) {
    int temp = 1;
    for(int i = 0; i < jari-1; i++) {
        temp *= 10;
    }

    return n/(temp*10)*(temp*10) + what*temp + n%temp;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t, prime[11111] = {2, 2, };

    for(int i = 2; i < 11111; i++) {
        if(prime[i] == 0) {
            prime[i] = 1;
            for(int j = i*2; j < 11111; j+=i) {
                prime[j] = 2;
            }
        }
    }
    
    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        int num1, num2, stop_point = 0;
        bool visited[11111];
        queue<pair<int, int>> q;

        for(int i = 0; i < 11111; i++) {
            visited[i] = false;
        }

        cin >> num1 >> num2;

        if(num1 == num2) {
            cout << "0\n";
            continue;
        }

        visited[num1] = true;
        q.push({num1, 0});

        while(q.size() && stop_point == 0) {
            int num = q.front().first;
            int cnt = q.front().second;

            q.pop();

            // cout << num << " " << cnt << "\n";

            for(int i = 1; i <= 4 && stop_point == 0; i++) {
                for(int j = 0; j < 10 && stop_point == 0; j++) {
                    if(i == 4 && j == 0) continue;

                    int next_num = change_num(num, i, j);

                    if(prime[next_num] == 2) continue;
                    else if(visited[next_num] == true) continue;

                    visited[next_num] = true;

                    if(next_num == num2) {
                        stop_point = 1;

                        cout << cnt+1 << "\n";
                        break;
                    }
                    else {
                        q.push({next_num, cnt+1});
                    }
                }
            }
        }
        
        if(stop_point == 0 && q.size() == 0) {
            cout << "Impossible\n";
        }
    }
}