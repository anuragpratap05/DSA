#include<bits/stdc++.h>
using namespace std;

bool is_possible_to_place_all(vector<int> &stations, int k,double dist)
{
    int g=0;
    for(int i=1;i<stations.size();i++)
    {
        g+= stations[i]-stations[i-1];
        if(g>k)
        {
            return true;
        }
    }
    return false;
}


double minmaxGasDist(vector<int> &stations, int k)
{
    double si=0.0;
    double ei=1e9;

    while((ei-si)>1e-6)
    {
        double dis=(si+ei)/2.0;
        if(is_possible_to_place_all(stations,k,dis))
        {
            si=dis;
        }
        else
        {
            ei=dis-(1e-6);
        }
    }
    return si;
}

int main()
{
    return 0;
}