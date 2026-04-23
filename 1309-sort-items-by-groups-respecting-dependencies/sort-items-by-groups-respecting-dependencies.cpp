class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& graph, vector<int>& indegree, int n) {
        queue<int> q;
        vector<int> res;
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res.push_back(u);
            
            for (int v : graph[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        
        return res.size() == n ? res : vector<int>();
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) group[i] = m++;
        }

        vector<vector<int>> itemGraph(n), groupGraph(m);
        vector<int> itemIndegree(n, 0), groupIndegree(m, 0);

        for (int v = 0; v < n; v++) {
            for (int u : beforeItems[v]) {
                itemGraph[u].push_back(v);
                itemIndegree[v]++;

                if (group[u] != group[v]) {
                    groupGraph[group[u]].push_back(group[v]);
                    groupIndegree[group[v]]++;
                }
            }
        }

        vector<int> groupOrder = topoSort(groupGraph, groupIndegree, m);
        if (groupOrder.empty()) return {};

        vector<int> itemOrder = topoSort(itemGraph, itemIndegree, n);
        if (itemOrder.empty()) return {};

        unordered_map<int, vector<int>> mp;
        for (int item : itemOrder) {
            mp[group[item]].push_back(item);
        }

        vector<int> res;
        for (int g : groupOrder) {
            for (int item : mp[g]) {
                res.push_back(item);
            }
        }

        return res;
    }
};