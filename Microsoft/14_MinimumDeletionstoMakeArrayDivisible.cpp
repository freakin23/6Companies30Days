#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide){
        int val = numsDivide[0];
        for(auto i:numsDivide){
            val = __gcd(val, i);
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(val%nums[i] == 0){
                return i;
            }
        }
        return -1;
    }
};

#ifdef LOCAL
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif