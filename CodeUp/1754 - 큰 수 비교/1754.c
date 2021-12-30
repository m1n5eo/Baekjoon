#include <stdio.h>
#include <string.h>

int main() {
    int len1, len2;
    char ch1[103], ch2[103];
    scanf("%s %s", &ch1, &ch2);

    len1 = strlen(ch1), len2 = strlen(ch2);


    if(len1 < len2) printf("%s %s", ch1, ch2);
    else if(len1 > len2) printf("%s %s", ch2, ch1);
    else if(strcmp(ch1, ch2) < 0) printf("%s %s", ch1, ch2);
    else if(strcmp(ch1, ch2) > 0) printf("%s %s", ch2, ch1);
}