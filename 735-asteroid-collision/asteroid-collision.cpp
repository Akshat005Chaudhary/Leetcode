class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(asteroids[i]);
                continue;
            }
            int newcommer = asteroids[i];
            int flag = 0;
            while(!st.empty() && (st.top() > 0 && newcommer < 0)){
                if(abs(st.top())>abs(newcommer)){
                    flag = 1;
                    break;
                }else if(abs(st.top())==abs(newcommer)){
                    flag = 1;
                    st.pop();
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(flag==1) continue;
            st.push(asteroids[i]);
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res; 
    }
};