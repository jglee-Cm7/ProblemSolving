#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v = 0;
    int x = 0;
    Node* left = NULL;
    Node* right = NULL;
    Node(int v, int x, Node* left, Node* right) : v(v), x(x), left(left), right(right) {}
};

void preOrder(Node* root, vector<int>& order) {
    if(root == NULL) return;
    
    order.push_back(root->v);
    preOrder(root->left, order);
    preOrder(root->right, order);
}

void postOrder(Node* root, vector<int>& order) {
    if(root == NULL) return;
    
    postOrder(root->left, order);
    postOrder(root->right, order);
    order.push_back(root->v);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int n = nodeinfo.size();
    vector<tuple<int, int, int>> nodes;
    for(int i=0; i<n; i++)
        nodes.push_back({nodeinfo[i][1], nodeinfo[i][0], i+1});
    
    sort(nodes.begin(), nodes.end(), greater<>());
    
    auto [level, x, v] = nodes[0];
    Node* root = new Node(v, x, NULL, NULL);
    for(int i=1; i<n; i++) {
        auto [level, x, v] = nodes[i];
        Node* parent = root;
        
        while(parent != NULL) {
            // left
            if(x < parent->x) {
                if(parent->left == NULL) {
                    parent->left = new Node(v, x, NULL, NULL);
                    break;
                }
                parent = parent->left;
                
            } 
            // right
            else {
                if(parent->right == NULL) {
                    parent->right = new Node(v, x, NULL, NULL);
                    break;
                }
                parent = parent->right;
            }
        }
    }
    
    vector<int> order;
    preOrder(root, order);
    answer.push_back(order);
    order.clear();
    
    postOrder(root, order);
    answer.push_back(order);
    
    
    return answer;
}