#include<iostream>
#include<fstream>
using namespace std;
const int mx=20;
int n, a[mx][mx];
int x[mx], c, xmin[mx];
int costmin=100000;
void citire()
{
    ifstream f("matrice.in");
    f>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            f>>a[i][j];
}
void afisare()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}
void scrie()
{
    for(int i=0; i<n; i++)
        cout<<xmin[i]<<' ';
    cout<<"cost: "<<costmin;
}
void greedy(int start, int x[], int& cost)
{
    bool vizitat[mx]={false};
    cost=0;
    int v;
    int curent=start;
    vizitat[curent]=true;
    x[0]=start;
    for(int i=1; i<n; i++)
    {
        int mn=100000;
        for(int j=0; j<n; j++)
            if(mn>a[curent][j] && !vizitat[j])
            {
                mn=a[curent][j];
                v=j;
            }
        curent=v;
        cost+=mn;
        vizitat[curent]=true;
        x[i]=v;
    }
    cost+=a[x[n-1]][x[0]];
}
int main()
{
    citire();
    afisare();
    for(int i=0; i<n; i++)
    {
        greedy(i, x, c);
        if(c<costmin)
        {
            for(int j=0; j<n; j++)
                xmin[j]=x[j];
            costmin=c;
        }
    }
    scrie();
}
