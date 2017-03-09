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
const lli mod1 = 1000000009;
const lli mod2 = 1100000009;
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
int sign(double a){return a < -EPS ? -1 : a > EPS ? 1 : 0;}

/* insert '$' at begging of string
call buildSA(),buildLCP(),buildLogs(),buildLcpSparseTable();
string is 1 based, constructed suffix array is also 1 based, 0th suffix is the whole string
sa[i]  is the ith suffix 1 based
pos[i] is the rank of ith suffix
lcp[i] is the lcp of ith suffix with (i+1)th
s = "$banana"
     0123456
sa[]  = {0,6,4,2,1,5,3};
pos[] = {0,4,3,6,2,5,1};
lcp[] = {0,1,3,0,0,2,0};
*/


namespace SA{
    static const int MAXN = 2200010;
    static const int MAXLOGN = 23;
    string s;
    int n,gap;
    int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN], logs[MAXN], lcptable[MAXLOGN][MAXN];

    bool sufCmp(int i,int j){
        if(pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap;j += gap;
        return(i < n && j < n) ? pos[i] < pos[j] : i > j;
    }
    void buildSA(){
        n = s.size();
        for(int i=0;i<n;i++)
            sa[i] = i,pos[i] = s[i];
        for(gap = 1;;gap *= 2){
            sort(sa,sa+n,sufCmp);
            for(int i=0;i<n-1;i++)
                tmp[i + 1] = tmp[i] + sufCmp(sa[i],sa[i + 1]);
            for(int i=0;i<n;i++)
                pos[sa[i]] = tmp[i];
            if(tmp[n-1] == n-1)
                break;
        }
    }
    void buildLCP(){
        for (int i=0,k=0;i<n;++i){
            if(pos[i]!=n-1){
                for(int j=sa[pos[i]+1];s[i+k]==s[j+k];)
                    ++k;
                lcp[pos[i]]=k;
                if(k)
                    --k;
            }
        }
    }
    void buildLogs(){
        int g=2;
        while(g<=n){
            logs[g]=1;
            g=(g<<1);
        }
        for(int i=1;i<=n;i++)
            logs[i]+=logs[i-1];
    }
    void buildLcpSparseTable(){
        for(int i=0;i<n;i++)
            lcptable[0][i]=lcp[i];
        for(int j=1;(1<<j)<=n;j++)
            for(int i=0;i+(1<<j)-1<n;i++)
                lcptable[j][i]=min(lcptable[j-1][i],lcptable[j-1][i+(1<<(j-1))]);
    }
    int lcpQuery(int l,int r){
        if(l>r)     swap(l,r);
        if(l==r)    return INF;
        if(l+1==r)  return lcp[l];
        r--;
        int k=logs[r-l+1];
        return min(lcptable[k][l],lcptable[k][r-(1<<k)+1]);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
#endif
    srand (time(NULL));




    return 0;
}

