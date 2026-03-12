#include <bits/stdc++.h>
using namespace std;

long long maxSum(vector<int>& nums, int k) {
    vector<int> bit(32,0);
    for(int x : nums){
        for(int b=0;b<32;b++){
            if(x & (1<<b))
                bit[b]++;
        }
    }

    long long ans = 0;
    for(int i=0;i<k;i++){

        long long cur = 0;

        for(int b=0;b<32;b++){
            if(bit[b] > 0){
                cur |= (1LL<<b);
                bit[b]--;
            }
        }
        ans += cur*cur;
    }
    return ans;
}

int main(){

    vector<int> nums = {2,6,5};
    int k = 2;

    cout<<maxSum(nums,k);
}