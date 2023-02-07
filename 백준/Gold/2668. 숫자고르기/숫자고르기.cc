#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int arr[105];

  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  int vis[105];
  set<int> s;
  for (int i = 1; i <= n; i++) {
    fill(vis, vis + n, 0);
    vector<int> num;
    int cnt = 1;
    int nxt = arr[i];
    num.push_back(i);
    bool loop = true;
    while (nxt != i) {
      if (vis[nxt]) {
        loop = false;
        break;
      }
      num.push_back(nxt);
      vis[nxt] = 1;
      nxt = arr[nxt];
      cnt++;
    }
    if (loop) {
      for (int nm : num)
        s.insert(nm);
    }
  }

  cout << s.size() << "\n";
  for (int ss : s)
    cout << ss << "\n";
}