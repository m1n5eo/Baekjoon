#include <iostream>
using namespace std;

int main() {
    int p, v, k;
    cin >> p >> v >> k;

    int lcm, large = max(p+1, v+1);
    for(int i = 1; ; i++) {
        if((large*i)%(p+1) == 0 && (large*i)%(v+1) == 0) {
            lcm = large*i;
            break;
        }
    }
    cout << k-(+k/(v+1)+k/(p+1)-k/lcm) << " " << k/lcm << " " << k/(v+1)-k/lcm << " " << k/(p+1)-k/lcm;
}