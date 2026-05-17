class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(int i=0;i<n;i++){
            string sorted = strs[i];
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(strs[i]);
        }
        for(auto it: mp){
            res.push_back(it.second);
        }
        return res;
    }
};