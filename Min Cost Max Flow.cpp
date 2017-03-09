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

const double EPS = 1e-9;
const lli MOD = 1000000007ll;
const lli HASHMOD[2]={1000000009ll,1100000009ll};
const double PI = 3.14159265359;
int INF = 2147483645;
lli INFINF = 9223372036854775807;
int debug = 0;

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
lli add(lli a,lli b){lli x=a+b;if(x>MOD)x-=MOD;return x;}
lli sub(lli a,lli b){lli x=a-b;if(x<0)x+=MOD;return x;}
lli mul(lli a,lli b){lli x=a*b;x%=MOD;return x;}

/*
change MAXN
call init(s,t,n)
change datatype
change inf
*/

namespace MCMF
{
    struct Edgemcmf{
        mcmftype b, c, u, f, back;
    };
    typedef int mcmftype;
    const mcmftype MAXN = 510;
    mcmftype s, t, n;
    vector<Edgemcmf> g[MAXN];
    mcmftype inf = (mcmftype)1e9;

    void init(mcmftype _s, mcmftype _t, mcmftype _n){
        s = _s;
        t = _t;
        n = _n;
    }

    void addEdge(mcmftype from, mcmftype to, mcmftype cost, mcmftype cap)
    {
        Edgemcmf e1 = {to, cost, cap, 0, (mcmftype)g[to].size()};
        Edgemcmf e2 = {from, -cost, 0, 0, (mcmftype)g[from].size()};
        g[from].push_back(e1);
        g[to].push_back(e2);
    }

    pair<mcmftype,mcmftype> minCostMaxFlow()
    {
        mcmftype flow = 0;
        mcmftype cost = 0;
        mcmftype *state = new mcmftype[n];
        mcmftype *from = new mcmftype[n];
        mcmftype *from_edge = new mcmftype[n];
        mcmftype *d = new mcmftype[n];
        mcmftype *q = new mcmftype[n];
        mcmftype qh, qt;
        qh = 0, qt = 0;
        while (true)
        {
            for (mcmftype i = 0; i < n; i++) state[i] = 2, d[i] = inf;
            fill(from, from + n, -1);
            state[s] = 1;
            q[qh++] = s;
            d[s] = 0;
            while (qh != qt)
            {
                mcmftype v = q[qt++];
                qt %= n;
                state[v] = 0;
                for (mcmftype i = 0; i < g[v].size(); i++) if (g[v][i].f < g[v][i].u && d[g[v][i].b] > d[v] + g[v][i].c)
                {
                    mcmftype to = g[v][i].b;
                    d[to] = d[v] + g[v][i].c;
                    from[to] = v;
                    from_edge[to] = i;
                    if (state[to] == 1) continue;
                    if (!state[to])
                    {
                        qt--;
                        if (qt == -1) qt = n - 1;
                        q[qt] = to;
                        state[to] = 1;
                    } else
                    {
                        state[to] = 1;
                        q[qh++] = to;
                        qh %= n;
                    }
                }
            }
            if (d[t] == inf) break;
            mcmftype it = t;
            mcmftype addflow = inf;
            while (it != s)
            {
                addflow = min(addflow, (mcmftype)(g[from[it]][from_edge[it]].u - g[from[it]][from_edge[it]].f));
                it = from[it];
            }
            it = t;
            while (it != s)
            {
                g[from[it]][from_edge[it]].f += addflow;
                g[it][g[from[it]][from_edge[it]].back].f -= addflow;
                cost += g[from[it]][from_edge[it]].c * addflow;
                it = from[it];
            }
            flow += addflow;
        }
        return {cost,flow};
    }
};


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

