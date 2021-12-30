#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    char ch[10001][11];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", &ch[i]);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(strcmp(ch[i], ch[j]) >0) {
                swap(ch[i], ch[j]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%s\n", ch[i]);
    }
}