#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum = 0;
    char arr[10001];
    scanf("%s", arr);
    int len = strlen(arr);
    for(int i = 0; i < len; i++) {
        sum = sum + arr[i]-48;
    }

    if(sum%3 == 0) printf("1");
    else printf("0");
}