#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

stack<int> a;
stack<int> b;
stack<int> dap;

int main() {
    int im = 0, len;
    char n, su[102];
    scanf("%s", su);
    len = strlen(su);
    for(int i = 0; i < len; i++) {
        a.push(su[i]-48);
    }

    scanf("%s", su);
    len = strlen(su);
    for(int i = 0; i < len; i++) {
        b.push(su[i]-48);
    }

    while(1) {
        if(a.size() == 0 || b.size() == 0) break;
        if(a.top() + b.top() + im < 10) {
            dap.push(a.top() + b.top() + im);
            im = 0;
            a.pop();
            b.pop();
        }
        else if(a.top() + b.top() + im >= 10) {
            dap.push((a.top() + b.top() + im) % 10);
            im = 1;
            a.pop();
            b.pop();
        }
    }
    while(1) {
        if(a.size() == 0) break;
        if(a.top() + im < 10) {
            dap.push(a.top() + im);
            im = 0;
            a.pop();
        }
        else if(a.top() + im >= 10) {
            dap.push((a.top() + im) % 10);
            im = 1;
            a.pop();
        }
    }
    while(1) {
        if(b.size() == 0) break;
        if(b.top() + im < 10) {
            dap.push(b.top() + im);
            im = 0;
            b.pop();
        }
        else if(b.top() + im >= 10) {
            dap.push((b.top() + im) % 10);
            im = 1;
            b.pop();
        }
    }
    if(im == 1) dap.push(im);
    while(1) {
        if(dap.size() == 0) break;
        printf("%d", dap.top());
        dap.pop();
    }
}