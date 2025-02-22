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

        while(!pq.empty())
        {
            auto[weight, destination] = pq.top();
            pq.pop();

            if(minTime[destination] < weight) continue;

            minTime[destination] = weight;

            for(pair<int, int> edge : graph[destination])
            {
                int newWeight = weight + edge.second;
                if(minTime[edge.first] > newWeight) 
                {
                    minTime[edge.first] = newWeight;
                    pq.push({newWeight, edge.first});
                }
            }

        }

        int maxVal = 0;
        for(int i =1; i<=n; i++)
        {
            maxVal = max(maxVal, minTime[i]);
        }

        return maxVal == INT_MAX ? -1 : maxVal;
        
	}
};
