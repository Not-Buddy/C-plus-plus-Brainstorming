#include <bits/stdc++.h> 
using namespace std;

int GCD(int a, int b)
{

	int hcf{1};
	int maxed=max(a,b);
	for(int i{1};i<=maxed;i++)
	{
		if(a%i==0&b%i==0)
			hcf=i;
	}
return hcf;

}


int main()
{	

	int input{},upper{};
	std::string Input{};
	cin>>input;
	cin>>upper;

	cout<<"HCF of "<<input<<" and "<<upper
		<<" is "<<GCD(input,upper);


	return 0;
}

