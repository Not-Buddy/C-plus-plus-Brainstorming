class Solution {
public:
    string decodeString(string s) {


        stack<int> countStack;
        stack<string> stringStack;

        string current_string = "";
        int current_num = 0;

        for(char c:s)
        {
            if(isdigit(c))
            {
                current_num = current_num * 10 + (c-'0');
            }
            else if(isalpha(c))
            {
                current_string += c;
            }
            else if(c=='[')
            {
                countStack.push(current_num);
                stringStack.push(current_string);

                current_num = 0;
                current_string = "";
            }
            else if(c==']')
            {
                int k = countStack.top();
                countStack.pop();

                string prev_string = stringStack.top();
                stringStack.pop();
                
                string decoded_chunk = "";
                for(int i{0};i<k;i++)
                {
                    decoded_chunk += current_string;
                }

                current_string = prev_string + decoded_chunk;

            }
        }
        return current_string;
    }
};
