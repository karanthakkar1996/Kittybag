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

const double EPS = 1e-24;
const lli MOD = 1000000007ll;
const lli MOD1=1000000009ll;
const lli MOD2=1100000009ll;
const double PI = 3.14159265359;
int INF = 2147483645;
lli INFINF = 9223372036854775807;

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

namespace Geometry{
    typedef long double T;

    struct PT {
        T x, y;
        PT() {}
        PT(T x, T y) : x(x), y(y) {}
        PT(const PT &p) : x(p.x), y(p.y)    {}
        PT operator + (const PT &p)  const { return PT(x+p.x,y+p.y); }
        PT operator - (const PT &p)  const { return PT(x-p.x,y-p.y); }
        PT operator * (T c)          const { return PT(x*c,y*c); }
        PT operator / (T c)          const { return PT(x/c,y/c); }
        bool operator  < (const PT &rhs) const { return mp(y,x)  < mp(rhs.y,rhs.x); }
        bool operator == (const PT &rhs) const { return mp(y,x) == mp(rhs.y,rhs.x); }
    };

    T dot(PT p, PT q)         { return p.x*q.x + p.y*q.y; }
    T dist2(PT p, PT q)       { return dot(p-q,p-q);      }
    T cross(PT p, PT q)       { return p.x*q.y - p.y*q.x; }
    T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }
    #define Det(a,b,c) ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x))

    bool LinesParallel(PT a, PT b, PT c, PT d) {
        return fabs(cross(b-a, c-d)) < EPS;
    }

    bool LinesCollinear(PT a, PT b, PT c, PT d) {
        return LinesParallel(a, b, c, d)
        && fabs(cross(a-b, a-c)) < EPS
        && fabs(cross(c-d, c-a)) < EPS;
    }

    bool SegmentsIntersect(PT a, PT b, PT c, PT d) { // line segment ab with line segment cd
        if (LinesCollinear(a, b, c, d)) {
            if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
                dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
        if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
            return false;
        return true;
        }
        if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
        if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
        return true;
    }

    PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
        b=b-a; d=c-d; c=c-a;
        assert(dot(b, b) > EPS && dot(d, d) > EPS);
        return a + b*cross(c, d)/cross(b, d);
    }

    bool PointInPolygon(const vector<PT> &p, PT q) {
        bool c = 0;
        for (int i = 0; i < p.size(); i++){
            int j = (i+1)%p.size();
            if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) &&
                q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
                c = !c;
        }
        return c;
    }

    bool between(const PT &a, const PT &b, const PT &c) {
      return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
    }

    void ConvexHull(vector<PT> &pts) {
        sort(pts.begin(), pts.end());
        pts.erase(unique(pts.begin(), pts.end()), pts.end());
        vector<PT> up, dn;
        for (int i = 0; i < pts.size(); i++) {
            while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
            while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
            up.push_back(pts[i]);
            dn.push_back(pts[i]);
        }
        pts = dn;
        for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

        bool remove_redundant = false;
        if(remove_redundant){
            if (pts.size() <= 2) return;
            dn.clear();
            dn.push_back(pts[0]);
            dn.push_back(pts[1]);
            for (int i = 2; i < pts.size(); i++) {
                if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
                dn.push_back(pts[i]);
            }
            if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
                dn[0] = dn.back();
                dn.pop_back();
            }
            pts = dn;
        }
    }

    bool in_convex(vector<Geometry::PT>& l, Geometry::PT p){
        int a = 1, b = l.size()-1, c;
        if (Det(l[0], l[a],l[b]) > 0) swap(a,b);     // orientation of area, a is above 0 and b below 0
        // Allow on edge --> if (Det... > 0 || Det ... < 0)
        if (Det(l[0], l[a], p) >= EPS || Det(l[0], l[b], p) < -EPS) return false;
        while(abs(a-b) > 1) {
            c = (a+b)/2;
            if (Det(l[0], l[c], p) > 0) b = c; else a = c;
        }
        // Alow on edge --> return Det... <= 0
        return Det(l[a], l[b], p) < 5*EPS;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    srand (time(NULL));



    return 0;
}

