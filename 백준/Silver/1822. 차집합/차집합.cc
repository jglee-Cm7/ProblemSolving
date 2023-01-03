#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int an, bn;
  cin >> an >> bn;
  vector<int> A(an);
  vector<int> B(bn);
  vector<int> AmB;
  for (int i = 0; i < an; i++)
    cin >> A[i];
  for (int i = 0; i < bn; i++)
    cin >> B[i];
  sort(B.begin(), B.end());
  for (int a : A) {
    if (!binary_search(B.begin(), B.end(), a)) AmB.push_back(a);
  }
  sort(AmB.begin(), AmB.end());
  cout << AmB.size() << "\n";
  for (int v : AmB)
    cout << v << " ";
}