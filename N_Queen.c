#include<stdio.h>
#include<stdlib.h>

int is_safe(int row,int col,int N,int b[N][N])
{
    for (int i = 0; i < row;i++)   // check for columns
    {
        if(b[i][col]==1)
        {
            return 0;
        }
    }
    
    // check for left diagonal
    int k = row - 1;
    int j= col-1;
    while (k>0 && j>0)  
    {
        if(b[k][j]==1)
        {
            return 0;
        }
        k--;
        j--;
    }

    //check for right diagonal
    k = row - 1;
    j = col + 1;
    while (k > 0 && j < N)
    {
        if (b[k][j] == 1)
        {
            return 0;
        }
        k--;
        j++;
    }
    return 1;
}

int N_Queen(int row,int N, int b[N][N])
{
    if (row>=N)    //base case
        return 1;  //to print all the solution just call print_possible() every time the base case satisify

    for (int i = 0; i < N;i++)
    {
        if (is_safe(row,i,N,b)==1)
        {
            b[row][i] = 1;
        
            if (N_Queen(row+1, N, b)==1)
            {
                return 1;
            }
            b[row][i] = 0;
        }
    }
    return 0;
}


int print_position(int N,int b[N][N])
{
    printf("Queen NO.\tPosition\n");
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N;j++)
        {
            if (b[i][j] == 1)
            {
                printf("%d\t\t(%d,%d)\n", i+1, i, j);
                break;
            }
            //printf("%d\n", b[i][j]);
        }
    }
}




int main()
{
    int N;
    scanf("%d", &N);
    int b[N][N];
    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N;j++)
        {
            b[i][j] = 0;
        }
    }
        
    if(N_Queen(0, N, b)==1)
    {
        printf("Possible\n");
        print_position( N,b);
    }
    else
    {
        printf("Not Possible\n");
    }

    return 0;
}