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
    1-based string
    struct Trie *root = new Trie();
*/

struct Trie
{
    const static int sz = 26;
    int cnt;
    struct Trie *children[sz];

    Trie(){
        for(int i=0;i<this->sz;i++)
            this->children[i] = NULL;
        this->cnt = 0;
    }

    void addString(string s){
        struct Trie *pCrawl = this;

        int n = s.size()-1;
        for(int i=1;i<=n;i++){
            int idx = s[i]-'a';
            if(pCrawl->children[idx] == NULL)
                pCrawl->children[idx] = new Trie();
            pCrawl=pCrawl->children[idx];
        }
    }

    void dfs(Trie* u){
        for(int i=0;i<u->sz;i++){
            if(u->children[i] != NULL){
                dfs(u->children[i]);
            }
        }
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

