#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << 100 << "\n";
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      if (i == 100 || j == 100 || i == j)
        cout << "0 ";
      else
        cout << "1 ";
    }
    cout << "\n";
  }
}