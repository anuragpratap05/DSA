#include<bits/stdc++.h>
using namespace std;

 struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };
vector<int> par;
vector<int> size;
int maxsize=1;
int find(int i)
{
    if(par[i]==i)
    {
        return i;
    }
    par[i]=find(par[i]);
    return par[i];
}

void unite(int p1,int p2)
{
    if(size[p1]<size[p2])
    {
        par[p1]=p2;
        size[p2]+=size[p1];
        
    }
    else{
        par[p2]=p1;
        size[p1]+=size[p2];
        
    }
}
 vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
    par.resize(n*m);
    size.resize(n*m,1);
    for(int i=0;i<n*m;i++)
    {
        par[i]=i;
    }
    int no=0;
    vector<int>ans;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int nt=operators.size();
    for(int x=0;x<nt;x++)
    {
        
        int i=operators[x].x;
        int j=operators[x].y;
        if(vis[i][j])
        {
            ans.push_back(no);
            continue;
        }
        int u=i*m+j;
        vis[i][j]=true;
        no+=1;
        for(vector<int>& vec:dir)
        {
            int r=i+vec[0];
            int c=j+vec[1];
            if(r>=0 and c>=0 and r<n and c<m and vis[r][c])
            {
                int v=r*m+c;
                int p1=find(u);
                int p2=find(v);
                if(p1!=p2)
                {
                    unite(p1,p2);
                    no--;
                }
                
                
            }
            
        }
        ans.push_back(no);
    }
    return ans;
//         vector<vector<int>> vis(n,vector<int>(m,0));
//     par.resize(n*m);
//     for(int i=0;i<n*m;i++)
//     {
//         par[i]=i;
//     }
//     vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
//     vector<int> vec;

//     int count=0;
//     for(int i=0;i<operators.size();i++)
//     {
        
        
//         int sr=operators[i].x;
//         int sc=operators[i].y;
//         if(vis[sr][sc]==1)
//         {
//             vec.push_back(count);
//             continue;
//         }
//         vis[sr][sc]=1;
//         count++;

//         int v=sr*m+sc;
//         int p1=find(v);

//         for(vector<int>& d:dir)
//         {
//             int r=sr+d[0];
//             int c=sc+d[1];
//             if( r>=0 and c>=0 and r<n and c<m and   vis[r][c]==1)
//             {
//                 int p2=find(r*m+c);
//                 if(p1!=p2)
//                 {
//                     par[p2]=p1;
//                     count--;
//                 }
                
//             }
//         }
//         vec.push_back(count);
//     }
//    return vec;
    }

int main()
{
    
    return 0;
}