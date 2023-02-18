#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  vector<int> A(26);
  for (char c : s) A[tolower(c) - 'a']++;

  int mx = 0;
  char answer = 0;
  for (int i = 0; i < 26; i++) {
    if (A[i] <= mx) continue;
    mx = A[i];
    answer = 'A' + i;
  }
  if (count(A.begin(), A.end(), mx) > 1) cout << "?";
  else cout << answer;
}