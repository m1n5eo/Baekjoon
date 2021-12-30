#include <stdio.h>

int main() {
    int i = 0;
    char english[202];
    gets(english);
    while(english[i] != '\0') {
        if(english[i] >= 48 && english[i] <= 57) {
            if(english[i] == 48) printf("zero");
            else if(english[i] == 49) printf("one");
            else if(english[i] == 50) printf("two");
            else if(english[i] == 51) printf("three");
            else if(english[i] == 52) printf("four");
            else if(english[i] == 53) printf("five");
            else if(english[i] == 54) printf("six");
            else if(english[i] == 55) printf("seven");
            else if(english[i] == 56) printf("eight");
            else if(english[i] == 57) printf("nine");
        }
        else if(i == 0 && english[i] >= 'a' && english[i] <= 'z') printf("%c", english[i] - 32);
        else if(i != 0 && (english[i] >= 'A' && english[i] <= 'Z') && ((english[i-1] >= 32 && english[i-1] <= 47) || (english[i-1] >= 58 && english[i-1] <= 64) || (english[i-1] >= 91 && english[i-1] <= 96) || (english[i-1] >= 123 && english[i-1] <= 127)) && ((english[i+1] >= 32 && english[i+1] <= 47) || (english[i+1] >= 58 && english[i+1] <= 64) || (english[i+1] >= 91 && english[i+1] <= 96) || (english[i+1] >= 123 && english[i+1] <= 127))) printf("%c", english[i]);
        else if(i != 0 && (english[i] >= 'a' && english[i] <= 'z') && ((english[i-1] >= 32 && english[i-1] <= 47) || (english[i-1] >= 58 && english[i-1] <= 64) || (english[i-1] >= 91 && english[i-1] <= 96) || (english[i-1] >= 123 && english[i-1] <= 127)) && ((english[i+1] >= 32 && english[i+1] <= 47) || (english[i+1] >= 58 && english[i+1] <= 64) || (english[i+1] >= 91 && english[i+1] <= 96) || (english[i+1] >= 123 && english[i+1] <= 127))) printf("%c", english[i] - 32);
        else if(i != 0 && english[i] >= 'A' && english[i] <= 'Z') printf("%c", english[i] + 32);
        else printf("%c", english[i]);

        i = i + 1;
    }
}