#include <bits/stdc++.h> 
using namespace std;

int facto(int a)
{
	if(a==1)
		return 1;
	return a*facto(a-1);
}

int main()
{	

	//3!=3*2*1
	int input{},reverse{};
	std::string Input{};

	std::vector<int> loma{1,2,4,4,5,6,7,8,9,2,2,2,1,1,12,3};
	cin>>input;

	cout<<"Factorial of "<<input<<" :"<<facto(input);



	return 0;
}

