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
lli add(lli a,lli b){lli x=a+b;if(x>=MOD)x-=MOD;return x;}
lli sub(lli a,lli b){lli x=a-b;if(x<0)x+=MOD;return x;}
lli mul(lli a,lli b){lli x=a*b;x%=MOD;return x;}

/*
    1-based
    change MAXN, LOGN
    change spt
*/

struct SparseTableMAX{
    typedef int spt;
    static const int MAXN = 100010;
    static const int LOGN = 20;
    int N;
    spt arr[MAXN];
    int logTable[MAXN];
    int rmq[MAXN][LOGN];
    void init(int _N,spt A[]){
        N = _N;
        for(int i=0;i<N;i++)
            arr[i] = A[i+1];
        for(int i=2;i<=N;i++)
            logTable[i]=logTable[i>>1]+1;
        for(int i=0;i<N;++i)
            rmq[i][0] = i;
        for(int j=1;(1<<j)<=N;j++){
            for(int i=0;i+(1<<j)-1<N;i++){
                int x = rmq[i][j-1];
                int y = rmq[i+(1<<j-1)][j-1];
		        rmq[i][j] = arr[x]>=arr[y] ? x : y;
            }
        }
    }
    int query(int i, int j){
        i--;j--;
        int k,x,y;
        k = logTable[j-i],x = rmq[i][k],y = rmq[j-(1<<k)+1][k];
        return (arr[x]>=arr[y] ? x : y) + 1;
    }
};

struct SparseTableMIN{
    typedef int spt;
    static const int MAXN = 100010;
    static const int LOGN = 20;
    int N;
    spt arr[MAXN];
    int logTable[MAXN];
    int rmq[MAXN][LOGN];
    void init(int _N,spt A[]){
        N = _N;
        for(int i=0;i<N;i++)
            arr[i] = A[i+1];
        for(int i=2;i<=N;i++)
            logTable[i]=logTable[i>>1]+1;
        for(int i=0;i<N;++i)
            rmq[i][0] = i;
        for(int j=1;(1<<j)<=N;j++){
            for(int i=0;i+(1<<j)-1<N;i++){
                int x = rmq[i][j-1];
                int y = rmq[i+(1<<j-1)][j-1];
		        rmq[i][j] = arr[x]<=arr[y] ? x : y;
            }
        }
    }
    int query(int i, int j){
        i--;j--;
        int k,x,y;
        k = logTable[j-i],x = rmq[i][k],y = rmq[j-(1<<k)+1][k];
        return (arr[x]<=arr[y] ? x : y) + 1;
    }
};

struct SparseTableGCD{
    typedef int spt;
    static const int MAXN = 100010;
    static const int LOGN = 20;
    int N;
    spt arr[MAXN];
    int logTable[MAXN];
    spt rmq[MAXN][LOGN];
    void init(int _N,spt A[]){
        N = _N;
        for(int i=0;i<N;i++)
            arr[i] = A[i+1];
        for(int i=2;i<=N;i++)
            logTable[i]=logTable[i>>1]+1;
        for(int i=0;i<N;++i)
            rmq[i][0] = arr[i];
        for(int j=1;(1<<j)<=N;j++){
            for(int i=0;i+(1<<j)-1<N;i++){
                spt x = rmq[i][j-1];
                spt y = rmq[i+(1<<j-1)][j-1];
		        rmq[i][j] = __gcd(x,y);
            }
        }
    }
    int query(int i, int j){
        i--;j--;
        int k,x,y;
        k = logTable[j-i],x = rmq[i][k],y = rmq[j-(1<<k)+1][k];
        return __gcd(x,y);
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

