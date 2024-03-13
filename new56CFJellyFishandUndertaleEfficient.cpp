#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;
void vectormaker(std::vector <ll>&vec1,std::string input)
{
  std::string digit{};
  for(ll i{0};i<input.size();i++)
  {
    while(std::isdigit(input[i]))
    {
      digit.push_back(input[i]);
      i++;
    }
    vec1.push_back(std::stoull(digit));

    digit.clear();
  }
}
void ArrayDisplay(std::vector <ll> const vec1)
{
  cout<<"{ ";
  for(ll i:vec1)
  {
    cout<<i<<" ";
  }
  cout<<"}"<<endl;
}
int main()
{
  int testcases{};
  cin>>testcases;
  cin.ignore();
  for(int i{0};i<testcases;i++)
  {
    ll a{},b{},n{},tot_sec{1};
    std::string input{};
    std::vector <ll> vec1{};
    cin>>a>>b>>n;
    cin.ignore();
    getline(cin,input);
    vectormaker(vec1,input);
    //cout<<"a:"<<a<<" b:"<<b<<" n:"<<n<<endl;

    for(b;b>0;b--)
    {
        if(b>1)
        {
          ll diff=b-1;
          tot_sec+=diff;
          b=1;
          //cout<<"Sec Passed: "<<tot_sec<<endl;
        }
       //cout<<"Sec Passed: "<<tot_sec<<" b value: "<<b<<endl;
       tot_sec++;
       if(b==1)
       {
        auto min_element_iterator=std::min_element(vec1.begin(),vec1.end());
        //std::cout<<*min_element_iterator<<" Used"<<endl;
        if(min_element_iterator!=vec1.end())
        {
          b+=*min_element_iterator;
         // cout<<"Used "<<*min_element_iterator<<" from: ";
          //ArrayDisplay(vec1);
          vec1.erase(min_element_iterator);
        }
        else 
        {
          *min_element_iterator=0;  
        }
        if(b>a)
        {
          //cout<<"b set to a: "<<a<<endl;
          b=a;
        }
       }
      //vec1.erase(std::remove(vec1.begin(),vec1.end(),*min_element_iterator),min_element_iterator);
        

    }
    //cout<<"Total_Seconds: "<<tot_sec-1<<endl;
    cout<<tot_sec-1<<endl;

    //for(auto val:vec1)
    //{
     // cout<<"Vecprinting: "<<val<<endl;
    //}

  }
  return 0;
}
