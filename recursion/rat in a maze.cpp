#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[][10],int i,int j,int m,int n)
{
    //base
    if(i==m && j==n)
    {
        soln[i][j]=1;
        //print the path
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    //rec
    //rat should be inside grid
    if(i>m || j>n)
    {
        return false;
    }
    if(maze[i][j]=='X')
    {
        return false;
    }
    //assume solution exists through current cell
    soln[i][j]=1;
    bool rightSuccess=ratInMaze(maze,soln,i,j+1,m,n);
    bool downSuccess=ratInMaze(maze,soln,i+1,j,m,n);

    //backtracking
    soln[i][j]=0;

    if(rightSuccess || downSuccess)
    {
        return true;
    }
    return false;
}

int main()
{
    char maze[10][10]={"0000","00X0","000X","0X00"};
    int soln[10][10]={0};
    int m=4;
    int n=4;

    bool ans=ratInMaze(maze,soln,0,0,m-1,n-1);
    if(ans==false)
    {
        cout<<"path does not exist";
    }
    return 0;
}
