#include<bits/stdc++.h>

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
int INF = 2147483645;
lli INFINF = 9223372036854775807;
int debug = 0;

using namespace std;

void print(int a[],int s,int e){for(int i=s;i<=e;i++)cout<<a[i]<<" ";cout<<"\n";}
void print(vector<int> &v,int s,int e){for(int i=s;i<=e;i++)cout<<v[i]<<" ";cout<<"\n";}
void print(vector<int> &v){for(int x:v)cout<<x<<" ";cout<<"\n";}

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*b;x%=m;return x;}

namespace Treap{
    struct Node{
        int val,prior,sz;
        struct Node *l,*r;
    };

    int GetSz(Node* t){
        return t?t->sz:0;
    }

    void UpdateSz(Node* t){
        if(t) t->sz = GetSz(t->l)+1+GetSz(t->r);
    }

    void Split(Node* t,Node* &l,Node* &r,int key){
        if(!t) l=r=NULL;
        else if(t->val<=key) Split(t->r,t->r,r,key),l=t;
        else Split(t->l,l,t->l,key),r=t;
        UpdateSz(t);
    }

    void Merge(Node* &t,Node* l,Node* r){
        if(!l || !r) t=l?l:r;
        else if(l->prior > r->prior)Merge(l->r,l->r,r),t=l;
        else Merge(r->l,l,r->l),t=r;
        UpdateSz(t);
    }

    void Insert(Node* &t,Node* it){
        if(!t) t=it;
        else if(it->prior>t->prior) Split(t,it->l,it->r,it->val),t=it;
        else Insert(t->val<=it->val?t->r:t->l,it);
        UpdateSz(t);
    }

    void Erase(Node* &t,int key){
        if(!t)return;
        else if(t->val==key){Node* temp=t;Merge(t,t->l,t->r);delete temp;}
        else Erase(t->val<key?t->r:t->l,key);
        UpdateSz(t);
    }

    Node* Init(int val){
        Node* ret = new Node();
        ret->val=val;ret->sz=1;ret->prior=rand();ret->l=ret->r=NULL;
        return ret;
    }

    int LessThanAndEqual(Node* &t, lli l){
        if(t==NULL)
            return 0;
        if(t->val>l)
            return LessThanAndEqual(t->l,l);
        return 1+GetSz(t->l)+LessThanAndEqual(t->r,l);
    }
}

Treap::Node* treap[10010];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
#endif
    srand (time(NULL));

    /*for(int i=1;i<=N;i++)
        treap[i] = NULL;

    for(int i=1;i<=N;i++){
        if(treap[F[i]] == NULL)
            treap[F[i]] = Treap::Init(X[i]);
        else
            Treap::Insert(treap[F[i]],Treap::Init(X[i]));
    }*/

    return 0;
}

