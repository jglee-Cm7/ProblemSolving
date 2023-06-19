#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v;
    Node* prev;
    Node* next;
    Node(int v, Node* prev, Node* next) : v(v), prev(prev), next(next) {}
};

string solution(int n, int k, vector<string> cmd) {
    string answer (n, 'O');
    stack<Node*> s;
    Node* cur = new Node(0, NULL, NULL);
    for(int i=1; i<n; i++) {
        cur->next = new Node(i, cur, NULL);
        cur = cur->next;
    }
    for(int i=0; i<n-k-1; i++) cur = cur->prev;
    
    for(auto m : cmd) {
        char op = m[0];
        if(op == 'D') {
            int d = stoi(m.substr(2));
            while(d--) cur = cur->next;
        }
        if(op == 'U') {
            int u = stoi(m.substr(2));
            while(u--) cur = cur->prev;
        }
        if(op == 'C') {
            int key = cur->v;
            answer[key] = 'X';
            s.push(cur);
            if(cur->prev) cur->prev->next = cur->next;
            if(cur->next) {
                cur->next->prev = cur->prev;
                cur = cur->next;
            } else cur = cur->prev;
        }
        if(op == 'Z') {
            auto key = s.top();
            answer[key->v] = 'O';
            if(key->prev) key->prev->next = key;
            if(key->next) key->next->prev = key;
            s.pop();
            
        }
    }
    
    return answer;
}