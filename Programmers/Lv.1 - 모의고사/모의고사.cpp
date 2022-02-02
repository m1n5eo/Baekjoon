#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int student[3][11111];
    for(int i = 0; i < 3; i++) {
        if(i == 0) {
            for(int j = 0; j < 10000; j+=5) {
                student[i][j] = 1; student[i][j+1] = 2; student[i][j+2] = 3; student[i][j+3] = 4; student[i][j+4] = 5;
            }
        }
        else if(i == 1) {
            for(int j = 0; j < 10000; j+=8) {
                student[i][j] = 2; student[i][j+1] = 1; student[i][j+2] = 2; student[i][j+3] = 3; student[i][j+4] = 2; student[i][j+5] = 4; student[i][j+6] = 2; student[i][j+7] = 5;
            }
        }
        else if(i == 2) {
            for(int j = 0; j < 10000; j+=10) {
                student[i][j] = 3; student[i][j+1] = 3; student[i][j+2] = 1; student[i][j+3] = 1; student[i][j+4] = 2; student[i][j+5] = 2; student[i][j+6] = 4; student[i][j+7] = 4; student[i][j+8] = 5; student[i][j+9] = 5;
            }
        }
    }
    vector<int> count(3);
    for(int i = 0; i < answers.size(); i++) {
        if(student[0][i] == answers[i]) count[0]++;
        if(student[1][i] == answers[i]) count[1]++;
        if(student[2][i] == answers[i]) count[2]++;
    }
    int max_count = 0;
    for(int i = 0; i < 3; i++) {
        if(count[i] > max_count) max_count = count[i];
    }
    for(int i = 0; i < 3; i++) {
        if(count[i] == max_count) answer.push_back(i+1);
    }
    return answer;
}