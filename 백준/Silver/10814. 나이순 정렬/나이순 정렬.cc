#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<tuple<int, int, string>> s;
  for (int i = 0; i < n; i++) {
    int age;
    string name;
    cin >> age >> name;
    s.insert({age, i, name});
  }
  for (auto [age, i, name] : s) {
    cout << age << " " << name << "\n";
  }
}