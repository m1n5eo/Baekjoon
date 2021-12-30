#include <bits/stdc++.h>
using namespace std;

int main() {
    int downPerson, upPerson, sum = 0, maxPerson = -1234567890;
    for(int i = 0; i < 10; i++) {
        scanf("%d %d", &downPerson, &upPerson);
        sum -= downPerson;
        maxPerson = max(maxPerson, sum);
        sum = sum+upPerson>10000? 10000:sum+upPerson;
        maxPerson = max(maxPerson, sum);
    }
    printf("%d", maxPerson);
}
