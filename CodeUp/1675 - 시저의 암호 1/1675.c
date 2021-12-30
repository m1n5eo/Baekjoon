#include <stdio.h>
 
int main() {
    int i = 0;
    char ch[1000] = {};
    gets(ch);
    while(1) {
        if(ch[i] == '\0' && ch[i+1] == '\0') break;
        else if (ch[i] == ' ') ch[i] = ' ';
        else if (ch[i] == 'a' || ch[i] == 'b' || ch[i] == 'c') ch[i] = ch[i] + 23;
        else ch[i] = ch[i] - 3;
        i = i + 1;
    }
    puts(ch);
}