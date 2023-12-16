class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 만약 num의 크기가 1이라면 true 반환
        if(nums.size() == 1) return true;
        
    // ============================ 최소 점프 횟수도 계산하는 경우 ==============================================
        //vector<int> index(nums.size(), 100000);
        //index[0] = 0;

        //for(int i=0; i< nums.size(); i++){
            // 여기서 nums[i]를 뽑는다. 
        //    int canJumpableCount = nums[i];
            // 그리고 그 i + 값 한 곳의 인덱스까지 +1을 하고 +1을 한 것하고 현재 값 중 더 작은 것을 유지한다 
        //    for(int j=1; i+j<nums.size() && j<=canJumpableCount; j++)
        //    {
        //        index[i + j] =  min(index[i] + 1, index[i + j]);
        //    }
        //}

        // 제일 마지막이 100000인 경우면 == 외부에 의해서 변경 되지 않았따는 뜻인므로 false 반환 아니면 true 반환 
        //if(index[nums.size()-1] == 100000) return false;
        //return true;
    // ============================ 최소 점프 횟수도 계산하는 경우 ==============================================
        // 여기에 이동 가능한 최대 index를 기록한다
        int maxEnableindex= 0;
        // 이동하는 것이 n이하 다 갈수 있으므로, maxEnable 이하의 모든 점은 다 이동 가능하다
        for(int i=0; i< nums.size() && i<= maxEnableindex ; i++){
            // 각 인덱스 + 최대 갈 수 있는 거리를 갱신해준다
            maxEnableindex = max(maxEnableindex, i + nums[i]);
        }
        // 최종적으로 maxEnableindex가 nums.size()-1 미만이면 false

        if(maxEnableindex < nums.size()-1)
        {
            return false;
        }else
        {
            return true;
        }
    
    }
};