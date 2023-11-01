class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        Recursive(result, candidates, {} , target);
        return result;
    }

    void Recursive(vector<vector<int>>& result, vector<int>& candidates, vector<int> used, int target)
    {
        if(target == 0)
        {
            result.push_back(used);
            return;
        }

        int lastUsed = (used.size() == 0) ? -1 : used[used.size()-1];
        for(int i=0; i<candidates.size(); i++)
        {
            int candidate = candidates[i];
            if(candidate < lastUsed) continue;

            if(candidate > target){
                break;
            }else
            {
                used.push_back(candidate);
                Recursive(result, candidates, used, target - candidate);
                used.pop_back();
            }
        }
    }
    
    
    // 이 문제는 푸는 것은 매우 쉬웠다
    // 근데 문제는 벡터를 다루는 것이 빡셌다. 
    
    // 1. 벡터를 &으로 넘겨주게 되면 편집이 가능해 짐과 동시에 그 벡터는 주소에 의한 참조로 여겨진다
    //    따라서 이걸 값에 의한 전달로 보고, 이 벡터를 벡터의 벡터에 넣는 등의 행위는 하기가 매우 까다로워 진단
    //    만약 벡터들의 벡터를 만들일이 있다면 가능한 값에 의한 참조로 벡터들을 주고 받자
    
    // 2. 벡터에서 인수를 지우는 방법은 여러가지가 있지만, pop_back()이 마지막 원소를 지워주는 함수이다
    //    비교적 마지막 원소를 지워야 할 상황이 많이 오니, 이 함수는 기억해 두고 있자
    
    // 3. 벡터는 생성을 {}를 이용해서도 할 순 잇는데, 이 {} 연산은 기초적인 생성 밖에 못한다.
    //    {1 , {}} 같은 고급화 연산은 불가능 하므로 이점 참고하자
 
};