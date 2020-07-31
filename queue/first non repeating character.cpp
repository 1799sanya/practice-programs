#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<char> q;
    int freq[27]={0}; //chars are mapped with index
    //running stream of characters
    char ch;
    cin>>ch;
    while(ch!='.')
    {
        //logic
        //insert into the queue and frequency table
        q.push(ch);
        freq[ch-'a']++;

        //query
        while(!q.empty())
        {
            int idx=q.front()-'a';
            if(freq[idx]>1)
            {
                q.pop();
            }
            else{
                cout<<q.front()<<" ";
                break;
            }
        }
        //queue is empty
        if(q.empty())
        {
            cout<<"-1 ";
        }
        cin>>ch;
    }
    return 0;
}
