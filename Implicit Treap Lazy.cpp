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

typedef struct node{
    int prior,size,val,sum,lazy;
    struct node *l,*r;
}node;
typedef node* pnode;
int sz(pnode t){
    return t!=NULL?t->size:0;
}
void upd_sz(pnode t){
    if(t)t->size=sz(t->l)+1+sz(t->r);
}
void lazy(pnode t){
    if(!t || !t->lazy)return;
    swap(t->r,t->l);
    if(t->l)t->l->lazy = !t->l->lazy;
    if(t->r)t->r->lazy = !t->r->lazy;
    t->lazy = 0;
}
void reset(pnode t){
    if(t)t->sum = t->val;
}
void combine(pnode& t,pnode l,pnode r){
    if(!l || !r)return void(t = l?l:r);
    t->sum = l->sum + r->sum;
}
void operation(pnode t){
    if(!t)return;
    reset(t);
    lazy(t->l);lazy(t->r);
    combine(t,t->l,t);
    combine(t,t,t->r);
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t)return void(l=r=NULL);
    lazy(t);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else
        split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
    operation(t);
}
void merge(pnode &t,pnode l,pnode r){
    lazy(l);lazy(r);
    if(!l || !r) t = (l==NULL)?r:l;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd_sz(t);
    operation(t);
}
void init(pnode &t,int val)
{
	t->prior=rand();
	t->size=1;
	t->val=val;
	t->sum=val;
	t->lazy=0;
	t->l=t->r=NULL;
}
int range_query(pnode t,int l,int r){
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);
    int ans = t->sum;
    merge(mid,L,t);
    merge(t,mid,R);
    return ans;
}
void range_update(pnode t,int l,int r,int val){
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);
    t->lazy+=val;
    merge(mid,L,t);
    merge(t,mid,R);
}
void subArrayReverse(pnode t,int l,int r){
    pnode L1,L2,R1,R2;
    split(t,L1,L2,l-1);
    split(L2,R1,R2,r-l);
    R1->lazy = !R1->lazy;
    merge(L2,R1,R2);
    merge(t,L1,L2);
}
int kthQuery(pnode t,int k){
    lazy(t);
    if(k == sz(t->l)) return t->val;
    if(k < sz(t->l)) return kthQuery(t->l,k);
    else return kthQuery(t->r,k - sz(t->l) -1);
    upd_sz(t);
    operation(t);
}
void updateTreap(pnode t,int k,int x){
    lazy(t);
    if(k==sz(t->l)){
        t->val += x;
        upd_sz(t);
        operation(t);
        return;
    }
    if(k < sz(t->l)) updateTreap(t->l,k,x);
    else updateTreap(t->r,k - sz(t->l) - 1,x);
    upd_sz(t);
    operation(t);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
#endif
    srand (time(NULL));

    si(N);
    for(int i=0;i<N;i++)
        si(A[i]);
    for(int i=0;i<N;i++){
        pnode it = new node;
        init(it,A[i]);
        if(i==0)
            Treap = it;
        else
            merge(Treap,Treap,it);
    }

    return 0;
}

