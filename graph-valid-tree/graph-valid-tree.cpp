class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // 이건 역시 사이클이 있는지 없는지를 봐야 한다
        vector<bool> inStack(n, false);
        vector<bool> visited(n, false);

        vector<vector<int>> graph = vector<vector<int>>(n);
        for(vector<int> edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        if(!dfs(inStack, visited, graph, -1, 0)) return false;

        for(bool flag : visited)
        {
            if(!flag) return false;
        }

        return true;
    }

    bool dfs(vector<bool>& inStack, vector<bool>& visited, vector<vector<int>>& graph, int parent, int current)
    {
        if(inStack[current]) return false;
        if(visited[current]) return true;

        visited[current] = true;
        inStack[current] = true;

        for(int node : graph[current])
        {
            if(node == parent) continue;
            if(!dfs(inStack, visited, graph, current, node)) return false;
        }   

        inStack[current] = false;

        return true;
    }
};