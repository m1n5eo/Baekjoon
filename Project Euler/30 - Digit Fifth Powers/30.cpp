#include <iostream>
using namespace std;

int fiveSquared(int num) {
    int rtn = 1;
    for(int i = 0; i < 5; i++) {
        rtn = rtn*num;
    }
    return rtn;
}

int main() {
    int sum = 0;
    for(int a = 0; a < 10; a++) {
        int aa = fiveSquared(a);
        for(int b = 0; b < 10; b++) {
            int bb = fiveSquared(b);
            for(int c = 0; c < 10; c++) {
                int cc = fiveSquared(c);
                for(int d = 0; d < 10; d++) {
                    int dd = fiveSquared(d);
                    for(int e = 0; e < 10; e++) {
                        int ee = fiveSquared(e);
                        for(int f = 0; f < 10; f++) {
                            int ff = fiveSquared(f);
                            if(a*1+b*10+c*100+d*1000+e*10000+f*100000 == aa+bb+cc+dd+ee+ff) {
                                sum += aa+bb+cc+dd+ee+ff;
                                cout << aa+bb+cc+dd+ee+ff << " ";
                            }
                        }
                    }
                }
            }
        }
    }
    cout << sum-1;
}