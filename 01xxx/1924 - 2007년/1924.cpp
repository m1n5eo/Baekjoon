#include <bits/stdc++.h>
using namespace std;

int arr[22] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,};

int main() {
    int x, y, sum = 0;
    scanf("%d %d", &x, &y);
    for(int i = 1; i < x; i++) sum = sum + arr[i];
    sum = sum + y;

    if(sum % 7 == 1) printf("MON");
    else if(sum % 7 == 2) printf("TUE");
    else if(sum % 7 == 3) printf("WED");
    else if(sum % 7 == 4) printf("THU");
    else if(sum % 7 == 5) printf("FRI");
    else if(sum % 7 == 6) printf("SAT");
    else if(sum % 7 == 0) printf("SUN");
}
