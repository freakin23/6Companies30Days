#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template<typename T>
T size(vector<T> v){
    return (T)v.size();
}

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0,ind=0;
        vector<int> res(4, 0);
        for(int i=0;i<size(s);i++){
            res[s[i]-'a']++;
            while(res[0] and res[1] and res[2]){
                ans+=(size(s)-i);
                res[s[ind]-'a']--;
                ind++;
            }
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