class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        res.push_back(pq.top().first);
        for(int i=k;i<n;i++){
            pq.push({nums[i],i});
            if(nums[i]<pq.top().first){
                while(nums[i]<pq.top().first && pq.top().second<=(i-k)){
                    pq.pop();
                }
                res.push_back(pq.top().first);
            }else{
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};