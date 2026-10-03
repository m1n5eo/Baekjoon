#include <bits/stdc++.h>
using namespace std;

int main() {
    int downPerson, upPerson, nowPerson = 0, maxPerson = -1234567890;
    for(int i = 0; i < 4; i++) {
        scanf("%d %d", &downPerson, &upPerson);
        nowPerson += upPerson-downPerson;
        maxPerson = max(maxPerson, nowPerson);
    }
    printf("%d", maxPerson);
}
