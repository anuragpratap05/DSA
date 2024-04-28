#include<bits/stdc++.h>
using namespace std;


int numRabbits(vector<int>& answers)
{
    vector<int>vec(1001,0);
    int n=answers.size();
    int i=0;
    int ans=0;
    while(i<n)
    {
        int ele=answers[i];
        if(vec[ele]==0)
        {
            ans+=ele;
            ans+=1;
            vec[ele]=ele;
        }
        else{
            vec[ele]--;
        }
        i++;
    }       
    return ans; 
}

int main()
{
    return 0;
}