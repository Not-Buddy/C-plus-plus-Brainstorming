#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <climits>

using namespace std;

void arrayMaker(const std::string& line, int arr_size, int arr[]) 
{
    std::string num;
    int j = 0;
    for (int i = 0; i < line.size(); i++) 
    {
        if (std::isdigit(line[i])) 
        {
            while (std::isdigit(line[i])) 
            {
                num.push_back(line[i]);
                i++;
            }
            arr[j] = std::stoi(num);
            num.clear(); // Clear the string for the next number
            j++;
        }
    }
}

void maxmin(int arr[],int arr_size,int &max,int &min)
{
  max=0;
  min=INT_MAX;
  for(int i{0};i<arr_size;i++)
  {
    if(max<=arr[i])
      max=arr[i];
    if(min>=arr[i])
      min=arr[i];
  }
  if(min==INT_MAX)
    min=0;
}

int main() 
{
    int testcases;
    cin >> testcases;
    cin.ignore(); // Ignore the newline character after reading an integer
    std::vector <int> answer{};
    for (int i = 0; i < testcases; i++) 
    {
        int arr_size;
        cin >> arr_size;
        int arr[arr_size];
        cin.ignore(); // Ignore the newline character after reading an integer

        string line;
        getline(cin, line);

        arrayMaker(line, arr_size, arr);
        int max{},min{};
        maxmin(arr,arr_size,max,min);
        answer.push_back(max-min);
    }
    for(int n:answer)
    {
      cout<<n<<"\n";
    }
    return 0;
}

