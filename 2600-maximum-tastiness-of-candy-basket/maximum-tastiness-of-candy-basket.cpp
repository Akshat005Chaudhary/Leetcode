class Solution {
public:

    bool check(int diff, vector<int>& price, int k){
        int cnt = 1;
        int prev = price[0];
        for(int i=1;i<price.size();i++){
            if(price[i]-prev>=diff){
                prev = price[i];
                cnt++;
            }
        }
        return cnt>=k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int low = 0;
        int maxi = *max_element(price.begin(),price.end());
        int mini = *min_element(price.begin(),price.end());
        int high = maxi-mini+1;
        while(high-low>1){
            int mid = low+(high-low)/2;
            if(check(mid,price,k)){
                low = mid;
            }else high = mid;
        }
        if(check(high,price,k)) return high;
        return low;
    }
};

// 1,2,5,8,13,21