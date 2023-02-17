#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
  vector<string> a, b;
  unordered_map<string, int> am, bm;
  double sub = 0, uni = 0;
  for (int i = 0; i < (int)str1.length() - 1; i++) {
    string s;
    char c1 = tolower(str1[i]);
    char c2 = tolower(str1[i + 1]);
    if ((c1 >= 'a' && c1 <= 'z') && (c2 >= 'a' && c2 <= 'z')) {
      s.push_back(c1);
      s.push_back(c2);
      a.push_back(s);
      am[s]++;
    }
  }
  for (int i = 0; i < (int)str2.length() - 1; i++) {
    string s;
    char c1 = tolower(str2[i]);
    char c2 = tolower(str2[i + 1]);
    if ((c1 >= 'a' && c1 <= 'z') && (c2 >= 'a' && c2 <= 'z')) {
      s.push_back(c1);
      s.push_back(c2);
      b.push_back(s);
      bm[s]++;
    }
  }

  for (auto [key, value] : am) {
    if (bm.find(key) != bm.end()) sub += min(value, bm[key]);
    uni += value;
  }
  for (auto [key, value] : bm)
    uni += value;
  uni -= sub;
  if (sub == 0 && uni == 0)
    answer = 65536;
  else
    answer = floor((sub / uni) * 65536);
  return answer;
}