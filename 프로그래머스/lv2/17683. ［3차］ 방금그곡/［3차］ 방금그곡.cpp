#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, string delimiter) {
  vector<string> result;

  char *str = strdup(s.c_str());
  char *del = strdup(delimiter.c_str());

  char *ptr = strtok(str, del);
  while (ptr != NULL) {
    string token = ptr;
    result.push_back(token);
    ptr = strtok(NULL, del);
  }

  free(str);
  free(del);
  return result;
}

string solution(string m, vector<string> musicinfos) {
  string answer = "";
  int playTime = 0;
  for (string music : musicinfos) {
    vector<string> infos = split(music, ",:");
    int t = (stoi(infos[2]) * 60 + stoi(infos[3])) -
            (stoi(infos[0]) * 60 + stoi(infos[1]));

    vector<string> musicCodes, mCodes;
    for (char c : infos[5]) {
      string code(1, c);
      if (c == '#')
        musicCodes[musicCodes.size() - 1] += c;
      else
        musicCodes.push_back(code);
    }
    for (char c : m) {
      string code(1, c);
      if (c == '#')
        mCodes[mCodes.size() - 1] += c;
      else
        mCodes.push_back(code);
    }

    vector<string> play;
    for (int i = 0; i < t; i++)
      play.push_back(musicCodes[i % musicCodes.size()]);

    bool flag = 0;
    for (int i = 0; i < (int)play.size() - (int)mCodes.size() + 1; i++) {
      string part = "";
      for (int j = i; j < i + (int)mCodes.size(); j++)
        part += play[j];
      if (m == part) {
        flag = 1;
        break;
      }
    }

    if (flag && playTime < t) {
      playTime = t;
      answer = infos[4];
    }
  }
  if (answer == "") answer = "(None)";
  return answer;
}