/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
1st Year ICT BTECH student
*/
#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int

const double EPS = 1e-24;
const lli MOD = 1000000007ll;
const double PI = 3.14159265359;
int INF = 2147483645;
lli INFINF = 9223372036854775807;

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Max2(c,d));}

using namespace std;

struct SuffixArray
{
    string S;
    vector<int> SA;
    vector<int> RSA;
    vector<int> P[50];
    vector<int> LCP[50];
    vector<int> LOG2;
    vector<pair<pair<int,int>,int> >L;
    int laststep;
    void init(string a)
    {
        S=a;
        L.resize(a.size());
        SA.resize(a.size());
        RSA.resize(a.size());
        LOG2.resize(a.size());
        for(int i=0;i<50;i++)
            P[i].resize(a.size());
        for(int i=0;i<50;i++)
            LCP[i].resize(a.size());
    }
    void buildSA()
    {
        for(int i=0;i<S.size();i++)
            P[0][i]=S[i];
        for(int step=1,cnt=1;cnt<S.size();cnt*=2,step++)
        {
            for(int i=0;i<S.size();i++)
            {
                L[i].first.first=P[step-1][i];
                L[i].first.second=(i+cnt)<S.size()?(P[step-1][i+cnt]):(-1);
                L[i].second=i;
            }
            sort(L.begin(),L.end());
            P[step][L[0].second]=0;
            for(int i=1;i<S.size();i++)
            {
                if(L[i].first.first==L[i-1].first.first && L[i].first.second==L[i-1].first.second)
                    P[step][L[i].second]=P[step][L[i-1].second];
                else
                    P[step][L[i].second]=i;
            }
            laststep=step;
        }
        for(int i=0;i<S.size();i++)
            SA[i]=L[i].second;
    }
    void buildRSA()
    {
        for(int i=0;i<S.size();i++)
            RSA[SA[i]]=i;
    }
    void buildLCP()
    {
        for(int i=0;i<S.size()-1;i++)
            LCP[0][i]=lcp(SA[i],SA[i+1]);
        for(int j=1;(1<<j)<=S.size();j++)
        for(int i=0;(i+(1<<j)-1)<S.size();i++)
        {
            int p,q;
            p=LCP[j-1][i];
            q=LCP[j-1][i+(1<<(j-1))];
            LCP[j][i]=Min2(p,q);
        }
    }
    void buildLOG2()
    {
        int g=2;
        while(g <= S.size()){
            LOG2[g] = 1;
            g = (g << 1);
        }
        for(int i=1;i<=S.size();i++)
            LOG2[i]+=LOG2[i - 1];
    }
    int lcp(int x,int y)
    {
        int k,ret=0;
        if(x==y)
            return S.size()-x;
        for(k=laststep;k>=0 && x<S.size() && y<S.size(); k--)
            if(P[k][x]==P[k][y])
                x+=1<<k,y+=1<<k,ret+=1<<k;
        return ret;
    }
    int lcprmq(int x,int y)
    {
        if(x==y)
            return S.size()-x;
        if(x>y)
            swap(x,y);
        int k=LOG2[y-x+1];
        return Min2(LCP[k][x], LCP[k][y+1-(1<<k)]);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;
}

