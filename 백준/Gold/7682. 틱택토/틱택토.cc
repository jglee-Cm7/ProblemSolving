#include <bits/stdc++.h>
using namespace std;
vector<string> ans[11];
void func(string board, int k) {
  if (k == 10) {
    ans[k].push_back(board);
    return;
  }

  for (int i = 0; i < 3; i++) {
    if (board[i] == '.') continue;
    if (board[i] == board[i + 3] && board[i] == board[i + 6]) {
      ans[k].push_back(board);
      return;
    }
  }

  for (int i = 0; i < 9; i += 3) {
    if (board[i] == '.') continue;
    if (board[i] == board[i + 1] && board[i] == board[i + 2]) {
      ans[k].push_back(board);
      return;
    }
  }

  if (board[0] != '.' && board[0] == board[4] && board[0] == board[8]) {
    ans[k].push_back(board);
    return;
  }
  if (board[2] != '.' && board[2] == board[4] && board[2] == board[6]) {
    ans[k].push_back(board);
    return;
  }

  char nxt = 'O';
  if (k % 2) nxt = 'X';
  for (int i = 0; i < 9; i++) {
    if (board[i] != '.') continue;
    board[i] = nxt;
    func(board, k + 1);
    board[i] = '.';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string board = ".........";

  func(board, 1);

  while (1) {
    string s;
    cin >> s;
    if (s == "end") break;
    int k = 0;
    for (int i = 0; i < 9; i++) {
      if (s[i] != '.') k++;
    }
    bool find = 0;
    for (auto bd : ans[k + 1]) {
      if (bd == s) {
        find = 1;
        break;
      }
    }
    if (find)
      cout << "valid\n";
    else
      cout << "invalid\n";
  }
}