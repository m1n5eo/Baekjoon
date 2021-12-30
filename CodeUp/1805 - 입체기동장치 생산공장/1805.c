#include <stdio.h>
#include <algorithm>

using namespace std;

struct data {
    int num, gas;
}arr[101];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].num, &arr[i].gas);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(arr[i].num > arr[j].num) {
                swap(arr[i].num, arr[j].num);
                swap(arr[i].gas, arr[j].gas);
            }
        }
        printf("%d %d\n", arr[i].num, arr[i].gas);
    }
}