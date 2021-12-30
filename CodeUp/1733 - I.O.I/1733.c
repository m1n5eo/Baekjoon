#include <stdio.h>
 
int main() {
    char ch[2001];
    
    gets(ch);
    if(ch[0] == 'I' && ch[1] == 'O' && ch[2] == 'I' && ch[3] == '\0') printf("IOI is the International Olympiad in Informatics.");
    else printf("I don't care.");
}