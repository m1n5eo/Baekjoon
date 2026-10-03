#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, i;
    scanf("%d %d", &a, &i);
    printf("%d", a*(i-1)+1);
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[8], sortcnt = 0, reversecnt = 0;
    for(int i = 0; i < 8; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < 7; i++) {
        if(arr[i] < arr[i+1]) sortcnt++;
        else if(arr[i] > arr[i+1]) reversecnt++;
    }
    if(sortcnt == 7) printf("ascending");
    else if(reversecnt == 7) printf("descending");
    else printf("mixed");
}
