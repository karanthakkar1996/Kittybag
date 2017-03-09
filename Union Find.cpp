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

/*
1 to n
change MAXN
call init(N)
*/

struct UnionFind
{
    static const int MAXN = 100010;
    int parent[MAXN],rank[MAXN],cnt[MAXN];
    int comp;
    void init(int N){
        for(int i=1;i<=N;i++){
            rank[i] = 0;
            parent[i] = i;
            cnt[i] = 1;
        }
        comp = N;
    }
    int Find(int u){
        if(parent[u]!=u)
            parent[u]=Find(parent[u]);
        return parent[u];
    }
    void Union(int u,int v){
        v=Find(v);
        u=Find(u);
        if(u==v)
            return;
        if(rank[v] > rank[u])
            swap(u,v);
        parent[v] = u;
        cnt[u] += cnt[v];
        if(rank[u]==rank[v])
            rank[u]++;
        comp--;

        //
    }
};


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;
}

