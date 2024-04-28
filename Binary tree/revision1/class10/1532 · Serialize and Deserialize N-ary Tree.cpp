#include<bits/stdc++.h>
using namespace std;

struct DirectedGraphNode
{
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x){};
    
};

string serialize(vector<DirectedGraphNode *> &nodes)
{
}
vector<DirectedGraphNode *> deserialize(string &data)
{
}

int main()
{
    return 0;
}