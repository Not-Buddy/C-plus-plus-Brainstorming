#include <iostream>
using namespace std;
  void fun1(int n)
  {
    if(n>0)
    {
      printf("%d",n);
      fun1(n-1);
    }
  }
int main()
{
//  If a function is calling itself then its called a recursion function
//  and if the condition inside the function is true then it will stop
//  there can be variations of the recursion 
//  it can either be triggered when a condition is false and keep running
//  till the condition is false 
//  or else it can be the other way around triggered when the condition is true
//  and come out when the condition is false
//  Tracing the Recursion 
//

  int x=3;
  fun1(x);
//  You can trace a recursive function using a tree like structure
//  for easier understanding of the code a tree is used to trace the 
//  Recursion
//
//  Generalising the recursion 
//
//  Comparing recursion with loops
//  the difference betwween them is that a loop will only have ascending phase
//  Recursion can also have a descending phase
//
//  How Recursion uses stack 
//  Memory layout below for How Recursion uses stack
//  Heap:-
//  Nothing here xD
//
//
//
//  Stack:- (Size of the stack is 4) (The total memory consumed
//  here is in order of n O(n)) (Recursive functions are memory
//  consuming functions like the consume a ton of memory)
//  x is created      
//  n is created for 3
//  2nd call n is made 2
//  then 3rd call n is made to 1
//  then 4th call n is made to 0 once the function is ended
//  this 0 activation call is deleted 
//  
//
//
//  Code:-
//  fun1
//  stack
//
//  The time Complexity of the Recursion 
//  Analysis of the time complexity of the recursion
//  we measure time in units of time
//
//  In the above example the function is just printing a integer
//  Count the amount of times it is printing the integer
//  In the example it is printing it thrice thus we conclude that
//  it is printing for 3 units of times
//  Thus the time taken will be n unit of time This the time
//  complexity of this program is O(n)
//  Every recursive function can
//  be written as a recursion and every loop can be writtenas a recursion
//  Who is more efficient 
//  The time taken by both of them is O(n) 
//  Recursive function uses the stack  Thus space taken by recursionis O(n)
//  While for the loop Space taken is O(1)
//  Thus Loops are more efficient  
//  
//  If the function is calling itself only once then its a Linear
//  Recursion function
//
//  If a Recusive function is callint itself more than one time then
//  its called a tree recursion Lmao this shit is Complex.
//
//
//
//

  return 0;
}
