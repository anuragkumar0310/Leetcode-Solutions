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
#include <iomanip>
#include <numeric>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <ctime>
#include <array>
#include <deque>
#include <forward_list>
#include <initializer_list>
#include <regex>
#include <climits>
using namespace std;

static const auto apy07 = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();

mt19937_64 apy07_rng(chrono::steady_clock::now().time_since_epoch().count());

#define apy07 long long
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define pf pop_front
#define mp make_pair
#define mt make_tuple
#define PRECISION(x) cout << fixed << setprecision(x)
#define rep(i,a,b) { int i=a; while(i<b) { ++i; } }
#define per(i,a,b) { int i=a-1; while(i>=b) { --i; } }
#define each(x,a) { auto it=begin(a); while(it!=end(a)) { auto& x=*it; ++it; } }
#define debug(x) cerr << #x << " = " << x << endl
#define yes cout << "sahi baat hai\n"
#define no cout << "galat baat hai\n"

template<typename T> using vt = vector<T>;
template<typename T> using vvt = vector<vector<T>>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using uset = unordered_set<T>;
template<typename T, typename U> using umap = unordered_map<T,U>;
template<typename T> using mset = multiset<T>;
template<typename T, typename U> using mmap = multimap<T,U>;

const apy07 INF = 0x3f3f3f3f3f3f3f3f;
const apy07 MOD = 1e9 + 7;
const apy07 MOD2 = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const apy07 MAX = 2e5 + 5;

apy07 apy07_dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
apy07 apy07_dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
apy07 apy07_dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
apy07 apy07_dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
apy07 apy07_dx4[] = {-1, 0, 1, 0};
apy07 apy07_dy4[] = {0, 1, 0, -1};

template<typename T, typename U> inline void amin(T &x, U y) { x = (y < x) ? y : x; }
template<typename T, typename U> inline void amax(T &x, U y) { x = (y > x) ? y : x; }
template<typename T> inline T sgn(T x) { return (T(0) < x) - (x < T(0)); }
template<typename T> inline T sq(T x) { return x * x; }
template<typename T> inline T cub(T x) { return x * x * x; }
template<typename T> inline bool isPow2(T x) { return x && (x & -x) == x; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> inline T mod(T a, T m) { return ((a % m) + m) % m; }

uint64_t custom_hash(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

class Solution {
    unordered_map<string, unsigned int> map;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unsigned int length = words[0].size();
        map.clear();
        
        auto it = words.begin();
        while(it != words.end()) {
            map[*it]++;
            ++it;
        }
        
        unsigned int offset = 0;
        while(offset < length) {
            unsigned int size = 0;
            unordered_map<string, unsigned int> seen;
            
            unsigned int i = offset;
            while(i + length <= s.size()) {
                string sub = s.substr(i, length);
                auto itr = map.find(sub);
                
                (itr == map.end()) ? (seen.clear(), size = 0) : (++seen[sub], ++size);
                
                while(seen[sub] > (itr != map.end() ? itr->second : 0)) {
                    string first = s.substr(i - (size - 1) * length, length);
                    --seen[first];
                    --size;
                }
                
                (size == words.size()) ? result.push_back(i - (size - 1) * length) : void();
                
                i += length;
            }
            ++offset;
        }
        return result;
    }
};

void solve() {
    Solution solution;
}

