class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;

        vector<int> route;
        dfs(graph, ans, route, 0);

        return ans;
    }

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& route, int source)
    {
        int n = graph.size();

        route.push_back(source);

        if(source == n-1)
        {
            ans.push_back(route);
        }else
        {
            for(int node : graph[source])
            {
                dfs(graph, ans, route, node);
            }
        }

        route.pop_back();
    }
};