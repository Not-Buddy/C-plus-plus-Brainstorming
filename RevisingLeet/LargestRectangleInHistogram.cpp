class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
	    heights.push_back(0);
	    stack<int> st;
	    int maxArea = 0;
	    int n = heights.size();

	    for(int i{0}; i<n; i++)
	    {
		    while(!st.empty() && heights[i]<heights[st.top()])
		    {
			    int height = heights[st.top()];
			    st.pop();

			    int width = st.empty() ? i : i - st.top() - 1;

			    maxArea = max(maxArea, height * width);
		    }
		    st.push(i);
	    }
       return maxArea; 
    }
};
