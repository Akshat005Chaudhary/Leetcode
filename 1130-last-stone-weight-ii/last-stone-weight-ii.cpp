class Solution {
public:
    int dp[31][3005];

    int solve(int ind, int curr, vector<int>& stones) {
        if (ind == stones.size()) return curr;

        if (dp[ind][curr] != -1) return dp[ind][curr];

        int add = solve(ind + 1, curr + stones[ind], stones);
        int subtract = solve(ind + 1, abs(curr - stones[ind]), stones);

        return dp[ind][curr] = min(add, subtract);
    }

    int lastStoneWeightII(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, stones); 
    }
};