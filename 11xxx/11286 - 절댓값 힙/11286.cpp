#include <bits/stdc++.h>
using namespace std;

int n, k;
int heapArr[100001], heapIdx = 0;

int heapPop() {
    if(heapIdx == 0) return 0;

    int result = heapArr[1];
    heapArr[1] = heapArr[heapIdx--];

    int child, parent = 1;
    while(1) {
        child = parent*2;
        if(child+1 <= heapIdx) {
            if(abs(heapArr[child]) > abs(heapArr[child+1])) child++;
            else if(abs(heapArr[child]) == abs(heapArr[child+1]) && heapArr[child] > heapArr[child+1]) child++;
        }
        //if(child+1 <= heapIdx && heapArr[child] < heapArr[child+1]) child++;
        if(child > heapIdx || abs(heapArr[child]) > abs(heapArr[parent])) break;
        if(abs(heapArr[child]) == abs(heapArr[parent]) && heapArr[child] > heapArr[parent]) break;
        swap(heapArr[child], heapArr[parent]);
        parent = child;
    }
    return result;
}

void heapPush(int data) {
    int idx = ++heapIdx;
    heapArr[idx] = data;
    while(idx != 1 && abs(data) <= abs(heapArr[idx/2])) {
        if(abs(data) < abs(heapArr[idx/2])) swap(heapArr[idx], heapArr[idx/2]);
        else if(abs(data) == abs(heapArr[idx/2]) && data < heapArr[idx/2]) swap(heapArr[idx], heapArr[idx/2]);
        else break;
        idx = idx/2;
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k != 0) heapPush(k);
        else if(k == 0) printf("%d\n", heapPop());
        /*for(int i = 0; i <= 10; i++) printf("%d ", heapArr[i]);
        printf("\n");*/
    }
}
