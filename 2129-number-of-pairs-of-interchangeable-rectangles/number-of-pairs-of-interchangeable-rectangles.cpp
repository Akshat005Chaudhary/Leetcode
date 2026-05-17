class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,int> mp;
        for(auto it: rectangles){
            int num = it[0];
            int deno = it[1];
            double div = (num*1.0)/deno;
            mp[div]++;
        }
        long long res =  0;
        for(auto it: mp){
            int nn = it.second;
            res += (1LL*nn*(nn-1))/2;
        }
        return res;
    }
};