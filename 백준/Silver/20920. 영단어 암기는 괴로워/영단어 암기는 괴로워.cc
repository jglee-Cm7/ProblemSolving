#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  unordered_map<string, int> word;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if ((int)s.size() < m) continue;
    if (word.find(s) == word.end()) word.insert({s, 1});
    else word[s]++;
  }
  vector<tuple<int, int, string>> note;
  for (auto [key, value] : word)
    note.push_back({value, key.size(), key});

  sort(note.begin(), note.end(), [](const auto &a, const auto &b) -> bool {
    int f1, f2, l1, l2;
    string s1, s2;
    tie(f1, l1, s1) = a;
    tie(f2, l2, s2) = b;
    if (f1 != f2) return f1 > f2;
    if (l1 != l2) return l1 > l2;
    if (s1 != s2) return s1 < s2;
  });

  for (auto [f, l, s] : note)
    cout << s << "\n";
}