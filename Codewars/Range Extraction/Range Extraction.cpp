#include <string>
#include <vector>
using namespace std;

string range_extraction(vector<int> args) {
  int start = 0, end = 0;
  string ans;
  for(int i = 0; i < args.size(); i++) {
    if(args[i]+1 != args[i+1]) {
      if(start+1 == end) {
        ans.append(to_string(args[start]));
        ans.append(",");
        ans.append(to_string(args[end]));
        ans.append(",");
        start = i+1, end = i+1;
      }
      else if(start != end) {
        ans.append(to_string(args[start]));
        ans.append("-");
        ans.append(to_string(args[end]));
        ans.append(",");
        start = i+1; end = i+1;
      }
      else {
        ans.append(to_string(args[start]));
        ans.append(",");
        start = i+1, end = i+1;
      }
    }
    else {
      end = i+1;
    }
  }
  ans.resize(ans.size()-1);
  return ans;
}