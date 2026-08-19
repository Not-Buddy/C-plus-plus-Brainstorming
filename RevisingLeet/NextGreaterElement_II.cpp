#include <vector>
#include <stack>

//weird iterator i made for fun to solve the two times iterating problem
class TwiceCircularIterator
{
    private:
        const std::vector<int> &nums;
        int n;
        int step;
        int maxSteps;

    public:
        TwiceCircularIterator(const std::vector<int> &input_nums)
            : nums(input_nums), n(input_nums.size()), 
            step(0), maxSteps(2 * input_nums.size()) {}

    bool hasNext() const{
        return step < maxSteps;
    } 

    int getValue() const {
        return nums[step % n];
    }

    int getRealIndex() const {
        return step % n;
    }

    bool isFirstPass() const {
        return step < n;
    }

    void advance() {
        step++;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, -1);
        std::stack<int> st;

        TwiceCircularIterator it(nums);

        while(it.hasNext()){
            int val = it.getValue();
            int idx = it.getRealIndex();

            while(!st.empty() && nums[st.top()] < val){
                ans[st.top()] = val;
                st.pop();
            }
            if(it.isFirstPass()){
                st.push(idx);
            }
            it.advance();
        }
    return ans;
    }
};
