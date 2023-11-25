int FindOutlier(std::vector<int> arr) {
  int odd_cnt = 0, even_cnt = 0, sign[111] = {0, };
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] < 0) {
      arr[i] = -arr[i];
      sign[i] = 1;
    }
    if(arr[i]%2 == 0) even_cnt++;
    else odd_cnt++;
  }
  for(int i = 0; i < arr.size(); i++) {
    if(even_cnt == 1 && arr[i]%2 == 0) {
      if(sign[i] == 0) return arr[i];
      else return -arr[i];
    }
    else if(odd_cnt == 1 && arr[i]%2 == 1) {
      if(sign[i] == 0) return arr[i];
      else return -arr[i];
    }
  }
}