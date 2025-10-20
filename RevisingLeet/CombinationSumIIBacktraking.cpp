class Solution {
public:
    std::vector<vector<int>> Answer{};

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         Answer.clear();
         sort(candidates.begin(),candidates.end());
         vector<int> temp{};
         solve(0,candidates,temp,target);
         return Answer;
    }
    void solve(int start,vector<int> &arr,vector<int> &temp,int target)    
    {
        if(target == 0)
        {
            Answer.push_back(temp);
            return;
        }
        if(target<0)
            return;
        
        for(int i=start;i<arr.size();i++)
        {
            if(i>start && arr[i]==arr[i-1])
                continue;

            if(arr[i] > target)
                break;
            temp.push_back(arr[i]);
            solve(i+1,arr,temp,target-arr[i]);
            temp.pop_back();
        }

    }
};
