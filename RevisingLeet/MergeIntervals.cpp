class Solution {
public:

    vector<int> Merger(const vector<int> v1,const vector<int> v2)
    {
        return {min(v1[0], v2[0]), max(v1[1], v2[1])};
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        for(int i{0};i<n-1;i++)
        {
            if(intervals[i][1]>=intervals[i+1][0])
            {
                vector<int> Merged = Merger(intervals[i],intervals[i+1]);
                intervals.erase(intervals.begin()+i);
                intervals.erase(intervals.begin()+i);
                intervals.insert(intervals.begin(),Merged);
                n--;
            }
        }
        return intervals;
    }
};
