#include<bits/stdc++.h>

#define LOCAL 1

#define lli long long int
#define llu unsigned long long int
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

const long double EPS = 1e-10;
const lli MOD = 1000000007ll;
const lli mod1 = 1000000009ll;
const lli mod2 = 1100000009ll;
int INF = (int)1e9;
lli INFINF = (lli)1e18;
int debug = 0;
long double PI = acos(-1.0);

using namespace std;

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m=MOD){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;while(x<0)x+=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;while(x>=m)x-=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*1ll*b;x%=m;if(x<0)x+=m;return x;}

/*
    change MAXN
    call init(N)
*/

namespace Sieve{
    const int MAXN = 100010;
    int N;
    bool isp[MAXN];

    void init(int _N){
        N = _N;
        for(int i=2;i<=N;i++)
            isp[i] = true;
        for(int i=2;i<=N;i++)
            if(isp[i])
                for(int j=i+i;j<=N;j+=i)
                    isp[j] = false;
    }
}

namespace Sieve{
    const int MAXN = 100010;
    int N;
    bool isp[MAXN];
    int spf[MAXN];

    void init(int _N){
        N = _N;
        for(int i=2;i<=N;i++)
            isp[i] = true,
            spf[i] = -1;
        for(int i=2;i<=N;i++){
            if(isp[i]){
                spf[i] = i;
                for(int j=i+i;j<=N;j+=i){
                    isp[j] = false;
                    if(spf[j] == -1)
                        spf[j] = i;
                }
            }
        }
    }
}

namespace Sieve{
    const int MAXN = 100010;
    int N;
    bool isp[MAXN];
    vector<int> pfactors[MAXN];

    void init(int _N){
        N = _N;
        for(int i=2;i<=N;i++)
            isp[i] = true;
        for(int i=2;i<=N;i++){
            if(isp[i]){
                pfactors[i].pb(i);
                for(int j=i+i;j<=N;j+=i){
                    pfactors[j].pb(i);
                    isp[j] = false;
                }
            }
        }
    }
}

namespace Sieve{
    const int MAXN = 1000010;
    int N;
    bool isp[MAXN];
    vector<pair<int,int> > pfactors[MAXN];

    void init(int _N){
        N = _N;
        for(int i=2;i<=N;i++)
            isp[i] = true;
        for(int i=2;i<=N;i++){
            if(isp[i]){
                pfactors[i].pb({i,1});
                for(int j=i+i;j<=N;j+=i){
                    int cnt = 0;
                    int x = j;
                    while(x%i == 0){
                        cnt ++;
                        x /= i;
                    }
                    pfactors[j].pb({i,cnt});
                    isp[j] = false;
                }
            }
        }
    }
}

int main()
{
if(LOCAL){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
}
    srand (time(NULL));



    return 0;
}
