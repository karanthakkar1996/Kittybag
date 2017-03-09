/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
2nd Year ICT BTECH student
*/
#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

const double EPS = 1e-4;
const lli MOD = 1000000007ll;
const lli HASHMOD[2]={1000000009ll,1100000009ll};
const double PI = 3.14159265359;
int INF = 2147483645;
lli INFINF = 9223372036854775807;

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Min2(c,d));}

using namespace std;

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

struct LowestCommonAncestor
{
    int N;
    int LOGN;
    vector<vector<int> >GRAPH;
    vector<vector<int> >LCA;
    vector<int> DEPTH;

    void dfs(int u,int p,int l)
    {
        LCA[u][0]=p;
        DEPTH[u]=l;
        for(int v:GRAPH[u])
            if(v!=p)
                dfs(v,u,l+1);
    }

    void init(int _N,int _LOGN,vector<int> _GRAPH[])
    {
        N=_N;
        LOGN=_LOGN;
        GRAPH.resize(N+1);
        for(int i=1;i<=N;i++)
            GRAPH[i].clear();
        for(int i=1;i<=N;i++)
            for(int x:_GRAPH[i])
                GRAPH[i].push_back(x);
        LCA.resize(N+1);
        DEPTH.resize(N+1);
        for(int i=1;i<=N;i++)
            LCA[i].resize(LOGN);
        for(int i=1;i<=N;i++)
            for(int j=0;j<LOGN;j++)
                LCA[i][j]=-1;
        dfs(1,-1,1);
        for(int j=1;j<LOGN;j++)
            for(int i=1;i<=N;i++)
                if(LCA[i][j-1]!=-1)
                    LCA[i][j]=LCA[LCA[i][j-1]][j-1];
    }

    int getLCA(int u,int v)
    {
        if(DEPTH[u]<DEPTH[v])
            swap(u,v);
        int diff=DEPTH[u]-DEPTH[v];
        for(int i=0;i<LOGN;i++)
            if( (diff>>i)&1 )
                u=LCA[u][i];
        if(u==v)
            return u;
        for(int j=LOGN-1;j>=0;j--)
            if(LCA[u][j]!=LCA[v][j])
            {
                u=LCA[u][j];
                v=LCA[v][j];
            }
        return LCA[u][0];
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    srand (time(NULL));



    return 0;
}

