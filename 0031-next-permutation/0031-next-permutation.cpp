class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1) return;

        int ascendingIndex = -1;
        int descendingIndex = -1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1] >= nums[i])
            {
                descendingIndex = i;
            }else
            {
                ascendingIndex = i;
            }
        }

        if(ascendingIndex  == nums.size()-1) // 오름차순으로 끝나 경우
        {// 맨 뒤 2개를 바꿔주기만 하면 된다
            swap(nums[ascendingIndex], nums[ascendingIndex-1]);
        }else // 내림차순으로 끝난 경우
        {
            if(ascendingIndex == -1) 
            {
                sort(nums.begin(), nums.end());
            }else
            {
                sort(nums.begin() + ascendingIndex, nums.end());
                for(int i=ascendingIndex; i<nums.size(); i++)
                {
                    if(nums[ascendingIndex-1] < nums[i])
                    {
                        swap(nums[ascendingIndex - 1], nums[i]);
                        sort(nums.begin() + ascendingIndex, nums.end());
                        break;
                    }
                }
            }
        }

    }

    // swap은 값을 서로 교환하는 함수. 다만 vector 같은 컨테이너는 아예 컨테이너 채로 바꿔준다(내부적으로 주소값 교환 일어남)
    // ** 중요한 것은 asceding index는 ascending의 끝이기도 하지만 descending의 시작이기도 하다!!!! 이거 빼먹었다가 엄청 헤멨다
    
    // purmutation의 핵심은, 이 순열은 전부 오름차수이엇더 순열을 내림차순으로 바꾸는 과정이란 것이다 
    // 오름차순 ->내림차순 -> 오름차순 순으로 반복이되고, 핵심은 뒤에서 부터 2번쨰와 맨 뒤의 정렬 순서이다
    // 만약 오름차순으로 끝났다면 그냥 맨 뒤 2개를 바꾸기만 하면 된단
    // 만약 내림차순으로 끝낫다면, (내림차순 바로 앞 수(ascending-1)보다 큰 수중 가장 작은 수)를 뽑아서 그 수와 
    // asceding - 1을 교환하고, ascending ~ 마지막 부분을 오름차순 정렬 시키면 된다
    
    // 만약 모두 오름차순이어서 ascending이 한번도 움직이지 않아 -1이라면 그냥 전체를 오름차수 정렬한다
    
    
    
    // 다른 풀이 들을 보다보니 핵심은 이걷
    // 1. 오름차순을 만족하는 최대의 i를 찾느다
    // 2. i 이후 모든 배열을 뒤집는다 (i 이후는 다 내림차순이란 소리다)
    // 3. 그렇게 뒤집은 배열중에, i가 0이 아니라면, nums[i]에 해당하는 수보다 큰 수중 가장 작은수와 nums[i]를 바꾼다
    
    
    // 핵심은 비슷하지만 이 편이 구현하기에도 더 간단하고, 생각이 꼬일 염려도 없으니 이 단순한 풀이로 기억해보자
};