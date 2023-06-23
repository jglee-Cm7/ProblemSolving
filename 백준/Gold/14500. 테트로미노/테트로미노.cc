#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> board(505, vector<int>(505, 0));

int tetromino() {
  int mx = 0;

  // O O O O 형태
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 3; j++) {
      int sum =
          board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
      mx = max(sum, mx);
    }
  }

  // O O
  // O O 형태
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      int sum =
          board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1];
      mx = max(sum, mx);
    }
  }

  // O
  // O
  // O O 형태
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 1; j++) {
      int sum =
          board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
      mx = max(sum, mx);
    }
  }

  //   O
  //   O
  // O O 형태
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 1; j++) {
      int sum = board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j] +
                board[i + 2][j + 1];
      mx = max(sum, mx);
    }
  }

  // O
  // O O
  //   O 형태
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 1; j++) {
      int sum = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] +
                board[i + 2][j + 1];
      mx = max(sum, mx);
    }
  }

  //   O
  // O O
  // O   형태
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 1; j++) {
      int sum = board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] +
                board[i + 2][j];
      mx = max(sum, mx);
    }
  }

  // O O O
  //   O    형태
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 2; j++) {
      int sum =
          board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
      mx = max(sum, mx);
    }
  }

  return mx;
}

int main() {
  cin >> n >> m;
  int answer = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }

  for (int k = 0; k < 4; k++) {
    vector<vector<int>> temp(505, vector<int>(505, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        temp[i][j] = board[n - j - 1][i];
    }
    swap(n, m);
    board = temp;
    answer = max(answer, tetromino());
  }

  cout << answer;
}
