/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
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

const double EPS = 1e-10;
const lli MOD = 1000000007ll;
const lli mod1 = 1000000009ll;
const lli mod2 = 1100000009ll;
const double PI = 3.14159265359;
int INF = 2147483645;
lli INFINF = 9223372036854775807;
int debug = 0;

using namespace std;

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b){lli x=a+b;if(x>MOD)x-=MOD;return x;}
lli sub(lli a,lli b){lli x=a-b;if(x<0)x+=MOD;return x;}
lli mul(lli a,lli b){lli x=a*b;x%=MOD;return x;}

void dfs1(int u){
    int childcnt = 0;
    vis[u] = true;
    disc[u] = low[u] = ++dfstime;
    for(auto it : G[u]){
        int v = it;
        if(!vis[v]){
            childcnt ++;
            parent[v] = u;
            dfs1(v);
            low[u] = min(low[u], low[v]);

            if(parent[u] == 0 && childcnt > 1)
                arti[u] = true;
            if(parent[u] != 0 && low[v]>=disc[u])
                arti[u] = true;
        }
        else if(v!=parent[u]){
            low[u] = min(low[u], disc[v]);
        }
    }
}

/* bridge
int disc[N],low[N],parent[N];
int dfstime;
bool vis[N],bridge[M];
*/

int dual(int i){
    if(i%2==0)
        return i + 1;
    return i - 1;
}

void find_bridge(int u){
    vis[u] = true;
    disc[u] = low[u] = dfstime++;
    for(int i : G[u]){
        int v = to[i];
        if(!vis[v]){
            parent[v] = u;
            find_bridge(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]){
                bridge[i] = true;
                bridge[dual(i)] = true;
            }
        }
        else if(v!=parent[u]){
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
#endif
    srand (time(NULL));



    return 0;
}

