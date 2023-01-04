#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int tot=0,ind=0,res=0;
        for(auto x:nums){
            tot+=x;
            res+=(ind*x);
            ind++;
        }
        int ans=res;
        for(int i=(int)nums.size()-1;i>=0;i--){
            res+=tot-(nums[i]*(int)nums.size());
            ans=max(ans,res);
        }
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