#include <bits/stdc++.h>
using namespace std;

int main() {
    int SecretCode[256];
    char ch, input[256], PhoneNumber[256];
    scanf("%s", input);
    for(int i = 0; i < 10; i++) SecretCode[input[i]] = i;
    scanf("%c", &ch);
    scanf("%[^\n]s", PhoneNumber);

    int len = strlen(PhoneNumber);
    for(int i = 0; i < len; i++) {
        if(PhoneNumber[i] == ' ') printf(" ");
        else printf("%d", SecretCode[PhoneNumber[i]]);
    }
}