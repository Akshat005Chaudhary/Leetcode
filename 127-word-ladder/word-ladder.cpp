class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<wordList.size();i++){
            int cnt = 0;
            for(int j=0;j<beginWord.size();j++){
                if(beginWord[j]!=wordList[i][j]){
                    cnt++;
                }
            }
            if(cnt==1) mp[beginWord].push_back(i);
        }
        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList.size();j++){
                if(i!=j){
                    int cnt = 0;
                    for(int k=0;k<beginWord.size();k++){
                        if(wordList[i][k]!=wordList[j][k]){
                            cnt++;
                        }
                    }
                    if(cnt==1) mp[wordList[i]].push_back(j);
                }
            }
        }
        unordered_set<string> visited;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string curr = q.front().first;
            int res = q.front().second;
            q.pop();
            if(visited.find(curr)!=visited.end()) continue;
            visited.insert(curr);
            if(curr==endWord) return res;
            for(auto it: mp[curr]){
                q.push({wordList[it],res+1});
            }
        }
        return 0;
    }
};