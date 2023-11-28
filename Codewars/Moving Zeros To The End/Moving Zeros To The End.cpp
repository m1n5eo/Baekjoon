#include <vector>
using namespace std;

vector<int> move_zeroes(const vector<int>& input) {
  vector<int> ans;
  int inputSize = input.size();
  for(int i = 0; i < inputSize; i++) {
    if(input[i] != 0) ans.push_back(input[i]);
  }
  int ansSize = ans.size();
  for(int i = 0; i < inputSize-ansSize; i++) {
    ans.push_back(0);
  }
  return ans;
}