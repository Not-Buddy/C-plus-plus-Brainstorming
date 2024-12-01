#include <stdio.h>
int main()
{

int Matrix1[2][2],Matrix2[2][2],Matrix[2][2];
  printf("Enter the value of Matrix\n");
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      printf("Enter the element %d %d\n",i,j);
      scanf("%d",&Matrix1[i][j]);    
    }
  }
  printf("Matrix1 Accepted\nThe Matrix 1 is:\n");
  
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      printf("%d ",Matrix1[i][j]);
    }
    printf("\n");
  }

  printf("Enter 2nd Matrix:\n");
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      printf("Enter the element %d %d\n",i,j);
      scanf("%d",&Matrix2[i][j]);    
    }
  }

  printf("Matrix2 Accepted\nThe Matrix 2 is:\n");

  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      printf("%d ",Matrix2[i][j]);
    }
    printf("\n");
  }
/*
 * 1 2    1 2 
 * 3 4    3 4
 *
 * 1*1+2*3 1*2+2*4
 * 3*1+4*3 3*2+4*4
 */
  int i=0;
  for(j)





  return 0;
}
