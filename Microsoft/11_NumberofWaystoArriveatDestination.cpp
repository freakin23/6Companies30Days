#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

#define ll long long int
const int MOD=1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> graph(n);
        for(auto& road: roads) {
            ll u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        auto dijkstra=[&](const vector<vector<pair<ll,ll>>>& graph, int n, int src){
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> q;
        q.push({0, 0}); // dist, src
        while (!q.empty()) {
            auto[d, u]=q.top();
            q.pop();
            if (d > dist[u]){
                continue;
            }
            for(auto [v, time] : graph[u]){
                if (dist[v] > d + time){
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    q.push({dist[v], v});
                }
                else if (dist[v] == d + time){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    };
    int ans=dijkstra(graph,n,0);
    return ans;
    }
};
    

#ifdef LOCAL
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif