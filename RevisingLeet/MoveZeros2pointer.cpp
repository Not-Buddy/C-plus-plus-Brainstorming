class Solution
{
        public:
                void moveZeroes(vector<int> &nums)
                {
                        int writePos = 0;
                        for(int i{0};i<nums.size();i++)
                        {
                                if(nums[i]!=0)
                                        nums[writePos++] = nums[i];
                        }

                for(int i = writePos; i< nums.size();i++)
                {
                        nums[i] = 0;
                }
                }

};
