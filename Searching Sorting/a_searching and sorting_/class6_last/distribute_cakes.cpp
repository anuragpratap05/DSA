#include<bits/stdc++.h>
using namespace std;

double pi = 2*asin(1.0);


bool can_give_this_big(vector<int> rad,double piece_size,int guest)
{
    int my_g=0;
    for(int i=rad.size()-1;i>=0;i--)
    {
        double area=pi*rad[i]*rad[i];
        my_g+=floor(area/piece_size);
        if(my_g>=guest)
        {
            return true;
        }

    }
    return false;
}

double serve_cake(vector<int> rad,int guest)
{
    double si=0.0, ei=1e7;

    while((ei-si)>0.00001)
    {
        double piece_size=(si+ei)/2;

        if(can_give_this_big(rad,piece_size,guest))
        {
            si=piece_size;
        }
        else
        {
            ei=piece_size-(0.00001);

        }
    }
    return si;

}

int main()
{
    vector<int> rad={1,1,1,2,2,3};
    
    cout<<serve_cake(rad,6);
    return 0;
}