class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int,vector<int>> stopToBus;
        for(int i=0;i<routes.size();i++){
            for(auto j: routes[i]){
                stopToBus[j].push_back(i);
            }
        }
        int totalBuses = 0;
        unordered_set<int> visitedStops;
        unordered_set<int> visitedBuses;
        queue<int> q;
        q.push(source);
        visitedStops.insert(source);
        while(!q.empty()){
            int size = q.size();
            totalBuses++;
            while(size--){
                int curr_stop = q.front();
                q.pop();
                for(auto bus: stopToBus[curr_stop]){
                    if(visitedBuses.count(bus)) continue;
                    visitedBuses.insert(bus);
                    for(int i=0;i<routes[bus].size();i++){
                        if(routes[bus][i]==target) return totalBuses;
                        if(!visitedStops.count(routes[bus][i])){
                            visitedStops.insert(routes[bus][i]);
                            q.push(routes[bus][i]);
                        }
                    }
                }
            }
        }
        return -1;
    }
};