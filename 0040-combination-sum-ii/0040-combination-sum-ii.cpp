class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        Recursive(result, candidates, {} , target, 0);
        return result;
    }

    void Recursive(vector<vector<int>>& result, vector<int>& candidates, vector<int> used, int target, int startIndex)
    {
        if(target == 0)
        {
            result.push_back(used);
            return;
        }

        for(int i=startIndex; i<candidates.size();)
        {
            int candidate = candidates[i];
            int count = 1;

            int k = i;
            while( k + 1 < candidates.size() && candidates[k] == candidates[k+1])
            {
                count++;
                k++;
            }

            int countFix = count;
            count = 1;
            while(count <= countFix && (count * candidate <= target))
            {
                for(int j = 0; j < count; j++)
                {
                    used.push_back(candidate);
                }
                Recursive(result, candidates, used, target - count * candidate, i + countFix);
                for(int j = 0; j < count; j++)
                {
                    used.pop_back();
                }
                count++;
            }
            
            i += countFix;
            
        }
    }
    
};