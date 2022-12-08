#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n;
  map<string, int> nameMap;
  vector<string> name(n);
  vector<int> adj[n];
  vector<int> deg(n);
  vector<string> child[n];
  for (int i = 0; i < n; i++) {
    string nm;
    cin >> nm;
    name[i] = nm;
  }
  sort(name.begin(), name.end());
  for (int i = 0; i < n; i++) {
    nameMap.insert({name[i], i});
  }

  cin >> m;
  while (m--) {
    string u, v;
    cin >> u >> v;
    adj[nameMap[v]].push_back(nameMap[u]);
    deg[nameMap[u]]++;
  }

  deque<int> q;
  vector<string> father;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      q.push_back(i);
      father.push_back(name[i]);
    }
  }
  sort(father.begin(), father.end());
  cout << father.size() << "\n";
  for (string s : father)
    cout << s << " ";
  cout << "\n";

  while (!q.empty()) {
    int cur = q.front();
    q.pop_front();
    for (int nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) {
        child[cur].push_back(name[nxt]);
        q.push_back(nxt);
      }
    }
  }

  for (string s : name) {
    cout << s << " ";
    int idx = nameMap[s];
    cout << child[idx].size() << " ";
    sort(child[idx].begin(), child[idx].end());
    for (string c : child[idx])
      cout << c << " ";
    cout << "\n";
  }
}