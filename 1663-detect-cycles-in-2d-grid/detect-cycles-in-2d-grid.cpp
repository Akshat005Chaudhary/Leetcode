class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<int> dir = {0,-1,0,1,0};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<pair<int,int>,pair<int,int>>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]) continue;
                q.push({{i,j},{-1,-1}});
                visited[i][j] = 1;
                while(!q.empty()){
                    auto curr = q.front();
                    q.pop();
                    int ii = curr.first.first;
                    int jj = curr.first.second;
                    char src_char = grid[ii][jj];
                    auto parent = curr.second;
                    for(int d=0;d<4;d++){
                        int new_ii = ii+dir[d];
                        int new_jj = jj+dir[d+1];
                        pair<int,int> tmp = {new_ii,new_jj};
                        if(new_ii>=0 && new_ii<m && new_jj>=0 && new_jj<n && grid[new_ii][new_jj]==src_char){
                            if(!visited[new_ii][new_jj]) {
                                visited[new_ii][new_jj] = 1;
                                q.push({{new_ii,new_jj},{ii,jj}});
                            }
                            else if(tmp != parent) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};