//car sorting problem
//problem statement-> take in the coordinates of n cars and find distance from them if you are at the origin
//get the sorted order of cars
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    //accepts 2 pairs of coordinates which we want to compare
    //distance of a car from origin=square root of (x^2 + y^2)
    int d1= p1.first*p1.first + p1.second*p1.second;
    int d2= p2.first*p2.first + p2.second*p2.second;
    if(d1==d2)
    {
        return p1.first<p2.first;
        //if same distances return the car which has lower x coordinate
    }

    return d1<d2; //return the car which has less distance from you that is origin
}

int main()
{
    int n;
    cin>>n; //no of cars
    vector<pair<int,int>> v;

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end(),compare); //compare-> to compare the positions of 2 cars

    for(auto p:v)
    {
        cout<<"car "<<p.first<<","<<p.second<<endl;
    }

    return 0;
}
