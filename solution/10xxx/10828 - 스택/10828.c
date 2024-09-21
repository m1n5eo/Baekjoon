#include <stdio.h>
#include <string.h>

int stack[11111] = {-1}, now = 0;

void top() {
    printf("%d\n", stack[now]);
}

void empty() {
    if(now > 0) {
        printf("0\n");
    }
    else {
        printf("1\n");
    }
}

void size() {
    printf("%d\n", now);
}

void pop() {
    printf("%d\n", stack[now]);
    
    if(now != 0) {
        now = now-1;
    }
}

void push(int n) {
    now = now+1;
    stack[now] = n;
}

int main() {
    int n, num;
    char cmd[11];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", cmd);
        
        if(cmd[0] == 'p' && cmd[1] == 'u') {
            scanf(" %d", &num);

            push(num);
        }
        else if(cmd[0] == 'p' && cmd[1] == 'o') {
            pop();
        }
        else if(cmd[0] == 's') {
            size();
        }
        else if(cmd[0] == 'e') {
            empty();
        }
        else if(cmd[0] == 't') {
            top();
        }
    }

    return 0;
}