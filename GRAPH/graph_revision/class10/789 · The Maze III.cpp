#include<bits/stdc++.h>
using namespace std;

class trp
{
    public:
    int r,c,steps;
    string s;
    trp(int r,int c,int steps,string s)
    {
        this->r=r;
        this->c=c;
        this->steps=steps;
        this->s=s;
    }
    
    
};

struct CompareHeight {
    bool operator()(trp const& p1, trp const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.steps > p2.steps;
    }
};
string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole)
{
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    vector<string> vec={"u","d","l","r"};
        int n=maze.size();
    int m=maze[0].size();
    int r=max(n,m);
    string final="z";
    vector<vector<int>> dis(n,vector<int>(m,1e8));
    priority_queue<trp,vector<trp>,CompareHeight> pq;
    int a=ball[0];
    int b=ball[1];
    int s_val=a*m+b;

    int x=hole[0];
    int y=hole[1];
    int d_val=x*m+y;
    

    pq.push(trp(a,b,0,""));
    dis[a][b]=0;

    while(!pq.empty())
    {
        int size=pq.size();
        
        while(size--)
        {
            trp p =pq.top();
            pq.pop();
            //int idx=p.second;
            
            //cout<<"steps="<<steps<<" "<<"idx="<<idx<<endl;
            
           
            for(int i=0;i<dir.size();i++)
            {   
                int steps=p.steps;
                int r=p.r;
                int c=p.c;
                string s=p.s+vec[i];
                while(r>=0 and c>=0 and r<n and c<m and maze[r][c]==0)
                {
                    r+=dir[i][0];
                    c+=dir[i][1];
                    steps++;
                    if(r==x and c==y)
                    {
                        if(steps<=dis[x][y])
                        {
                            if(steps<dis[x][y])
                            {
                                dis[x][y]=steps;
                                final=s;
                            }
                            else{
                                final=min(final,s);
                            }
                            
                        }
                        break;
                    }
                }
                r-=dir[i][0];
                c-=dir[i][1];
                steps--;
                if(steps>= dis[r][c])
                {
                    continue;
                }
                dis[r][c]=steps;
                pq.push(trp(r,c,steps,s));
            
                
            }
            
        }


    }
    return final;


}

int main()
{
    return 0;
}