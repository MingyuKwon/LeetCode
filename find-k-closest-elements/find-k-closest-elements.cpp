class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        
        int right = findX(arr, x);
        int left = right - 1;

        while(k--)
        {
            if(left < 0) 
            {
                ans.push_back(arr[right]);
                right++;
                continue;
            }

            if(right >= n) 
            {
                ans.push_back(arr[left]);
                left--;
                continue;
            }

            int leftGap = abs(arr[left]- x);
            int rightGap = abs(arr[right]- x);

            if(leftGap <= rightGap)
            {
                ans.push_back(arr[left]);
                left--;
            }else
            {
                ans.push_back(arr[right]);
                right++;
            }
        }

        sort(ans.begin(), ans.end());
        
        return ans;
    }

    int findX(vector<int>& arr, int x)
    {
        int left = 0;
        int right = arr.size() - 1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(arr[mid] < x)
            {
                left = mid + 1;
            }else
            {
                right = mid - 1;
            }
        }

        return left;
    }
    
    
};