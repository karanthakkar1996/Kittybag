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
int sign(double a){return a < -EPS ? -1 : a > EPS ? 1 : 0;}

struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y){x =_x;y=_y;}

    double dot(Point b){
        return x*b.x + y*b.y;
    }
    double cross(Point b){
        return x*b.y - y*b.x;
    }
    Point rotateCCW(double angle) {
        Point ret(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
        return ret;
    }
};

struct Line{
    double a,b,c;
    Line(Point p1,Point p2){
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
    Line(double _a,double _b,double _c){a=_a;b=_b;c=_c;}

    bool isParallel(Line line){
        return a * line.b - b * line.a == 0;
    }
    bool isPerpendicular(Line line){
        return sign( a * line.a + b * line.b ) == 0;
    }
    Point intersect(Line line) {
      double d = a * line.b - line.a * b;
      double x = -(c * line.b - line.c * b) / d;
      double y = -(a * line.c - line.a * c) / d;
      Point ret(x,y);
      return ret;
    }
};

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

