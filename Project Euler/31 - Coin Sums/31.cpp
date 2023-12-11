#include <iostream>
using namespace std;

int main() {
    int cnt = 0;
    for(int a = 0; a <= 200/100; a++) {
        int aa = a*100;
        for(int b = 0; b <= 200/50; b++) {
            int bb = b*50;
            for(int c = 0; c <= 200/20; c++) {
                int cc = c*20;
                for(int d = 0; d <= 200/10; d++) {
                    int dd = d*10;
                    for(int e = 0; e <= 200/5; e++) {
                        int ee = e*5;
                        for(int f = 0; f <= 200/2; f++) {
                            int ff = f*2;
                            for(int g = 0; g <= 200/1; g++) {
                                int gg = g*1;
                                if(aa+bb+cc+dd+ee+ff+gg == 200) {
                                    // cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << "\n";
                                    cnt += 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << cnt+1;
}