class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        unordered_map<int, int> state;
        return dfs(graph, state, source, destination);

        // 그러니까 어떤 길로 가던 목적지에 갈 수 있는지 없는지를 테스트한다는거잖아?
        // 이 경우는 한번 갔던 것을 체크 표시 하고 안 볼 수는 없을 것 같은데

        // 이거 재귀를 bool 반환하는 걸로 해서 있는지 없는지 물어보는 방식으로 가야 할까?
        // 아니 그냥 모른다 까지 포함해서 -1 0 1이렇게 반환하도록 할까?
        // 만약 자기 자신에 돌아가게 되면 그냥 모른다 반환 시키도록 
        
    }

    // 0 => 미방문, 1 -> 스택, 2 -> 완료

    bool dfs(vector<vector<int>>& graph, unordered_map<int, int>& state, int source, int destination)
    {
        if(state[source] != 0) return state[source] == 2;
        if(graph[source].size() == 0) return source == destination;

        state[source] = 1;

        for(int node : graph[source])
        {
            if(!dfs(graph, state, node, destination)) return false;
        }

        state[source] = 2;
        return true;
    }
};


