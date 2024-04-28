#include<bits/stdc++.h>
using namespace std;
class trp{
    public:
    int r, c, steps;
    string s;
    trp(int steps,int r,int c,string s)
    {
        this->steps=steps;
        this->r=r;
        this->c=c;
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

string shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    int n=maze.size();
    int m=maze[0].size();
    priority_queue<trp,vector<trp>,CompareHeight> pq;
    int sr=start[0];
    int sc=start[1];

    int er=destination[0];
    int ec=destination[1];
    

    vector<vector<int>> dis(n,vector<int>(m,1e8));
    pq.push({0,sr,sc,""});
    int spc=0;
    dis[sr][sc]=0;
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    vector<string> vec={"u","d","l","r"};
   // vector<string> ans;
    string final="z";
    while(!pq.empty())
    {
        trp t=pq.top();
        pq.pop();
        for(int d=0;d<dir.size();d++)
        {
            int r=t.r , c=t.c, steps=t.steps;
            string s=t.s+vec[d];
            while(r>=0 and c>=0 and r<n and c<m and maze[r][c]==0)
            {
                r+=dir[d][0];
                c+=dir[d][1];
                steps++;
                if(r==er and c==ec)
                {
                    if(spc==0)
                    {
                        spc=steps;
                        if(s<final)
                        {
                            final=s;
                        }
                        //ans.push_back(s);
                    }
                    else if(steps==spc)
                    {
                        if(s<final)
                        {
                            final=s;
                        }
                        //ans.push_back(s);
                    }
                    break;
                }
            }
            r-=dir[d][0];
            c-=dir[d][1];
            steps--;

            if(steps>=dis[r][c]) continue;

            pq.push({steps,r,c,s});
            dis[r][c]=steps;
            // if(r==er and c==ec)
            // {
            //     if(spc==0)
            //     {
            //         spc=steps;
            //         ans.push_back(s);
            //     }
            //     else if(steps==spc)
            //     {
            //         ans.push_back(s);
            //     }
            // }
        }
    }

    if(final=="z")
    {
        return "impossible";
    }

    return final;


    


}

int main()
{
    vector<vector<int>>maze ={{0,0,0,0,0},{1,1,0,0,1},{0,0,0,0,0},{0,1,0,0,1},{0,1,0,0,0}};
    vector<int>start={4,3};
    vector<int>dest={0,1};

    cout<<shortestDistance(maze,start,dest);
    return 0;
}