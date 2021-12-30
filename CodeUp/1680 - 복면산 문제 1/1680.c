#include <stdio.h>

int main() {
    for(int s = 0; s <= 9; s++) {
        for(int o = 0; o <= 9; o++) {
            for(int t = 0; t <= 9; t++) {
                if(s*10 + o + s*10 + o == t*100 + o*10 + o && s != o && o != t && t != s) {
                    printf("%d%d+%d%d=%d%d%d", s, o, s, o, t, o, o);
                }
            }
        }
    }
}