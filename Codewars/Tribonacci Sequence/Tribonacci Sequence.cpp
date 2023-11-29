#include <vector>
using namespace std;

vector<int> tribonacci(vector<int> signature, int n) {
  vector<int> result;
  for(int i = 0; i < n; i++) {
    if(i < 3) result.push_back(signature[i]);
    else result.push_back(result[i-3]+result[i-2]+result[i-1]);
  }
  return result;
}