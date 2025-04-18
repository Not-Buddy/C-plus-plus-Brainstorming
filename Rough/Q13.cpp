#include <bits/stdc++.h> 
using namespace std;


int Max(const int a,const int b,const int c)
{
	if(a>b&&a>c)
		return a;
	else if(b>c&&b>a)
		return b;
	else 
		return c;

}
int main()
{	

	//5 5*4*3*2*1
	int facto{};
	int sum{};
	int l{5},m{2},n{6};
	cout<<Max(l,m,n)<<"\n";



	return 0;
}

