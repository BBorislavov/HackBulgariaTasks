#include<iostream>
#include<windows.h>
#include <string>

using namespace std ;

int main()
{
    cout <<"Array[n][m] \n";
    int n,m ;
    int wordCounter=0 ;
     cout << "Enter word: " << endl  ;
    string word;
    cin>>word;
    int wordSize=word.size();
    cout << "Enter n: " << endl  ;
    cin>>n ;
    cout << "Enter m: " << endl  ;
    cin>>m ;
    char arr[n][m] ;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {

            if(m-j+1>=wordSize)
            {

                string comp = "";
                for(int k=j;k<j+wordSize;k++)
                {
                    comp+=arr[i][k];
                }
                if(comp==word)
                {

                    wordCounter++ ;
                }
            }


            if(j+1>=wordSize)
            {
                string comp = "";
                for(int k=j;k>j-wordSize;k--)
                {
                    comp+=arr[i][k];
                }
                if(comp==word)
                {

                    wordCounter++ ;
                }

            }


            if(n-i+1>=wordSize)
            {
                string comp = "";
                for(int k=i;k<i+wordSize;k++)
                {
                    comp+=arr[k][j];
                }
                if(comp==word)
                {

                    wordCounter++ ;
                }
            }

            if(i+1>=wordSize)
            {
                string comp = "";
                for(int k=i;k>i-wordSize;k--)
                {
                    comp+=arr[k][j];
                }
                if(comp==word)
                {
                    wordCounter++ ;
                }

            }


        }

    size_t found;
    int p ;
    string w ;
    for(int i=1;i<n;i++)
    {
            p = i ;
            for(int j=0;j<=i;j++)
            {
                w+=arr[p][j] ;
                --p ;

            }
            found = word.find(w);
            if(found!=string::npos)
            {
                ++wordCounter ;
            }
            w = "";
    }
    for(int i=1;i<n;i++)
    {
            p = i ;
            for(int j=0;j<=i;j++)
            {
                w+=arr[j][p] ;
                --p ;

            }
            found = word.find(w);
            if(found!=string::npos)
            {
                ++wordCounter ;
            }
            w = "";
    }

    for(int i=1;i<m;i++)
    {
        p = i;
        for(int j=n-1;j>=n-i-1;j--){

            w+=arr[j][p] ;
            --p;
        }

        found = word.find(w);
        if(found!=string::npos)
        {

            ++wordCounter ;
        }
         w = "";

    }
     for(int i=1;i<m;i++)
    {
        p = i;
        for(int j=n-1;j>=n-i-1;j--){

            w+=arr[p][j] ;
            --p;
        }

        found = word.find(w);
        if(found!=string::npos)
        {

            ++wordCounter ;
        }
         w = "";

    }


    cout << wordCounter <<endl;
    return 0;
}



/*
ivan
5
4
i v a n
e v n h
i n a v
m v v n
q r i t
*/
