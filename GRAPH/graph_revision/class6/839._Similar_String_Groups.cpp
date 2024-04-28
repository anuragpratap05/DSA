#include<bits/stdc++.h>
using namespace std;
// vector<int> par;
// vector<int> size;
// int maxsize=1;
// int find(int i)
// {
//     if(par[i]==i)
//     {
//         return i;
//     }
//     par[i]=find(par[i]);
//     return par[i];
// }

// void unite(int p1,int p2)
// {
//     if(size[p1]<size[p2])
//     {
//         par[p1]=p2;
//         size[p2]+=size[p1];
        
//     }
//     else{
//         par[p2]=p1;
//         size[p1]+=size[p2];
        
//     }
// }
// void find_and_unite(int u,int v)
// {
//     int p1=find(u);
//     int p2=find(v);
//     if(p1!=p2)
//     {
//         unite(p1,p2);
//     }
// }
bool swaps(string s1,string temp,int i,int j)
{
    temp[j]=temp[i];
    temp[i]=s1[i];
    if(temp==s1)
    {
        return true;
    }
    return false;
}
bool is_similar(string s1,string s2)
{
    if(s1.length()!=s2.length())
    {
        return false;
    }
    int i=0,j=0;
    while(s1[i]==s2[j])
    {
        i++;
        j++;
        if(i==s2.length() and j==s2.length())
    {
        
        return true;
    }
    }
    //cout<<i<<" "<<j<<endl;
    
    string temp=s2;
    for(;j<s2.length();j++)
    {
        if(s1[i]==s2[j])
        {
            if(swaps(s1,temp,i,j))
            {
                return true;
            }
            temp=s2;
        }
    }
    return false;
    //cout<<"i="<<i<<"  j="<<j<<endl;
    
}

bool is_similar2(string s1,string s2)
{
    int c=0;
    for(int i=0;i<s2.length();i++)
    {
        if(s1[i]!=s2[i] and ++c>2)
        {
            return false;
        }
    }
    return true;
    
}

// int numSimilarGroups(vector<string>& strs)
// {
//     int n=strs.size();
//     par.resize(n);
//     size.resize(n,1);
//     for(int i=0;i<n;i++)
//     {
//         par[i]=i;
//     }

//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(is_similar(strs[i],strs[j]))
//             {
//                 find_and_unite(i,j);
//             }
//         }
//     }
//     int c=0;
//     for(int i=0;i<n;i++)
//     {
//         if(par[i]==i)
//         {
//             c++;
//         }
//     }
//     return c;

// }

int main()
{
    // vector<string>vec={"jmijc","imjjc","jcijm","cmijj","mijjc"};
    vector<string>vec={"abc","abc"};
    int n=2;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(is_similar(vec[i],vec[j]))
            {
                cout<<" yes "<<i<<","<<j<<"  ";    
            }
            else{
                cout<<"    No   "<<i<<","<<j<<"  ";
            }
            
        }
        cout<<endl;
    }
    
    return 0;
}