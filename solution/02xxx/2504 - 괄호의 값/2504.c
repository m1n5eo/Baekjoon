#include <stdio.h>
#include <string.h>

int sum, idx = -1, temp = 1;
char stack[33], str[33];

char top() {return stack[idx];}
void push(char a) {stack[++idx] = a; return;}
void pop() {stack[idx--] = 0; return;}
int empty() {if(idx < 0) return 1; else return 0;}

int main() {
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') push('(');
        else if(str[i] == '[') push('[');
        else if(str[i] == ')' && !empty() && top() == '(') pop();
        else if(str[i] == ']' && !empty() && top() == '[') pop();
        else {
            printf("%d", sum);
            return 0;
        }
    }
    if(!empty()) {
        printf("0");
        return 0;
    }
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') {
            temp *= 2;
            push('(');
            if(i+1 < len && str[i+1] == ')') {
                sum += temp;
                temp /= 2;
                pop();
                i++;
            }
        }
        else if(str[i] == '[') {
            temp *= 3;
            push('[');
            if(i+1 < len && str[i+1] == ']') {
                sum += temp;
                temp /= 3;
                pop();
                i++;
            }
        }
        else if(str[i] == ')') {
            pop();
            temp /= 2;
        }
        else if(str[i] == ']') {
            pop();
            temp /= 3;
        }
    }
    printf("%d", sum);
}