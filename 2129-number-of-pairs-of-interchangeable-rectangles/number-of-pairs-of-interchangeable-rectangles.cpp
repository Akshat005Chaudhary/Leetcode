class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        // vector<double> divs;
        unordered_map<double,int> mp;
        for(auto it: rectangles){
            int num = it[0];
            int deno = it[1];
            // divs.push_back((num*1.0)/deno);
            double div = (num*1.0)/deno;
            mp[div]++;
        }
        // for(auto it: divs){
        //     mp[it]++;
        // }
        long long res =  0;
        for(auto it: mp){
            int nn = it.second;
            res += (1LL*nn*(nn-1))/2;
        }
        return res;
    }
};