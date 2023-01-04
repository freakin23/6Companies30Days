#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> mp;
        for(auto x:rectangles){
            mp[{x[0], x[1]}]++;
            mp[{x[0], x[3]}]--;
            mp[{x[2], x[1]}]--;
            mp[{x[2], x[3]}]++;
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second!=0){
                if(abs(it.second)!=1){
                    return false;
                }
                cnt++;
            }
        }
        if(cnt==4){
            return true;
        }
        return false;
    }
};

#ifdef LOCAL
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif