#include <stdio.h>
#include <stack>

using namespace std;

stack<int> s;

int main() {
    int n, m, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        if(!m) s.pop();
        else if(m) s.push(m);
    }
    while(1) {
        if(s.empty() == 1) break;
        sum = sum + s.top();
        s.pop();
    }
    printf("%d", sum);
}