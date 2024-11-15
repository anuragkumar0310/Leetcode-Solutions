/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> result;
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            
            TreeNode* node = current.first;
            int row = current.second.first;
            int col = current.second.second;
            
            nodes[col][row].insert(node->val);
            
            node->left ? q.push({node->left, {row + 1, col - 1}}) : void();
            node->right ? q.push({node->right, {row + 1, col + 1}}) : void();
        }
        
        int col_index = 0;
        auto map_iter = nodes.begin();
        
        while (map_iter != nodes.end()) {
            result.push_back(vector<int>());
            auto row_iter = map_iter->second.begin();
            
            while (row_iter != map_iter->second.end()) {
                auto val_iter = row_iter->second.begin();
                
                while (val_iter != row_iter->second.end()) {
                    result[col_index].push_back(*val_iter);
                    val_iter++;
                }
                row_iter++;
            }
            map_iter++;
            col_index++;
        }
        
        return result;
    }
};