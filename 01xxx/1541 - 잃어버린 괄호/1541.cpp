#include <bits/stdc++.h>
using namespace std;

int main() {
    int sw = 0, su = 0, sum = 0;
    char str[55];
    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++) {
        if('0' <= str[i] && str[i] <= '9') su = su*10+(str[i]-'0');
        else if(str[i] == '+') {
            if(sw == 0) {
                sum += su;
                su = 0; sw = 0;
            }
            else if(sw == 1) {
                sum -= su;
                su = 0; sw = 1;
            }
        }
        else if(str[i] == '-') {
            if(sw == 0) {
                sum += su;
                su = 0; sw = 1;
            }
            else if(sw == 1) {
                sum -= su;
                su = 0; sw = 1;
            }
        }
    }
    if(sw) sum -= su;
    else sum += su;
    printf("%d", sum);
}
