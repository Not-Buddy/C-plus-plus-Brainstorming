#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n{};
    cin >> n;
if(n%2==0)
{
    vector<int> vec(n); 

    for (int i = 0; i < n; i++) {
        vec[i] = i+1;
    }

    // Output the values
    for(int k=0;k<n;k=k+2)
    {
      int c{};
      c=vec[k];
      vec[k]=vec[k+1];
      vec[k+1]=c;
    }
    for (int j = 0; j < n; j++) {
        cout << vec[j] <<' ';
    }

}
else 
{
  cout<<-1<<endl;
}
    return 0;
}

