#include <stdio.h>
#include <stdlib.h>

#define MAX 555555

int n, k, count = 0, result = -1;

void merge(int* array, int left, int mid, int right) {
    int i = left, j = mid+1, t = 1;
    int* temp = (int*)malloc(sizeof(int) * (right+2));

    while(i <= mid && j <= right) {
        if(array[i] <= array[j]) temp[t++] = array[i++];
        else temp[t++] = array[j++];
    }

    while(i <= mid) temp[t++] = array[i++];
    while(j <= right) temp[t++] = array[j++];

    i = left, t = 1;
    while(i <= right) {
        array[i++] = temp[t++];
        count += 1;

        if(count == k) {
            result = temp[t-1];
            break;
        }
    }

    free(temp);
    return;
}

void merge_sort(int* array, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        
        merge_sort(array, left, mid);
        merge_sort(array, mid+1, right);
        merge(array, left, mid, right);
    }
}

int main() {
    int* array = (int*)malloc(sizeof(int) * MAX);

    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    merge_sort(array, 0, n-1);
    printf("%d", result);

    free(array);
}