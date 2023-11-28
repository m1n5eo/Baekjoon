#include <vector>
using namespace std;

vector<int> maps(const vector<int> & values) {
  vector<int> ans;
  
  for(int i = 0; i < values.size(); i++) ans.push_back(values[i]*2);
  return ans;
}