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
lli bit(lli _mask,lli _i){return (_mask&(1ll<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m=MOD){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;while(x<0)x+=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;while(x>=m)x-=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*1ll*b;x%=m;while(x<0)x+=m;return x;}

struct Segtree{
    typedef int stt;
    static const int MAXN = 100010;

    struct Node{
        int val;
        int sz;
    };
    struct Node Segtree[4*MAXN];

    Node MergeSegTree(Node a,Node b){
        struct Node temp;

        //

        return temp;
    }

    void BuildSegTree(int s,int e,int idx,int C[]){
        if(s==e){
            //
        }
        else{
            int mid = (s+e)>>1;
            BuildSegTree(s,mid,2*idx+1,C);
            BuildSegTree(mid+1,e,2*idx+2,C);
            Segtree[idx] = MergeSegTree(Segtree[2*idx+1],Segtree[2*idx+2]);
        }
    }

    void UpdateSegTree(int s,int e,int x,stt v,int idx){
        if(s==e){
            //
            return;
        }
        lli mid = (s+e)>>1;
        if(x<=mid)
            UpdateSegTree(s,mid,x,v,2*idx+1);
        else
            UpdateSegTree(mid+1,e,x,v,2*idx+2);

        Segtree[idx] = MergeSegTree(Segtree[2*idx+1],Segtree[2*idx+2]);
    }

    Node QuerySegTree(int s,int e,int x,int y,int idx){
        if(s==x && e==y)
            return Segtree[idx];
        int mid = (s+e)>>1;
        if(y<=mid)
            return QuerySegTree(s,mid,x,y,2*idx+1);
        if(x>mid)
            return QuerySegTree(mid+1,e,x,y,2*idx+2);
        return MergeSegTree(QuerySegTree(s,mid,x,mid,2*idx+1),QuerySegTree(mid+1,e,mid+1,y,2*idx+2));
    }
};

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
