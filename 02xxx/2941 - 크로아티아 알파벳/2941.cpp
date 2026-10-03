#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[101];
    scanf("%s", str);
    int len = strlen(str), cnt = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] == 'c' && str[i+1] == '=') {cnt++;i++;}
        else if(str[i] == 'c' && str[i+1] == '-') {cnt++;i++;}
        else if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=') {cnt++;i+=2;}
        else if(str[i] == 'd' && str[i+1] == '-') {cnt++;i++;}
        else if(str[i] == 'l' && str[i+1] == 'j') {cnt++;i++;}
        else if(str[i] == 'n' && str[i+1] == 'j') {cnt++;i++;}
        else if(str[i] == 's' && str[i+1] == '=') {cnt++;i++;}
        else if(str[i] == 'z' && str[i+1] == '=') {cnt++;i++;}
        else cnt++;
    }
    printf("%d", cnt);
}
