#include <iostream>
using namespace std;
int main()
{
  //First time complexity is n This takes the longest
  //   For eg:int arr[n]={} if we are iterating through
  //          this 1 by 1 then the time complexity is O(n)
  //
  //        A For Loop is probably taking O(n) Time
  //          As it iterates through everything 
  //
  //    For eg:There is another int arr[n]={}
  //        and you are checking Each element with all the other 
  //        Elements That means the time complexity will be
  //        O(n^2) as it is comparing all the other things with 
  //        each other
  //
  //    Below is an example for O(log2n)
  //    For eg:There is another int arr[n]={}
  //    basically this array is sorted and now you are searching
  //    through this by taking the middle element and halfing it
  //    and then again taking the middle and halfing it 
  //    this has the time complexity of O(log2n)
  //
  //    Matrix has an Time complexity of O(n^2)
  //    
  //    Array of linked list O(m+n) if you consider the array then its O(m+n)
  //    or else it will be just O(n)
  //    
  //    Binary tree has time complexity of log n to the base 2 O(logn)
  //    Along the height of the tree is the time complexity of a tree
  //
  //    The time complexity is solely depended on the work that you are doing
  //
  //    To find the time complexity of the funtion you gotta analyse the program
  //    completely and assign n to the lines at the end the sum of the n's will 
  //    be the time complexity function of the program
  //
  //    If there is a loop inside the loop the time complexity will
  //    get multiplied n*namespace  
  //    O(n) we can call it the order of or the Big other
  //    
  return 0;
}
