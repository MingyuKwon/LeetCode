class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Distance from source to all other nodes.
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        k++;

        while(k--)
        {
            vector<int> temp(dist);
            for(vector<int>& flight : flights)
            {
                if(dist[flight[0]] == INT_MAX) continue;
                int newDist = dist[flight[0]] + flight[2];
                temp[flight[1]] = min(temp[flight[1]], newDist);
                
            }
            
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
