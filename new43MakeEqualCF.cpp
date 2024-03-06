#include <iostream>
#include <string>
using namespace std;
int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  int sum_solved{};
  for(int i{0};i<testcases;i++)
  {
    int container{},sum{};
    std::string input{};
    cin>>container;
    cin.ignore();
    int arr[container];
    getline(cin,input);
    int k{0};
    for(int j{0};j<input.size();j++)
    {
        std::string num{};
        int number{};
      while(std::isdigit(input[j]))
      {
        num.push_back(input[j]);
        j++;
      }
        number=std::stoi(num);
      arr[k]=number;
      k++;
    }
    //cout<<"TestCase: "<<i+1<<endl;
    if(container==1)
    {
      cout<<"YES"<<"\n";
    }
    else
    {
      int flag=0;
      for(int n:arr)
      {
        sum=n+sum;
      }
      int avg=sum/container;
      int remainder{};
      //cout<<"Sum: "<<sum<<" Container: "<<container<<" AvgFloat: "<<avg<<" AvgInt: "<<sum/container<<endl;
      for(int l{0};l<container;l++)
      {
        remainder=arr[l]-avg;
       // cout<<remainder<<endl;
          if(remainder>=0)
          {
            arr[l]=arr[l]-remainder;
            arr[l+1]=arr[l+1]+remainder;
          }
          else
            flag=1;
      }
      
      if(flag==1)
      {
        cout<<"NO"<<endl;
      }
      else
      {
        cout<<"YES"<<endl;
      }
    }  
  }
  return 0;
}
