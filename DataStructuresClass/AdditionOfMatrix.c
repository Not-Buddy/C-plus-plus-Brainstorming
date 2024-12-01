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

  int choice;
  printf("Enter 1 if you want to add Matrix\nEnter 2 if you want to Multiply Matrix\n");
  scanf("%d",&choice);

  if(choice == 1)
  {
    for(int i=0;i<2;i++)
    {
      for(int j=0;j<2;j++)
      {
        Matrix[i][j]=Matrix1[i][j]+Matrix2[i][j];
      }
    }

    for(int i=0;i<2;i++)
    {
      for(int j=0;j<2;j++)
      {
        printf("%d ",Matrix[i][j]);
      }
      printf("\n");
    }
  }
  else if(choice == 2)
  {
    for(int i=0;i<2;i++)
    {
      for(int j=0;j<2;j++)
      {
        Matrix[i][j]=Matrix1[i][j]*Matrix2[i][j];
      }
    }
    for(int i=0;i<2;i++)
    {
      for(int j=0;j<2;j++)
      {
        printf("%d ",Matrix[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
