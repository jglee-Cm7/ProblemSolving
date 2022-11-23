#include <bits/stdc++.h>
using namespace std;

int findIndex(deque<int> &q, int v) {
  for (int i = 0; i < (int)q.size(); i++) {
    if (q[i] == v) return i;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  vector<int> arr;
  deque<int> q;
  int ans = 0;

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    arr.push_back(v);
  }

  for (int i = 1; i <= n; i++)
    q.push_back(i);

  for (auto v : arr) {
    if (q.front() == v) {
      q.pop_front();
      continue;
    }
    int idx = findIndex(q, v);
    int rIdx = (int)q.size() - idx;
    if (idx <= rIdx) {
      ans += idx;
      while (idx--) {
        q.push_back(q.front());
        q.pop_front();
      }
    } else {
      ans += rIdx;
      while (rIdx--) {
        q.push_front(q.back());
        q.pop_back();
      }
    }
    q.pop_front();
  }
  cout << ans << "\n";
}