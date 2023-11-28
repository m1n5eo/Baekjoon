#include <string>
using namespace std;

string ydhms(int num, int second) {
  string rtn;
  if(num == 0) rtn.append(" year");
  else if(num == 1) rtn.append(" day");
  else if(num == 2) rtn.append(" hour");
  else if(num == 3) rtn.append(" minute");
  else if(num == 4) rtn.append(" second");
  if(second != 1) rtn.append("s");
  return rtn;
}

string format_duration(int seconds) {
  int cnt = 0, arr[5] = {0,0,0,0,0};
  string str = "";
  arr[0] = seconds/31536000; seconds = seconds%31536000;
  arr[1] = seconds/86400; seconds = seconds%86400;
  arr[2] = seconds/3600; seconds = seconds%3600;
  arr[3] = seconds/60; seconds = seconds%60;
  arr[4] = seconds;
  for(int i = 0; i < 5; i++) {
    if(arr[i] != 0) cnt = cnt + 1;
  }
  if(cnt == 0) return "now";
  int sw = 0;
  for(int i = 0; i < 5; i++) {
    if(arr[i]) {
      str.append(to_string(arr[i]));
      str.append(ydhms(i, arr[i]));
      if(sw < cnt-2) {
        str.append(", ");
        sw++;
      }
      else if(sw == cnt-2) {
        str.append(" and ");
        sw++;
      }
    }
  }
  return str;
}