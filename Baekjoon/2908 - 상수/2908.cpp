#include <bits/stdc++.h>
using namespace std;

int main() {
    int su1, su2;
    scanf("%d %d", &su1, &su2);
    int num1 = su1%10*100 + su1/10%10*10 + su1/100;
    int num2 = su2%10*100 + su2/10%10*10 + su2/100;
    if(num1 > num2) printf("%d", num1);
    else printf("%d", num2);
}
