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

const double EPS = 1e-10;
const lli MOD = 1000000007ll;
const lli mod1 = 1000000009ll;
const lli mod2 = 1100000009ll;
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

typedef struct TreapNode{
    int prior,sz,val;
    struct TreapNode *l,*r;
}TreapNode;
typedef TreapNode* pTreapNode;
int TreapSz(pTreapNode t){
    return t!=NULL?t->sz:0;
}
void TreapUpdSz(pTreapNode t){
    if(t)t->sz=TreapSz(t->l)+1+TreapSz(t->r);
}
void TreapSplit(pTreapNode t,pTreapNode &l,pTreapNode &r,int pos,int add=0){
    if(!t)return void(l=r=NULL);
    int curr_pos = add + TreapSz(t->l);
    if(curr_pos<=pos)
        TreapSplit(t->r,t->r,r,pos,curr_pos+1),l=t;
    else
        TreapSplit(t->l,l,t->l,pos,add),r=t;
    TreapUpdSz(t);
}
void TreapMerge(pTreapNode &t,pTreapNode l,pTreapNode r){
    if(!l || !r) t = (l==NULL)?r:l;
    else if(l->prior>r->prior)TreapMerge(l->r,l->r,r),t=l;
    else TreapMerge(r->l,l,r->l),t=r;
    TreapUpdSz(t);
}
void init(pTreapNode &t,int val)
{
	t->prior=rand();
	t->sz=1;
	t->val=val;
	t->l=t->r=NULL;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
#endif
    srand (time(NULL));

    /*si(N);
    for(int i=0;i<N;i++)
        si(A[i]);
    for(int i=0;i<N;i++){
        pnode it = new node;
        init(it,A[i]);
        if(i==0)
            Treap = it;
        else
            merge(Treap,Treap,it);
    }*/

    return 0;
}

