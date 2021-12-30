#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, input[3], MinIdx, MinNum, output, printIdx = -1, printNum = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        MinNum = 1234567890;
        for(int j = 0; j < 3; j++) {
            scanf("%d", &input[j]);
            if(MinNum > input[j]) {
                MinNum = input[j];
                MinIdx = j;
            }
        }
        scanf("%d", &output);
        if(MinNum != output && printIdx == -1) {
            printIdx = i+1;
            printNum = MinNum;
        }
    }
    if(printIdx != -1) printf("%d %d", printIdx, printNum);
    else printf("-1");
}