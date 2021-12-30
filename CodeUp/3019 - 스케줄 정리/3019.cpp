#include <bits/stdc++.h>
using namespace std;

struct data {
    char name[111];
    int year, month, day, len;
};

bool compare(const data& a, const data& b) {
    if(a.year != b.year) return a.year < b.year;
    else {
        if(a.month != b.month) return a.month < b.month;
        else {
            if(a.day != b.day) return a.day < b.day;
            else {
                if(a.len < b.len) {
                   for(int i = 0; i < a.len; i++) {
                        if(a.name[i] < b.name[i]) return 1;
                        else if(a.name[i] > b.name[i]) return 0;
                   }
                   return 1;
                }
                else {
                   for(int i = 0; i < b.len; i++) {
                        if(a.name[i] < b.name[i]) return 1;
                        else if(a.name[i] > b.name[i]) return 0;
                   }
                   return 0;
                }
            }
        }
    }
}

int main() {
    int n;
    struct data arr[101];

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s %d %d %d", arr[i].name, &arr[i].year, &arr[i].month, &arr[i].day);
        arr[i].len = strlen(arr[i].name);
    }
    sort(arr, arr+n, compare);
    for(int i = 0; i < n; i++) printf("%s\n", arr[i].name);
}