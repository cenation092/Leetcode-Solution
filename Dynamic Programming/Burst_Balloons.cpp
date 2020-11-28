//Editorial: https://journeywithdp.blogspot.com/2019/07/burst-balloons-google-interview-question.html

class Solution {
public:
    
    int go( int l, int r, vector<int> &ar, vector<vector<int>> &dp ){
        if( l > r )return 0;
        if( dp[l][r] != -1 )return dp[l][r];
        int ans = 0;
        int left = 1, right = 1;
        if( l-1 >= 0 )left = ar[l-1];
        if( r+1 <= ar.size()-1)right = ar[r+1];
        for( int i = l; i <= r; i++ ){
            ans = max(ans, left*ar[i]*right + go(l, i-1, ar, dp) + go(i+1, r, ar, dp));
        }
        return dp[l][r] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return go(0, nums.size()-1, nums, dp);
    }
};
