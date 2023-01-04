#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    void backtrack(vector<vector<int>> &ans,vector<int> &curr,vector<int> v,int remain,int start,int k){
        if(remain<0) return;
        else if(remain==0&&(int)curr.size()==k) ans.push_back(curr);
        else{
            for(int i=start;i<(int)v.size();i++){
                curr.push_back(v[i]);
                backtrack(ans,curr,v,remain-v[i],i+1,k);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> v={1,2,3,4,5,6,7,8,9};
        backtrack(ans,curr,v,n,0,k);
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