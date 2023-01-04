#include<bits/stdc++.h>

#define ll long long 
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        ll res=0;
        tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ret;
        for(int i=0;i<(int)a.size();i++){
            res+=ret.order_of_key((ll)(a[i]-b[i]+diff+1)*(1e5));
            ret.insert(((ll)(a[i]-b[i])*1e5)+i);
        }
        return res;
    }
};

#ifdef LOCAL
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif