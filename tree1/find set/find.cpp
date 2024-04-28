

class Node
{
public:
    int data=0;
    Node* left=NULL;
    Node* right=nullptr;

    Node(int data)
    {
        this->data=data;
    }
};

bool find(int ele,Node* root)
{
    if(root==nullptr)
    {
        return false;
    }
    if(root->data==ele)
    {
        
        return true;
    }
    if(find(ele,root) or find(ele,root))
    {
        
        return true;
    }
    return false;

}

int main()
{
    vector<int>v;
    int ele=5;
    Node* root=new Node(3)
    find(ele,root);

}