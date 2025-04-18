#include <bits/stdc++.h> 
using namespace std;


void maxmin(const std::vector<int> loma, int &max,int &min)
{
	max=0;
	min=INT_MAX;
	int n=loma.size();
	for(int i{0};i<n;i++)
	{
		if(max<loma[i]) max=loma[i];
		if(min>loma[i]) min=loma[i];
	}
}


int main()
{	

	int input{},reverse{};
	std::string Input{};

	std::vector<int> loma{1,2,4,4,5,6,7,8,9,2,2,2,1,1,12,3};

	int max{},min{};
	maxmin(loma,max,min);

	cout<<"Max: "<<max<<"\n";
	cout<<"Min: "<<min<<"\n";

	return 0;
}

