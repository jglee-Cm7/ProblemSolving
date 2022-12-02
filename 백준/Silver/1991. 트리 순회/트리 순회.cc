#include <bits/stdc++.h>
using namespace std;

vector<int> lc(30);
vector<int> rc(30);

void preOrder(int cur) {
  if (cur == 0) return;
  cout << static_cast<char>(cur + 'A' - 1);
  preOrder(lc[cur]);
  preOrder(rc[cur]);
}
void inOrder(int cur) {
  if (cur == 0) return;
  inOrder(lc[cur]);
  cout << static_cast<char>(cur + 'A' - 1);
  inOrder(rc[cur]);
}
void postOrder(int cur) {
  if (cur == 0) return;
  postOrder(lc[cur]);
  postOrder(rc[cur]);
  cout << static_cast<char>(cur + 'A' - 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    char v, l, r;
    cin >> v >> l >> r;
    if (l != '.') lc[v - 'A' + 1] = l - 'A' + 1;
    if (r != '.') rc[v - 'A' + 1] = r - 'A' + 1;
  }

  preOrder(1);
  cout << "\n";
  inOrder(1);
  cout << "\n";
  postOrder(1);
}