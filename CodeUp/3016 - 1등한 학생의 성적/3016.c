#include <stdio.h>
#include <algorithm>

using namespace std;

int n;

struct data {
    char name[20];
    int subject[4], rank[4];
}arr[101];

void input() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", &arr[i].name);
        for(int j = 1; j <= 3; j++) {
            scanf("%d", &arr[i].subject[j]);
            arr[i].rank[j] = 1;
        }
    }
}

int main() {
    input();
    for(int k = 1; k <= 3; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i].subject[k] > arr[j].subject[k]) {
                    arr[j].rank[k] = arr[j].rank[k] + 1;
                }
                else if(arr[i].subject[k] < arr[j].subject[k]) {
                    arr[i].rank[k] = arr[i].rank[k] + 1;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(arr[i].rank[1] == 1) {
            printf("%s %d %d", arr[i].name, arr[i].rank[2], arr[i].rank[3]);
            return 0;
        }
    }
}