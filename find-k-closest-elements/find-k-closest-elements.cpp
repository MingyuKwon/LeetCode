class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        vector<int> ans;
        
        int left = 0;
        int right = n-1;
        
        int xIndex = findX(arr, x);
        if(xIndex < n && arr[xIndex] == x)
        {
            k--;
            ans.push_back(x);
            
            left = xIndex - 1;
            right = xIndex + 1;
        }else
        {
            left = xIndex - 1;
            right = xIndex;
        }
        
        while(k--)
        {
            if(left < 0)
            {
                ans.push_back(arr[right]);
                right++;
            }else if(right >= n)
            {
                ans.push_back(arr[left]);
                left--;
            }else
            {
                int leftGap = x - arr[left];
                int rightGap = arr[right] - x;
                
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
        }
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
    
    int findX(vector<int>& arr, int x)
    {
        int n = arr.size();
        
        int left = 0;
        int right = n-1;
        
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            
            if(arr[mid] == x)
            {
                return mid;
            }
            
            if(arr[mid] > x)
            {
                right = mid -1;
            }else
            {
                left = mid + 1;
            }
        }
        
        return left;
    }
};