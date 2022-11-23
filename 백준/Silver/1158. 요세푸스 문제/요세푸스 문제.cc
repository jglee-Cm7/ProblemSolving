#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  list<int> l;
  vector<int> p;
  for (int i = 1; i <= n; i++)
    l.push_back(i);
  auto pos = l.begin();
  cout << "<";
  while (l.size() > 1) {
    for (int i = 0; i < k - 1; i++) {
      pos++;
      if (pos == l.end()) pos = l.begin();
    }
    cout << *pos << ", ";
    p.push_back(*pos);
    pos = l.erase(pos);
    if (pos == l.end()) pos = l.begin();
  }
  cout << *l.begin() << ">";
}