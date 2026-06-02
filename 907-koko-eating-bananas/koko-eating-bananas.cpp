class Solution {
public:

    bool solve(vector<int>& piles, int k, int h){
        long long hours = 0;

        for(int pile : piles){
            hours += (pile + k - 1) / k; // ceil(pile/k)

            if(hours > h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high){

            int mid = low + (high - low) / 2;

            if(solve(piles, mid, h)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};