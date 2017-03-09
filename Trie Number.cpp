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

using namespace std;

/*
    struct trie root = new trie()

*/

struct trie
{
    const static int bits = 30;
    const static int sz = 2;
    struct trie *children[sz];

    trie(){
        for(int i=0;i<sz;i++)
            this->children[i] = NULL;
    }

    void trie_insert(int x)
    {
        vector<int> t;
        for(int i=0;i<bits;i++){
            t.pb(x&1);
            x >>= 1;
        }
        reverse(all(t));

        struct trie *pCrawl = this;
        for(int i=0;i<t.size();i++)
        {
            int idx=t[i];
            if(pCrawl->children[idx]==NULL)
                pCrawl->children[idx] = new trie();
            pCrawl=pCrawl->children[idx];
        }
    }

    int trie_query(int x)
    {
        vector<int> t;
        for(int i=0;i<bits;i++){
            t.pb(x&1);
            x >>= 1;
        }
        reverse(all(t));

        int ret = 0;
        struct trie *pCrawl = this;
        for(int i=0,j=bits-1;i<t.size();i++,j--)
        {
            int idx=t[i];
            if(pCrawl->children[!idx]!=NULL){
                pCrawl=pCrawl->children[!idx];
                ret += (1<<j);
            }
            else{
                pCrawl=pCrawl->children[idx];
            }
        }
        return ret;
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

