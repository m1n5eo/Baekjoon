#include <stdio.h>

int main() {
    int cnt_c = 0, cnt_cc = 0;
    char ch[100];
    gets(ch);
    for (int i = 0; i < 100; i++) {
        if(ch[i] == '\0') break;
        else if(ch[i] == 'c' || ch[i] == 'C') cnt_c = cnt_c + 1;
    }
    for(int i = 0; i < 100; i++) {
        if(ch[i] == '\0') break;
        else if((ch[i] == 'c' && ch[i+1] == 'c') || (ch[i] == 'c' && ch[i+1] == 'C') || (ch[i] == 'C' && ch[i+1] == 'c') || (ch[i] == 'C' && ch[i+1] == 'C')) {
            cnt_cc = cnt_cc + 1;
        }
    }
    printf("%d\n%d", cnt_c, cnt_cc);
}