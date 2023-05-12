#include <bits/stdc++.h>
using namespace std;

int hammingDistance(string a, string b) {
  int result = 0;
  for (int i = 0; i < (int)a.length(); i++)
    if (a[i] != b[i]) result++;
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> DNAs(n);
  for (int i = 0; i < n; i++)
    cin >> DNAs[i];

  string DNA = "";
  int ans = 0;
  vector<int> alp(27, 0);
  for (int i = 0; i < m; i++) {
    alp = vector(27, 0);
    int mx = 0;
    for (int j = 0; j < n; j++) {
      int k = DNAs[j][i] - 'A';
      alp[k]++;
      if (alp[k] > mx) mx = alp[k];
    }
    for (int j = 0; j < 27; j++) {
      if (mx == alp[j]) {
        char nt = 'A' + j;
        DNA.push_back(nt);
        break;
      }
    }
  }
  for (int i = 0; i < n; i++)
    ans += hammingDistance(DNAs[i], DNA);

  cout << DNA << "\n";
  cout << ans;
}