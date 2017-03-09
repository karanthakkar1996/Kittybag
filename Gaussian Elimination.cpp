/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
1st Year ICT BTECH student
*/
#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int

const double EPS = 1e-24;
const lli MOD = 1000000007ll;
const double PI = 3.14159265359;
int INF = 2147483645;

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Max2(c,d));}

using namespace std;

void Gaussian_Elimination(vector<vector<double> > &_a,int _N)
{
    int _max;
    for(int i=1;i<=_N;i++)
    {
        _max=i;
        for(int j=i+1;j<=_N;j++)
        {
            if(_a[j][i] > _a[_max][i])
                _max=j;
        }
        for(int j=1;j<=_N+1;j++)
        {
            int _temp=_a[_max][j];
            _a[_max][j]=_a[i][j];
            _a[i][j]=_temp;
        }
        for(int j=i;j<=_N+1;j++)
            for(int k=i+1;k<=_N;k++)
                _a[k][j]-=_a[k][i]/_a[i][i] * _a[i][j];

        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=4;j++)
                cout<<_a[i][j]<<" ";
            cout<<endl;
        }cout<<"\n";
    }

    for(int i=_N;i>=1;i--)
    {
        _a[i][_N+1]=_a[i][_N+1]/_a[i][i];
        _a[i][i]=1;
        for(int j=i-1;j>=1;j--)
        {
            _a[j][_N+1]-=_a[j][i]*_a[i][_N+1];
            _a[j][i]=0;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    vector<vector<double> > a={{0,0,0,0,0},
                    {0,2,1,-1,8},
                    {0,-3,-1,2,-11},
                    {0,-2,1,2,-3}};

    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=4;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    Gaussian_Elimination(a,3);
    cout<<"\n\n";
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=4;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

