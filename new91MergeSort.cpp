#include <iostream>
#include <vector>
using namespace std;
void merge(std::vector<int>& arr, int left, int mid, int right)
{
	int n1,n2;
	//Get the sizes of L1 and L2
	n1=mid-left+1;
	n2=right-mid;
	std::vector<int> L1(n1),L2(n2);
	//Add elements into the vector
	for(int i{0};i<n1;i++)
		L1[i]=arr[left+i];
	for(int j{0};j<n2;j++)
		L2[j]=arr[mid+j+1];

	int i=0,j=0;
	int k=left;

	//Merge Both Temporary L1 and L2 into Arr
	while(i<n1&&j<n2)
	{
		if(L1[i]<=L2[j])
		{
			arr[k]=L1[i];
			i++;
		}
		else
		{
			arr[k]=L2[j];
			j++;
		}
		k++;
	}
	//Add LeftOver L1 or L2 whichever
	while(i<n1)
	{
		arr[k]=L1[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		arr[k]=L2[j];
		k++;
		j++;
	}
}

void mergeSort(vector<int>& arr, int left, int right)
{
	if(left>=right)
		return;
	int mid=left+(right-left)/2;

	//Divide Part of the sort
	mergeSort(arr,left,mid);
	mergeSort(arr,mid+1,right);
	//Combine Part of the sort
	merge(arr,left,mid,right);
}

void printVector(std::vector<int> const arr)
{
	for(auto i:arr)
	{
		std::cout<<i<<' ';
	}
	std::cout<<std::endl;
}
int main()
{
	std::vector<int> vec{4,3,1,5,8,3,2,4};
	int n=vec.size();
	cout<<"Vector before merge Sort: ";

	printVector(vec);
	cout<<'\n';
	
	mergeSort(vec,0,n-1);
	cout<<"Sorted Array: ";
	printVector(vec);
	cout<<'\n';

	return 0;
}
