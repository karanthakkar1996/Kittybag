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

namespace FFT{
    void fft(vector<complex<double> >&a,bool invert){
        int n=(int) a.size();
        for (int i=1,j=0;i<n;++i){
            int bit=n>>1;
            for(;j>=bit;bit>>=1) j-=bit;
            j+=bit;
            if(i<j) swap(a[i], a[j]);
        }
        for (int len=2;len<=n;len<<=1) {
            double ang=2*PI/len*(invert?-1:1);
            complex<double> wlen(cos(ang),sin(ang));
            for (int i=0;i<n;i+=len){
                complex<double> w(1);
                for(int j=0;j<len/2;++j){
                    complex<double> u=a[i+j],v=a[i+j+len/2]*w;
                    a[i+j]=u+v;
                    a[i+j+len/2]=u-v;
                    w*=wlen;
                }
            }
        }
        if(invert) for(int i=0;i<n;++i) a[i]/=n;
    }

    void multiply(const vector<lli> &a,const vector<lli> &b,vector<lli> &res){
        vector<complex<double> > fa,fb;
        for(int i=0;i<a.size();i++) fa.push_back(a[i]);
        for(int i=0;i<b.size();i++) fb.push_back(b[i]);
        size_t n=1;
        while (n<max(a.size(), b.size()))n <<= 1;n<<=1;
        fa.resize(n),fb.resize(n);
        fft(fa,false),fft(fb,false);
        for(int i=0;i<n;++i) fa[i]*=fb[i];
        fft (fa, true);
        res.resize(n);
        for(int i=0;i<n;++i) res[i]=(lli)(fa[i].real() + 0.5);
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

