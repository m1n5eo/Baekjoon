#include <bits/stdc++.h>
using namespace std;

struct data {
    int country, student, score;
};

bool compare(const data& a, const data& b) {
    return a.score > b.score;
}

int main() {
    struct data arr[101];

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].country, &arr[i].student, &arr[i].score);
    }
    sort(arr, arr+n, compare);

    int cnt = 0;
    while(1) {
        if(arr[0].country == arr[1].country && arr[1].country == arr[cnt].country && cnt > 1) {
            cnt++;
            continue;
        }
        printf("%d %d\n", arr[cnt].country, arr[cnt].student);
        if(cnt > 1) break;
        cnt++;
    }
}