#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1){
            return 1.00000;
        }
        return 0.50000;
    }
};

#ifdef LOCAL
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif