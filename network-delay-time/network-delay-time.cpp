class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);

        for(vector<int> time : times)
        {
            graph[time[0]].push_back({time[1], time[2]}); // destination, weight
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // weight, destination 
        pq.push({0, k});

        vector<int> minTime(n+1, INT_MAX);
        minTime[0] = 0;
        

        while(!pq.empty())
        {
            auto[weight, destination] = pq.top();
            pq.pop();

            if(minTime[destination] != INT_MAX) continue;
            minTime[destination] = weight;

            for(pair<int, int> edge : graph[destination])
            {
                pq.push({edge.second + weight, edge.first});
            }

        }

        int maxVal = 0;
        for(int i : minTime)
        {
            maxVal = max(maxVal, i);
        }

        return maxVal == INT_MAX ? -1 : maxVal;
        
	}
};
