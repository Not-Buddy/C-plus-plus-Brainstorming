#include <iostream>
#include <array>
#include <vector>
using namespace std;
int BinSearch(std::vector<int> arr,int low ,int high,int val)
{
	if(high>=low)
	{
		int mid=low+(high-low)/2;

		if(arr[mid]==val)
			return mid;
		if(arr[mid]<val)
		{
			return BinSearch(arr,mid-1,high,val);
		}
		return BinSearch(arr,low,mid,val);
	}
	return -1;
}





int main()
{
	std::vector<int> arr{1,2,3,4,5,6,7,8,9,10};

	int i = BinSearch(arr,0,arr.size(),3);
	cout<<"We found the value at index: "<<i<<endl;
	return 0;
}
