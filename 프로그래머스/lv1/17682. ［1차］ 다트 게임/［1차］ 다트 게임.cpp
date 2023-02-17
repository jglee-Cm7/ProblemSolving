#include <bits/stdc++.h>

using namespace std;

int solution(string dartResult) {
  int answer = 0;
  vector<int> score(4);

  int round = 0;
  int s = 0;
  for (int i = 0; i < dartResult.length(); i++) {
    char c = dartResult[i];
    if (isdigit(c)) {
      if (s != 0)
        s *= 10;
      else
        round++;
      s += c - '0';
    } else {
      if (c == 'S') {
        score[round] = s;
      } else if (c == 'D') {
        score[round] = s * s;
      } else if (c == 'T') {
        score[round] = s * s * s;
      } else if (c == '*') {
        score[round] *= 2;
        score[round - 1] *= 2;
      } else if (c == '#') {
        score[round] = -score[round];
      }
      s = 0;
    }
  }
  for (int sc : score)
    answer += sc;

  return answer;
}