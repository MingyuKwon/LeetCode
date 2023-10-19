class Solution {
public:
    int maxArea(vector<int>& height) {
        int SIZE = height.size();
        int MAX = 0;

        int left = 0;
        int right = SIZE-1;
        
        while(left < right)
        {
            int areaSize = min(height[left] ,height[right]) * (right - left);
            MAX = max(areaSize, MAX);

            if(height[left] > height[right])
            {
                right--;
            }else
            {
                left++;
            }
        }


        return MAX;
        // Increasing the width of the container can only lead to a larger area if the height of the new boundary is greater. By moving the pointers towards the center, we explore containers with the potential for greater areas.

        // 이 문제의 핵심은 둘 중 높이가 작은 쪽에 귀속 된다는 것이다.
        // 아무리 기존의 높이보다 큰 높이가 오더라도, 높이는 기존에 있던 높이에서 정해지게 된다
        // 1. 넓이는 높이 * 너비 이므로, 시작을 최대 너비로 시작한다.
        // 2. 그리고, 너비를 줄여나가는데, 우리는 최대 넓이 값을 찾아야 하므로 너비가 줄어들어도
        // 높이가 증가해서 넓이가 증가 할 경우를 찾아야 한다. 따라서 높이가 높은 쪽으로 쫓아 가야 
        // 이러면 우리가 보고 있는 substring이 해당 길이를 가지는 substring 중에서 최대 길이는 아닐 수 있다 하지만, 우리는 이미 만들어진 max보다 더 큰 값을 찾아 나서는 것이기 때문에 문제는 없다

    }
};