#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <climits>

using namespace std;
bool compare (int a ,int b)
{
  return a>b;
}

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


int main() 
{
    int testcases{};
    cin >> testcases;
    cin.ignore(); 
    std::vector <int> answer{};
    for (int i = 0; i < testcases; i++) 
    {
        int arr_size;
        cin >> arr_size;
        cin.ignore();
        int arr[arr_size];

        string line;
        getline(cin, line);

        arrayMaker(line, arr_size, arr);

        int sum{0},size=sizeof(arr)/sizeof(arr[0]);

        for (int j{0};j<arr_size;j++)
        {
          arr[j]+=1+j;

        }
          std::sort(arr,arr+size,compare);
          for(int n:arr)
          {
            cout<<n<<" ";
          }
          cout<<"\n";

    }
    return 0;
}

