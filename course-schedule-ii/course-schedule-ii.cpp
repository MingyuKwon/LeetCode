class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0); 

        vector<int> ans;

        for(vector<int> prerequisite : prerequisites)
        {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        queue<int> q;

        for(int i=0; i< numCourses; i++)
        {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty())
        {
            int current = q.front();
            q.pop();

            ans.push_back(current);

            for(int next : adj[current])
            {
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};