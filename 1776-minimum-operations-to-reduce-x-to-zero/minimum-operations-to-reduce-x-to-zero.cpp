class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        int target = totalsum-x;
        int left = 0;
        int right = 0;
        int maxi = INT_MIN;
        int curr_sum = 0;
        for(;right<n;right++){
            curr_sum += nums[right];
            while(left<=right && curr_sum>target){
                curr_sum -= nums[left];
                left++;
            }
            if(curr_sum==target){
                maxi = max(maxi,right-left+1);
            }
        }
        if(maxi==INT_MIN) return -1;
        return n-maxi;
    }
};