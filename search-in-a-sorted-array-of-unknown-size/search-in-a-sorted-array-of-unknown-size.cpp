/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        // 아니 시발 끝도 모르는데 어떻게 탐색을 해
        
        int left = 0;
        int right = 10000;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            int value = reader.get(mid);

            if(value == INT_MAX)
            {
                right = mid -1;
            }else
            {
                if(value == target)
                {
                    return mid;
                }

                if(value > target)
                {
                    right = mid - 1;
                }else
                {
                    left = mid + 1;
                }
            }

        }

        return -1;
    }
};