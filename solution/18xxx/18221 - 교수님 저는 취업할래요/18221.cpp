#include <iostream>
using namespace std;

struct point {
    int x, y;
};

int n, cnt;
int room[1111][1111];
point student, professor;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> room[i][j];

            if(room[i][j] == 2) {
                student.x = i;
                student.y = j;
            }
            else if(room[i][j] == 5) {
                professor.x = i;
                professor.y = j;
            }
        }
    }
    
    int dist = (student.x-professor.x)*(student.x-professor.x) + (student.y-professor.y)*(student.y-professor.y);

    int max_x = max(student.x, professor.x), max_y = max(student.y, professor.y);
    int min_x = min(student.x, professor.x), min_y = min(student.y, professor.y);

    for(int i = min_x; i <= max_x; i++) {
        for(int j = min_y; j <= max_y; j++) {
            if(room[i][j] == 1) cnt += 1;
        }
    }
    
    if(dist >= 25 && cnt >= 3) cout << 1;
    else cout << 0;

    return 0;
}