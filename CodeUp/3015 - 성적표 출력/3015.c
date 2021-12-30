#include <stdio.h>
#include <algorithm>

using namespace std;

struct data {
    char name[11];
    int score, su;
}arr[101];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s %d", &arr[i].name, &arr[i].score);
        arr[i].su = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = n-1; j >= i; j--) {
            if(arr[i].score < arr[j].score) {
                swap(arr[i], arr[j]);
            }
            else if(arr[i].score == arr[j].score && arr[i].su > arr[j].su) {
                swap(arr[i], arr[j]);
            }
        }
    }

    for(int i = 0; i < m; i++) {
        printf("%s\n", arr[i].name);
    }
}