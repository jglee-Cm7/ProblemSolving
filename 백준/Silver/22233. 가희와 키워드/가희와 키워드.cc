#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  unordered_set<string> note;
  while (n--) {
    string s;
    cin >> s;
    note.insert(s);
  }
  while (m--) {
    string l;
    cin >> l;
    string keyword;
    int curPos = 0;
    int pos;
    while ((pos = l.find(",", curPos)) != string::npos) {
      int length = pos - curPos;
      keyword = l.substr(curPos, length);
      note.erase(keyword);
      curPos = pos + 1;
    }
    keyword = l.substr(curPos);
    note.erase(keyword);
    cout << note.size() << "\n";
  }
}
