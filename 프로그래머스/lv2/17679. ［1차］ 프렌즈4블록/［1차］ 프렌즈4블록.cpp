#include <bits/stdc++.h>

using namespace std;


int boom(int n, int m, vector<vector<int>> &b) {
  int count = 0;
  vector<vector<bool>> chk(n, vector<bool>(m, 0));
  vector<int> nb[n];
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      int t = b[i][j];
      if (t == 0) continue;
      if (t == b[i][j + 1] && t == b[i + 1][j] && t == b[i + 1][j + 1]) {
        chk[i][j] = 1;
        chk[i][j + 1] = 1;
        chk[i + 1][j] = 1;
        chk[i + 1][j + 1] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int row = 0;
    for (int j = 0; j < m; j++) {
      if (chk[i][j])
        row++;
      else
        nb[i].push_back(b[i][j]);
    }
    for (int j = 0; j < row; j++)
      nb[i].push_back(0);
    count += row;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      b[i][j] = nb[i][j];
  }

  return count;
}

int solution(int m, int n, vector<string> board) {
  int answer = 0;
  vector<vector<int>> b(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      b[i][j] = (int)board[m - j - 1][i];
  }

  int cnt = boom(n, m, b);
  while (cnt) {
    answer += cnt;
    cnt = boom(n, m, b);
  }

  return answer;
}