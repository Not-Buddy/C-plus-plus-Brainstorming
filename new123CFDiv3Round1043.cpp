#include <bits/stdc++.h>
using namespace std;	

int main()
{	

	int t{};
	cin>>t;
	cin.ignore();
	while(t--)
	{
		int n1{},n2{};
		cin>>n1;
		cin.ignore();
		std::string input1{};
		getline(cin,input1);
		
		cin>>n2;
		cin.ignore();
		std::string input2{},input3{};
		getline(cin,input2);
		getline(cin,input3);
		
		int j{0};
		for(int i{0};i<input3.size();i++)
		{
			char VorD=input3[i];
			if(VorD=='V')
			{
				input1.insert(input1.begin(), input2[j]);	
					j++;
			}
			else
			{
				input1.push_back(input2[j]);
				j++;
			}
		}

		cout<<input1<<"\n";

		

	}

	
	return 0;
}
