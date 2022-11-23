#include <bits/stdc++.h>
using namespace std;

deque<int> split(string s, char delimiter) {
  deque<int> result;

  string::size_type prev = 0;
  string::size_type pos = s.find(delimiter);
  while (pos != string::npos) {
    string sub = s.substr(prev, pos - prev);
    result.push_back(stoi(sub));
    prev = pos + 1;
    pos = s.find(delimiter, prev);
  }

  string sub = s.substr(prev, pos - prev);
  if (sub.size() > 0) result.push_back(stoi(sub));

  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string ops, data;
    int n;
    cin >> ops >> n >> data;

    data[data.size() - 1] = '\0';
    deque<int> q = split(&data[1], ',');
    bool e = false;
    bool r = false;
    for (auto op : ops) {
      if (op == 'R') {
        r = !r;
        continue;
      }
      if (q.empty()) {
        e = true;
        break;
      }
      if (!r)
        q.pop_front();
      else
        q.pop_back();
    }

    if (e) {
      cout << "error"
           << "\n";
    } else {
      if (r) reverse(q.begin(), q.end());
      cout << "[";
      for (int i = 0; i < (int)q.size() - 1; i++)
        cout << q[i] << ",";

      if (!q.empty()) cout << q[q.size() - 1];
      cout << "]\n";
    }
  }
}