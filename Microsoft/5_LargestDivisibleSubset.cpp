#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size() ,ans = -1 ,  lastIndex =-1;
        vector<int> dp(n, 1);
        vector<int> trace(n, -1);
        sort(nums.begin() , nums.end());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if((nums[i]%nums[j] == 0) && dp[j] >= dp[i]){
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                }
            }
            if(dp[i] > ans){
                ans = dp[i];
                lastIndex = i;
            }
        }
        vector<int>path;
        while(lastIndex != -1){
            path.push_back(nums[lastIndex]);
            lastIndex = trace[lastIndex];
        }
        reverse(path.begin(), path.end());      
        return path;
    } 
};

#ifdef LOCAL
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif