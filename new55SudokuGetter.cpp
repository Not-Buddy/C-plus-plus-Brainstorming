#include <iostream>
using namespace std;
void printboard(int const board[9][9])
{
  for(int i{0};i<9;i++)
  {
    for(int j{0};j<9;j++)
    {
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main()
{
  int board[9][9];
  for(int i{0};i<9;i++)
  {
    for(int j{0};j<9;j++)
    {
      cout<<"Enter ROW:"<<i<<" COLUMN:"<<j<<endl;
      cin>>board[i][j];
    }
  }
  printboard(board);
  return 0;
}
