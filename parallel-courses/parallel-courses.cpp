class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        // index 1이다 감안하자
        vector<vector<int>> graph(n+1);
        vector<int> indegree(n+1);

        for(vector<int> relation : relations)
        {   
            graph[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }

        queue<int> bfsQ;
        for(int i=1; i<=n; i++)
        {
            if(indegree[i] == 0) bfsQ.push(i);
        }

        int nodes = 0;
        int level = 0;

        while(!bfsQ.empty())
        {
            level++;
            int count = bfsQ.size();
            nodes += count;

            while(count--)
            {
                int current = bfsQ.front();
                bfsQ.pop();

                for(int next : graph[current])
                {
                    indegree[next]--;
                    if(indegree[next] == 0) bfsQ.push(next);
                }
            }
        }

        return nodes == n ? level : -1;
    }
};