#include <bits/stdc++.h>

using namespace std;

string solution(int n, int t, int m, int p) {
  string answer = "";
  vector<char> str(1, '0');
  int i = 1;
  while ((int)str.size() < t * m) {
    // 진수 변환
    string s;
    int k = i;
    while (k > 0) {
      int r = k % n;
      k /= n;
      if (r >= 10)
        s.push_back('A' + r - 10);
      else
        s.push_back('0' + r);
    }
    reverse(s.begin(), s.end());

    // 쪼개서 str에 넣기
    for (char c : s)
      str.push_back(c);
    i++;
  }
  for (int j = 0; j < (int)str.size(); j++) {
    if (j % m == (p - 1)) answer.push_back(str[j]);
    if ((int)answer.size() == t) break;
  }
  return answer;
}