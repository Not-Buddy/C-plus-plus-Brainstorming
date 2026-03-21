class Solution {
public:
    string maximumBinaryString(string binary) {
       int n = binary.length();
       int first_zero = -1;
       int zeros_count = 0;
       for(int i{0};i<n;i++)
       {
	       if(binary[i]=='0')
	       {
		       if(first_zero==-1)
		       {
			       first_zero=i;
		       }
		       zeros_count++;
	       }
       }

       if(zeros_count<=1)
       {
	       return binary;
       }

       string result(n,'1');
       result[first_zero+zeros_count-1] = '0';
       
       retun result;
    }
};
