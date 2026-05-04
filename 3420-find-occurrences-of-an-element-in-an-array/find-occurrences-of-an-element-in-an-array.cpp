class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int count = 1;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                mp[count++] = i;
            }
        }
        for(auto &it: queries){
            if(mp.find(it)==mp.end()){
                it = -1;
            }else it = mp[it];
        }
        return queries;
    }
};