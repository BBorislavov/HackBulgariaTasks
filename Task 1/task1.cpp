#include<iostream>
#include<string>
using namespace std;
long x,y;
bool xRightIncreas=1,yUpIncreas=0;
char input;
string dirrections;
int main()
{
    cin>>input>>x>>input>>y>>input>>dirrections;
    for(int i=0;i<=dirrections.size()-1;i++)
    {
        if(dirrections[i]=='>')
        {
            if(xRightIncreas) x++;
            else x--;
        }
        if(dirrections[i]=='<')
        {
            if(xRightIncreas) x--;
            else x++;
        }
        if(dirrections[i]=='^')
        {
            if(yUpIncreas) y++;
            else y--;
        }
        if(dirrections[i]=='~')
        {
            if(xRightIncreas) xRightIncreas=0;
            else xRightIncreas=1;
            if(yUpIncreas) yUpIncreas=0;
            else yUpIncreas=1;
        }
    }
    cout<<"("<<x<<", "<<y<<")"<<endl;
    return 0;
}
