#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int execute(int num, int idx) {
    if(idx == 0) {
        if(num*2 > 9999) return (num*2)%10000;
        else return num*2;
    }
    else if(idx == 1) {
        if(num-1 < 0) return 9999;
        else return num-1;
    }
    else if(idx == 2) {
        if(num > 999) return (num%1000*10)+(num/1000);
        else return num*10;
    }
    else if(idx == 3) {
        return (num%10*1000)+(num/10);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;

    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        int n, final_n;
        bool visited[11111] = {false, };
        queue<pair<int, string>> q;
        
        cin >> n >> final_n;

        q.push({n, ""});
        visited[n] = true;

        while(q.size()) {
            int now = q.front().first;
            string str = q.front().second;
            
            q.pop();

            if(now == final_n) {
                cout << str << "\n";
                break;
            }

            for(int k = 0; k < 4; k++) {
                int temp = execute(now, k);

                if(visited[temp] == true) continue;

                if(k == 0) q.push({temp, str+"D"});
                else if(k == 1) q.push({temp, str+"S"});
                else if(k == 2) q.push({temp, str+"L"});
                else if(k == 3) q.push({temp, str+"R"});

                visited[temp] = true;
            }
        }
    }
}