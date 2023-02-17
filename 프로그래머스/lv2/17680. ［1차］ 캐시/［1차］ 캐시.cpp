#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_map<string, int> m;
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        for (auto &c : city)
            c = tolower(c);
        auto it = m.find(city);
        if (it != m.end()) {
            answer += 1;
            m[city] = i;
        } else {
            answer += 5;
            if ((int)m.size() == cacheSize) {
                int mn = 101010;
                string k;
                for (auto [key, value] : m) {
                    if (value < mn) {
                        mn = value;
                        k = key;
                    }
                }
                if (mn != 101010) m.erase(k);
            }
            if ((int)m.size() < cacheSize) m.insert({city, i});
        }
    }
return answer;
}