#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

stack<int> s;

int main() {
    int n, m;
    char a, com[202][22];
    scanf("%d", &n);
    getchar();
    for(int i = 1; i <= n; i++) {
        scanf("%s", &com[i]);
        if(com[i][0] == 'p' && com[i][1] == 'u') {
            scanf("%d", &m);
            getchar();
            getchar();
            s.push(m);
        }
        else if(com[i][0] == 't') {
            if(!s.empty()) printf("%d\n", s.top());
            else if(s.empty()) printf("%d\n", -1);
        }
        else if(com[i][0] == 'p' && com[i][1] == 'o'){
            if(!s.empty()) s.pop();
        }
        else if(com[i][0] == 's') printf("%d\n", s.size());
        else if(com[i][0] == 'e') {
            if(s.empty() == 1) printf("true\n");
            else if(s.empty() == 0) printf("false\n");
        }
    }
}