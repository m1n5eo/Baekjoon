#include <stdio.h>
#include <string.h>

int arr[27];
char ch[1000001];

int main() {
    scanf("%s", ch);
    int len = strlen(ch);
    for(int i = 0; i < len; i++) {
        if(65 <= ch[i] && ch[i] <= 90) {
            ch[i] = ch[i]+32;
        }
        arr[ch[i]-97]++;
    }
    int maxx = -1234567890, MaxIdx;
    for(int i = 0; i < 26; i++) {
        if(maxx < arr[i]) {
            maxx = arr[i];
            MaxIdx = i;
        }
    }
    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(arr[i] == maxx) cnt++;
    }
    if(cnt == 1) printf("%c", MaxIdx+65);
    else printf("?");
}