class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<int> dir = {0,-1,0,1,0};
        int n = grid.size();
        int color_id = 0;
        unordered_map<int,int> mp_size;
        vector<vector<int>> color(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 || color[i][j]!=-1) continue;
                q.push({i,j});
                int color_here = color_id;
                color[i][j] = color_id++;
                mp_size[color_here] = 1;
                while(!q.empty()){
                    auto curr = q.front();
                    q.pop();
                    int ii = curr.first;
                    int jj = curr.second;
                    for(int d=0;d<4;d++){
                        int new_ii = ii+dir[d];
                        int new_jj = jj+dir[d+1];
                        if(new_ii>=0 && new_ii<n && new_jj>=0 && new_jj<n && grid[new_ii][new_jj]==1 && color[new_ii][new_jj]==-1){
                            color[new_ii][new_jj] = color_here;
                            q.push({new_ii,new_jj});
                            mp_size[color_here]++;
                        }
                    }
                }
            }
        }
        // Now I'm guessing all the islands are color coded
        int count = 0;
        int maxi = 0;
        for (auto &it : mp_size) {
            maxi = max(maxi, it.second);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                unordered_set<int> st;
                if(grid[i][j]==0){
                    for(int d=0;d<4;d++){
                        int ii = i+dir[d];
                        int jj = j+dir[d+1];
                        if(ii>=0 && ii<n && jj>=0 && jj<n && color[ii][jj] != -1){
                            st.insert(color[ii][jj]);
                        }
                    }
                    int sum = 1;
                    for(auto it: st){
                        sum += mp_size[it];
                    }
                    maxi = max(maxi,sum);
                }
            }
        }
        return maxi;
    }
};