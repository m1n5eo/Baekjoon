#include <stdio.h>

int main() {
    double pasta, juice, pastamin = 30000, juicemin = 30000;
    for(int i = 0; i < 3; i++) {
        scanf("%lf", &pasta);
        if(pastamin > pasta) {
            pastamin = pasta;
        }
    }
    for(int i = 0; i < 2; i++) {
        scanf("%lf", &juice);
        if(juicemin > juice) {
            juicemin = juice;
        }
    }
    printf("%.1lf", (pastamin+juicemin)+((pastamin+juicemin)*10/100));
}