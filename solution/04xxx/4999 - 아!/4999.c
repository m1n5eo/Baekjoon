#include <stdio.h>

int main() {
    char JaeHawn[1111], doctor[1111];
    scanf("%s %s", JaeHawn, doctor);
    int JaeHawn_len = strlen(JaeHawn), doctor_len = strlen(doctor);
    if(JaeHawn_len < doctor_len) printf("no");
    else printf("go");
}