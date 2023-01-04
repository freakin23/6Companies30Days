#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    string getHint(string a, string b) {
        int bull=0,cow=0;
        string s="",t="";
        map<char,int> mp1,mp2;
        for(int i=0;i<(int)a.size();i++){
            if(a[i]==b[i]){
                bull++;
            }
            else{
                mp1[a[i]]++;
                mp2[b[i]]++;
            }
        }
        for(auto x:mp1){
            cow+=min(mp1[x.first],mp2[x.first]);
        }
        string ans="";
        ans+=to_string(bull)+"A"+to_string(cow)+"B";
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