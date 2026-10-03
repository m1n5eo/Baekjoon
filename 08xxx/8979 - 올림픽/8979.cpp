#include <bits/stdc++.h>
using namespace std;

struct Data {
    int idx, gold, silver, bronze, nationRank;
};

int main() {
    struct Data arr[1001];
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &arr[i].idx, &arr[i].gold, &arr[i].silver, &arr[i].bronze);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i].gold > arr[j].gold) arr[i].nationRank++;
            else if(arr[i].gold == arr[j].gold && arr[i].silver > arr[j].silver) arr[i].nationRank++;
            else if(arr[i].gold == arr[j].gold && arr[i].silver == arr[j].silver && arr[i].bronze > arr[j].bronze) arr[i].nationRank++;
            else if(arr[i].gold == arr[j].gold && arr[i].silver == arr[j].silver && arr[i].bronze == arr[j].bronze) arr[i].nationRank++;
        }
        arr[i].nationRank = n-arr[i].nationRank+1;
    }
    for(int i = 0; i < n; i++) {
        if(arr[i].idx == m) printf("%d", arr[i].nationRank);
    }
}
