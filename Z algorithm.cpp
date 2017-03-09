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

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Max2(c,d));}
template <class T>void Swap(T& a,T& b){T temp;temp=a;a=b;b=temp;}

using namespace std;

// 0 based
void zalgo(string &s,int z[],int n)
{
    z[0]=n;
    int L=0,R=0;
    for (int i = 1; i < n; i++) {
      if (i > R) {
        L = R = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L; R--;
      } else {
        int k = i-L;
        if (z[k] < R-i+1) z[i] = z[k];
        else {
          L = i;
          while (R < n && s[R-L] == s[R]) R++;
          z[i] = R-L; R--;
        }
      }
    }
}

void zalgo(char s[],int len,int z[])
{
    z[0]=len;
    int L=0,R=0;
    for(int i=1;i<len;i++)
    {
        if(i>R)
        {
            L=R=i;
            while(R<len && s[R-L]==s[R])
                R++;
            z[i]=R-L;
            R--;
        }
        else
        {
            int k=i-L;
            if(z[k]<R-i+1)
                z[i]=z[k];
            else
            {
                L=i;
                while(R<len && s[R-L]==s[R])
                    R++;
                z[i]=R-L;
                R--;
            }
        }
    }
}

void zalgo(string &s,int z[],int n)
{
    z[1]=n;
    int L=0,R=1;
    for(int i=2;i<=n;i++)
    {
        if(i>R)
        {
            L=R=i;
            while(R<=n && s[R-L+1]==s[R])
                R++;
            z[i]=R-L;
            R--;
        }
        else
        {
            int k=i-L+1;
            if(z[k]<R-i+1)
                z[i]=z[k];
            else
            {
                L=i;
                while(R<=n && s[R-L+1]==s[R])
                    R++;
                z[i]=R-L;
                R--;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;
}

