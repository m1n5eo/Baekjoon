#include <bits/stdc++.h>
using namespace std;

int main() {
    char S1[22], S2[22], S3[22];
    scanf("%s %s %s", S1, S2, S3);
    int len1 = strlen(S1), len2 = strlen(S2), len3 = strlen(S3);

    if(S1[len1-1] == S2[0] && S2[len2-1] == S3[0] && S3[len3-1] == S1[0]) printf("good");
    else printf("bad");
}