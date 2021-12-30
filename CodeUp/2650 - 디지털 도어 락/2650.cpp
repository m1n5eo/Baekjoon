#include <bits/stdc++.h>
using namespace std;

int main() {
    int key[3], master_key, min_key = 1234567890;
    for(int i = 0; i < 3; i++) {
        scanf("%d", &key[i]);
        min_key = min(min_key, key[i]);
    }
    for(int i = min_key; i >= 1; i--) {
        if(!(key[0]%i) && !(key[1]%i) && !(key[2]%i)) {
            master_key = i;
            break;
        }
    }
    printf("%d", master_key);
}