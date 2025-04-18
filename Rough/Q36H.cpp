#include <bits/stdc++.h> 
using namespace std;

int main()
{	

	int input{},input2{},reverse{};
	std::string Input{};

	cin>>input;

	std::vector<vector<int>>pascal(input);
	for(int i{0};i<input;i++)
	{
		pascal[i].resize(i+1);
		pascal[i][0]=pascal[i][i]=1;

		for(int j{1};j<i;j++)
			pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
		

	}

	for(int i{0};i<input;i++)
	{
		for(int j{0};j<input-i;j++)
			cout<<" ";
		for(int j{0};j<=i;j++)
			cout<<pascal[i][j]<<" ";
		cout<<endl;	
	}
		

//      1
//     1 1
//    1 2 1
//   1 3 3 1
//  1 4 6 4 1



	return 0;
}

