#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  map<string, int> freq;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    freq[s]++;
  }
  vector<pair<int, long long>> card;
  for (auto [key, value] : freq) {
    card.push_back({value, stoll(key)});
  }
  sort(card.begin(), card.end(), [](const auto &a, const auto &b) -> bool {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
  });

  cout << card[0].second;
}