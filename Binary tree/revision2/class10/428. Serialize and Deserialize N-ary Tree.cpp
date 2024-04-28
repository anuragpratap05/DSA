#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(Node *root)
    {
        if (root == nullptr)
            return "";
        queue<Node *> q;
        string str;
        q.push(root);
        str += to_string(root->val) + " ";
        while (!q.empty())
        {
            Node *curNd = q.front();
            q.pop();
            for (Node *child : curNd->children)
            {
                q.push(child);
                str += to_string(child->val) + " ";
            }
            str += "# ";
        }
        return str;
    }

    vector<string> splitOnSpaces(string str)
    {
        string s;

        stringstream ss(str);

        vector<string> v;

        while (getline(ss, s, ' '))
        {
            v.push_back(s);
        }

        return v;
    }

    Node *constructTree(vector<string> &preorder)
    {
        queue<Node *> q;
        Node *oRoot = new Node(stoi(preorder[0]));
        q.push(oRoot);
        int idx = 2;
        while (!q.empty())
        {
            Node *root = q.front();
            q.pop();
            while (preorder[idx] != "#")
            {
                string strNd = preorder[idx];
                Node *node = new Node(stoi(strNd));
                root->children.push_back(node);
                q.push(node);
                idx++;
            }
            idx++;
        }
        return oRoot;
    }

    // Decodes your encoded data to tree.
    Node *deserialize(string data)
    {
        if (data == "")
            return nullptr;

        vector<string> preorder = splitOnSpaces(data);
        return constructTree(preorder);
    }
};

// method2 using stack
class Codec2
{
public:
    // Encodes a tree to a single string.
    void preorder(Node *root, string &str)
    {
        str += to_string(root->val) + " ";

        for (Node *node : root->children)
        {
            preorder(node, str);
        }
        str += "null ";
    }

    string serialize(Node *root)
    {
        if (root == nullptr)
            return "";
        string str = "";
        preorder(root, str);
        return str;
    }

    vector<string> splitOnSpaces(string str)
    {
        string s;

        stringstream ss(str);

        vector<string> v;

        while (getline(ss, s, ' '))
        {
            v.push_back(s);
        }

        return v;
    }

    // Decodes your encoded data to tree.
    Node *deserialize(string data)
    {
        if (data == "")
            return nullptr;
        vector<string> preorder = splitOnSpaces(data);
        stack<Node *> st;
        for (int i = 0; i < preorder.size() - 1; i++)
        {
            string ndStr = preorder[i];
            if (ndStr == "null")
            {
                Node *node = st.top();
                st.pop();
                st.top()->children.push_back(node);
            }
            else
                st.push(new Node(stoi(ndStr)));
        }
        Node *root = st.top();
        st.pop();
        return root;
    }
};

int main()
{
    return 0;
}