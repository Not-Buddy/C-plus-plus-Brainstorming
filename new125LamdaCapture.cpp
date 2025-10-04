#include <iostream>
using namespace std;
int main()
{
	int x = 5;
	int y = 3;
	//Lamda function that uses reference from outside variables
	auto sum1 = [&]() -> int {
	return x+y;
	};
	//Lambda function that takes copy of variables outside its scope
	auto sum2 = [=]() -> int {
	return x+y;
	};
	//Lamda function that takes function parameter and referenced input
	auto sum3 = [](int &a,int &b){
	return a+b;
	};
	//Lamda function that takes function parameter and copy function parameter
	auto sum4 = [](int a,int b){
	return a+b;
	};

	cout<<sum1()<<"\n";
	cout<<sum2()<<"\n";
	cout<<sum3(x,y)<<"\n";
	cout<<sum4(x,y)<<"\n";
	


	return 0;
}
