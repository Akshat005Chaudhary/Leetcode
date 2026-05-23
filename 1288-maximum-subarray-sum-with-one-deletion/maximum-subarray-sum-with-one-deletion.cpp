class Solution {
public:

    int dp[100005][2];

    // flag = 0 -> deletion not used yet
    // flag = 1 -> deletion already used

    int solve(int i, vector<int>& arr, int flag) {

        if(i == arr.size())
            return -1e9;

        if(dp[i][flag] != -1)
            return dp[i][flag];

        int ans;

        if(flag == 0) {

            // 3 choices:
            // 1. start new subarray
            // 2. continue subarray
            // 3. delete current element

            ans = max({
                arr[i],
                arr[i] + solve(i + 1, arr, 0),
                solve(i + 1, arr, 1)
            });

        } else {

            // deletion already used

            ans = max(
                arr[i],
                arr[i] + solve(i + 1, arr, 1)
            );
        }

        return dp[i][flag] = ans;
    }

    int maximumSum(vector<int>& arr) {

        memset(dp, -1, sizeof(dp));

        int ans = arr[0];

        for(int i = 0; i < arr.size(); i++) {

            ans = max(ans, solve(i, arr, 0));
        }

        return ans;
    }
};