class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> prev(grid[0]);

        for(int i = 1; i < n; i++){
            int min1 = -1, min2 = -1;

            // find min1 and min2 indices
            for(int j = 0; j < n; j++){
                if(min1 == -1 || prev[j] < prev[min1]){
                    min2 = min1;
                    min1 = j;
                } else if(min2 == -1 || prev[j] < prev[min2]){
                    min2 = j;
                }
            }

            vector<int> curr(n);

            for(int j = 0; j < n; j++){
                if(j == min1){
                    curr[j] = grid[i][j] + prev[min2];
                } else {
                    curr[j] = grid[i][j] + prev[min1];
                }
            }

            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};