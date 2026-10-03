#include <iostream>
using namespace std;

int n, m, t, airX, arr[55][55];

void airCleanerUp() {
    int ii = airX, jj = 1, sw = 0, temp, imsi;
    temp = arr[ii][jj];
    arr[ii][jj] = 0;
    while(true) {
        if(sw == 0) {
            if(jj+1 < m) {
                jj = jj+1;
            }
            else {
                ii = ii-1;
                sw = 1;
            }
        }
        else if(sw == 1) {
            if(ii-1 >= 0) {
                ii = ii-1;
            }
            else {
                jj = jj-1;
                sw = 2;
            }
        }
        else if(sw == 2) {
            if(jj-1 >= 0) {
                jj = jj-1;
            }
            else {
                ii = ii+1;
                sw = 3;
            }
        }
        else if(sw == 3) {
            if(ii+1 < n) {
                ii = ii+1;
            }
            else {
                jj = jj+1;
                sw = 0;
            }
        }

        if(arr[ii][jj] == -1) {
            break;
        }

        imsi = arr[ii][jj];
        arr[ii][jj] = temp;
        temp = imsi;
    }
}

void airCleanerDown() {
    int ii = airX+1, jj = 1, sw = 0, temp, imsi;
    temp = arr[ii][jj];
    arr[ii][jj] = 0;
    while(true) {
        if(sw == 0) {
            if(jj+1 < m) {
                jj = jj+1;
            }
            else {
                ii = ii+1;
                sw = 1;
            }
        }
        else if(sw == 1) {
            if(ii+1 < n) {
                ii = ii+1;
            }
            else {
                jj = jj-1;
                sw = 2;
            }
        }
        else if(sw == 2) {
            if(jj-1 >= 0) {
                jj = jj-1;
            }
            else {
                ii = ii-1;
                sw = 3;
            }
        }
        else if(sw == 3) {
            if(ii-1 >= 0) {
                ii = ii-1;
            }
            else {
                jj = jj+1;
                sw = 0;
            }
        }

        if(arr[ii][jj] == -1) {
            break;
        }

        imsi = arr[ii][jj];
        arr[ii][jj] = temp;
        temp = imsi;
    }
}

void airCleaner() {
    airCleanerUp();
    airCleanerDown();
}

void spread() {
    int temp[55][55] = {0, };
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int cnt = 0;
            if(arr[i][j] != -1 && arr[i][j] != 0) {
                if(i-1 >= 0 && arr[i-1][j] != -1) {
                    temp[i-1][j] += arr[i][j]/5;
                    cnt++;
                }
                if(j-1 >= 0 && arr[i][j-1] != -1) {
                    temp[i][j-1] += arr[i][j]/5;
                    cnt++;
                }
                if(i+1 < n && arr[i+1][j] != -1) {
                    temp[i+1][j] += arr[i][j]/5;
                    cnt++;
                }
                if(j+1 < m && arr[i][j+1] != -1) {
                    temp[i][j+1] += arr[i][j]/5;
                    cnt++;
                }
                temp[i][j] += arr[i][j] - (arr[i][j]/5)*cnt;
            }
            else if(arr[i][j] == -1) {
                temp[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

int main() {
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == -1) airX = i-1;
        }
    }

    for(int i = 0; i < t; i++) {
        spread();
        airCleaner();
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum += arr[i][j];
        }
    }
    cout << sum+2;
}