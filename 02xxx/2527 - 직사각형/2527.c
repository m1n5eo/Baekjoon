#include <stdio.h>

#define true 1
#define false 0

struct pair {
    int first, second;
};

struct pair rec[2][2], rec2[2][2];

int check_c() {
    if(rec[0][1].first == rec[1][0].first && rec[0][1].second == rec[1][0].second) return true;
    else if(rec[0][1].first == rec[1][0].first && rec[0][0].second == rec[1][1].second) return true;
    
    return false;
}

int check_b() {
    if(rec[0][1].first == rec[1][0].first) {
        if(rec[0][0].second <= rec[1][0].second && rec[1][0].second <= rec[0][1].second) return true;
        else if(rec[0][0].second <= rec[1][1].second && rec[1][1].second <= rec[0][1].second) return true;
        else if(rec[0][0].second >= rec[1][0].second && rec[0][1].second <= rec[1][1].second) return true;
    }
    else if(rec[0][1].second == rec[1][0].second || rec[0][0].second == rec[1][1].second) {
        if(rec[0][0].first <= rec[1][0].first && rec[1][0].first <= rec[0][1].first) return true;
        else if(rec[0][0].first <= rec[1][1].first && rec[1][1].first <= rec[0][1].first) return true;
        else if(rec[0][0].first >= rec[1][0].first && rec[0][1].first <= rec[1][0].first) return true;
    }

    return false;
}

int check_d() {
    if(rec[0][1].second < rec[1][0].second) return true;
    else if(rec[1][1].second < rec[0][0].second) return true;
    else if(rec[0][1].first < rec[1][0].first) return true;

    return false;
}

int main() {
    for(int testcase = 0; testcase < 4; testcase++) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                scanf("%d %d", &rec[i][j].first, &rec[i][j].second);
                rec2[i][j] = rec[i][j];
            }
        }

        if(rec[0][0].first > rec[1][0].first) {
            int temp;

            temp = rec[0][0].first; rec[0][0].first = rec[1][0].first; rec[1][0].first = temp;
            temp = rec[0][0].second; rec[0][0].second = rec[1][0].second; rec[1][0].second = temp;
            temp = rec[0][1].first; rec[0][1].first = rec[1][1].first; rec[1][1].first = temp;
            temp = rec[0][1].second; rec[0][1].second = rec[1][1].second; rec[1][1].second = temp;
        }

        if(check_c() == true) printf("c\n");
        else if(check_b() == true) printf("b\n");
        else if(check_d() == true) printf("d\n");
        else printf("a\n");
    }

    return 0;
}