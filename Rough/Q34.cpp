#include <bits/stdc++.h> 
using namespace std;

int ProductAllDigits(int n)
{
	int sum{1};
	while(n!=0)
	{
		int digit=n%10;
		sum*=digit;
		n/=10;
	}
	
	return sum;
}

int main()
{	

	int input{},reverse{};
	std::string Input{};

	std::vector<int> loma{1,2,4,4,5,6,7,8,9,2,2,2,1,1,12,3};
	cin>>input;

	cout<<"Product of all digits of "<<input<<" is "<<ProductAllDigits(input)<<"\n";



	return 0;
}

