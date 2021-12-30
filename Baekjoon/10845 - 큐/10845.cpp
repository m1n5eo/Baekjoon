#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    string str;
    queue <int> q;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str == "push") {
            scanf("%d", &a);
            q.push(a);
        }
        else if(str == "pop") {
            if(q.empty() == 1) {
                printf("%d\n", -1);
                continue;
            }
            printf("%d\n", q.front());
            q.pop();
        }
        else if(str == "size") printf("%d\n", q.size());
        else if(str == "empty") printf("%d\n", q.empty());
        else if(str == "front") {
            if(q.empty() == 1) {
                printf("%d\n", -1);
                continue;
            }
            printf("%d\n", q.front());
        }
        else if(str == "back") {
            if(q.empty() == 1) {
                printf("%d\n", -1);
                continue;
            }
            printf("%d\n", q.back());
        }
    }
}
