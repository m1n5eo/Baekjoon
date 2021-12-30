#include <bits/stdc++.h>
using namespace std;

char ch[222];
long long int a, b, sum;

int main() {
    gets(ch);
    stack <long long int> st;

    for(int i = 0; i < strlen(ch); i++) {
        if(ch[i] == '+' || ch[i] == '-' || ch[i] == '*') {
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            if(ch[i] == '+') sum = a+b;
            else if(ch[i] == '-') sum = a-b;
            else if(ch[i] == '*') sum = a*b;
            st.push(sum);
        }
        else {
            if(ch[i] != ' ') {
                int j;
                long long int k = 0;
                for(j = i; ; j++) {
                    if(ch[j] == ' ') break;
                    k = k*10 + (ch[j]-48);
                }#include <bits/stdc++.h>
using namespace std;

int main() {
    char ch[50003];
    gets(ch);
    stack <char> st;
    int len = strlen(ch);
    if(ch[0] == ')') {
        printf("bad");
        return 0;
    }
    for(int i = 0; i < len; i++) {
        if(ch[i] == '(') st.push(ch[i]);
        else if(st.empty() == 1) continue;
        else if(ch[i] == ')') st.pop();
    }
    if(st.empty() == 1) printf("good");
    else printf("bad");
}
                i = j;
                st.push(k);
            }
        }
    }
    printf("%lld", st.top());
}