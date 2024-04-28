#include<bits/stdc++.h>
using namespace std;


bool is_safe_to_place_H(vector<vector<char> >& board,int r,int c,string word)
{
	int n=board.size();
	int m=board[0].size();

	int l=word.length();

    if(c+l >m)
    {
        return false;
    }

    if(c==0 and c+l <m and  board[r][c+l]!='+')
    {
        return false;
    }

    if(c!=0 and r+l==m and board[r][c-1]!='+')
    {
        return false;
    }

    if(c!=0 and c+l<m and board[r][c-1]!='+' and board[r][c+l]!='+')
    {
        return false;
    }

	for(int i=0;i<word.length();i++)
	{
		
		if(board[r][c+i]!='-' and board[r][c+i]!=word[i])
		{
			return false;
		}
	}
	return true;
}

int place_H(vector<vector<char> >& board,int r,int c,string word)
{
	int loc=0;
	for(int i=0;i<word.length();i++)
	{
		if(board[r][c+i]=='-')
		{
			int mask=(1<<i);
			loc^=mask;
			board[r][c+i]=word[i];
		}
	}
	return loc;
}


void unplace_H(vector<vector<char> >& board,int r,int c,string word,int loc)
{
	for(int i=0;i<word.length();i++)
	{
		int mask=(1<<i);
		if((loc & mask)==1)
		{
			board[r][c+i] = '-';
		}
	}
}


bool is_safe_to_place_V(vector<vector<char> >& board,int r,int c,string word)
{
	int n=board.size();
	int m=board[0].size();

	int l=word.length();

    if(r+l >n)
    {
        return false;
    }

    if(r ==0 and r+l <n and  board[r+l][c]!='+')
    {
        return false;
    }

    if(r!=0 and r+l==n and board[r-1][c]!='+')
    {
        return false;
    }

    if(r!=0 and r+l<n and board[r-1][c]!='+' and board[r+l][c]!='+')
    {
        return false;
    }

	for(int i=0;i<word.length();i++)
	{
		
		if(board[r+i][c]!='-' and board[r+i][c]!=word[i])
		{
			return false;
		}
	}
	return true;
}

int place_V(vector<vector<char> >& board,int r,int c,string word)
{
	int loc=0;
	for(int i=0;i<word.length();i++)
	{
		if(board[r+i][c]=='-')
		{
			int mask=(1<<i);
			loc^=mask;
			board[r+i][c]=word[i];
		}
	}
	return loc;
}

void unplace_V(vector<vector<char> >& board,int r,int c,string word,int loc)
{
	for(int i=0;i<word.length();i++)
	{
		int mask=(1<<i);
		if((loc & mask)==1)
		{
			board[r+i][c]='-';
		}
	}
}

int crossword( vector<vector<char> >& board, vector<string>& words,int idx)
{
    if(idx==words.size())
    {

        for(int x=0;x<10;x++)
        {
            for(int k=0;k<10;k++)
            {
                cout<<board[x][k];
            }
            cout<<endl;
        }


        return 1;
    }

    int count=0;

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(board[i][j]=='-' or board[i][j]== words[idx][0])
            {
                if(is_safe_to_place_H(board,i,j,words[idx]))
                {
                    int loc=place_H(board,i,j,words[idx]);
                    count+= crossword(board,words,idx+1);
                    unplace_H(board,i,j,words[idx],loc);

                }

                if(is_safe_to_place_V(board,i,j,words[idx]))
                {
                    int loc=place_V(board,i,j,words[idx]);
                    count+= crossword(board,words,idx+1);
                    unplace_V(board,i,j,words[idx],loc);
                }
            }
        }
    }

    return count;

}
    
int main()
{


    vector<vector<char> >board(10,vector<char>(10));

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> board[i][j];
		}
	}

	int n;
	cin >> n;
	vector<string> words;
	for (int i = 0; i < n; i++)
	{
        string s;
		cin >> s;
        words.push_back(s);
	}


    crossword(board,words,0);

}



	





   
