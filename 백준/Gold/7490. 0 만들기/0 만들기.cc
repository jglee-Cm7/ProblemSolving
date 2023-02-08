#include <bits/stdc++.h>
using namespace std;

void func(vector<string> &result, vector<int> arr, int k, int n) {
  if (k == n - 1) {
    string eq = "";
    queue<int> q;
    vector<int> eqv;
    int v = 0;
    for (int i = 0; i < n - 1; i++) {
      eq += to_string(i + 1);
      v += i + 1;
      if (arr[i] == 0) {
        eq += "+";
        eqv.push_back(v);
        eqv.push_back(0);
        v = 0;
      } else if (arr[i] == 1) {
        eq += "-";
        eqv.push_back(v);
        eqv.push_back(-1);
        v = 0;
      } else if (arr[i] == 2) {
        eq += " ";
        v *= 10;
      }
    }
    eq += to_string(n);
    eqv.push_back(v + n);
    int ans = eqv[0];
    for (int i = 1; i < (int)eqv.size() - 1; i++) {
      if (eqv[i] == 0)
        ans += eqv[i + 1];
      else if (eqv[i] == -1)
        ans -= eqv[i + 1];
    }

    if (ans == 0) result.push_back(eq);
    return;
  }

  arr[k] = 0;
  func(result, arr, k + 1, n);
  arr[k] = 1;
  func(result, arr, k + 1, n);
  arr[k] = 2;
  func(result, arr, k + 1, n);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> result;
    vector<int> arr(n);
    func(result, arr, 0, n);
    sort(result.begin(), result.end());
    for (auto r : result)
      cout << r << "\n";
    cout << "\n";
  }
}