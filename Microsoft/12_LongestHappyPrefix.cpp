#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
private:
vector<int> prefix_function(string s){    
	int n = s.length();
	int i = 1;int j = 0;
	vector<int> ans(n,0);
	while(i<n){
	    if(s[i]==s[j]){
	        j++;
	        ans[i] = j;
	        i++;
	    }
	    else{
	        if(j==0){
	            ans[i]=0;
	            i++;
	        }
	        else{
	            j = ans[j-1];
	        }
	    }
	}
	return ans;
}  
public:
    string longestPrefix(string s) {
        vector<int> prefix = prefix_function(s);
        if(prefix[prefix.size()-1]==0) return "";
        else{
          return s.substr(0,prefix[prefix.size()-1]);
        }
    }
};

#ifdef LOCAL
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif