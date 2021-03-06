#include<iostream>
using namespace std;

bool isSafe(int board[][10],int i,int j,int n)
{
    //check for column
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            //can't place queen
            return false;
        }
    }

    //check for left diagonal
    int x=i;
    int y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            //there is a queen in the left daigonal
            return false;
        }
        x--;
        y--;
    }

    //check for right diagonal
    x=i;
    y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            //there is a queen in the right diagonal
            return false;
        }
        x--;
        y++;
    }

    //the position is now safe- checked for cols and diagonals
    return true;
}

bool solveNQueen(int board[][10],int i,int n)
{
    //base
    if(i==n)
    {
        //you have successfully placed queens in n rows(0...n-1)
        //print the board
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                {
                    cout<<"Q ";
                }
                else
                {
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    //rec
    //try to place the queen in the current row and call on the remaining part which will be solved by rec
    //iterate over all the cols of the current row
    for(int j=0;j<n;j++)
    {
        //check if i,j th position is safe to place the queen or not
        if(isSafe(board,i,j,n))
        {
            //place the queen-> assuming i,j is right position
            board[i][j]=1;
            bool nextQueenRakhPaaye=solveNQueen(board,i+1,n);
            if(nextQueenRakhPaaye)
            {
                return true;
            }
            //means i,j is not the right position->our assumption is wrong
            //backtrack-> to remove queen from there
            board[i][j]=0;
        }
    }
    //you have tried for all positions in the current row but could not place the queen
    return false;

}

int main()
{
    int n;
    cin>>n;
    int board[10][10]={0};
    solveNQueen(board,0,n);
    return 0;

}
