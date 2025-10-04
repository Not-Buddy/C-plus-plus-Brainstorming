#include <iostream>
using namespace std;
int main()
{
	//[capture] (parameters) {body}
	auto message = [] () {
	cout<<"Hello world\n";
	};
	message();
	return 0;
}

