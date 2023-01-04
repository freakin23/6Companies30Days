#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> res;
        res=nums;
        sort(res.begin(),res.end());
        int n=(int)nums.size();
        int low=n,high=0;
        for(int i=0;i<n;i++){
            if(res[i]!=nums[i]){
                low=min(i,low);
                high=max(i,high);
            }
        }
        int ans=(high-low+1>0?high-low+1:0);
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