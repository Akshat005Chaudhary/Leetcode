class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int res = 1;
        for(auto it: nums){
            if(it<=0) continue;
            if(res<it){
                st.insert(it);
                continue;
            }else if(res==it){
                st.insert(it);
                while(st.find(res)!=st.end()){
                    res++;
                }
            }
        }
        return res;
    }
};