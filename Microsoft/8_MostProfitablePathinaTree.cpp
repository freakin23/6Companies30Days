#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> G(n);
        for (auto& v : edges) {
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
        }
        vector<int> p(n, -1), dep(n), dp(n), f(n, 1);
        vector<int> o;
        function<void(int)> DFS = [&](int u) {
            for (int v : G[u]) {
                if (p[u] != v) {
                    p[v] = u;
                    dep[v] = dep[u] + 1;
                    DFS(v);
                }
            }
            o.push_back(u);
        };
        DFS(0);
        for (int x = bob; x != -1; x = p[x]) {
            if (dep[x] * 2 == dep[bob]) {
                amount[x] /= 2;
            }
            if (dep[x] * 2 > dep[bob]) {
                amount[x] = 0;
            }
        }
        for (int i : o) {
            dp[i] += amount[i];
            if (i) {
                if (f[p[i]] == 1) {
                    dp[p[i]] = dp[i];
                    f[p[i]] = 0;
                } else {
                    dp[p[i]] = max(dp[p[i]], dp[i]);
                }
            }
        }
        return dp[0];
    }
};

#ifdef LOCAL
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif