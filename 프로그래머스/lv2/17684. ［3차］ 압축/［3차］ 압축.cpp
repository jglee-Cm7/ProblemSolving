#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string msg) {
  vector<int> answer;
  map<string, int> d;
  int i = 1;
  for (char c = 'A'; c <= 'Z'; c++) {
    string s(1, c);
    d[s] = i++;
  }

  int idx = 0;
  while (idx < (int)msg.length()) {
    string w;
    w.push_back(msg[idx++]);
    int k = 0;
    while (d.find(w) != d.end()) {
      k = d[w];
      w.push_back(msg[idx++]);
    }
    idx--;
    answer.push_back(k);
    d.insert({w, i++});
  }
  return answer;
}