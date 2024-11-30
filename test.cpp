#include <bits/stdc++.h>
#define forn(i) for(int i=0;i<n;i++)
#define rep(i,j,k) for(auto i=j;i<k;i++)
#define rrep(i,j,k) for(auto i=j;i>=k;i--)
#define ll long long
#define vll vector<ll int>
#define PYES cout << "YES" << endl;
#define PNO cout << "NO" << endl;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define srt(v) sort(v.begin(),v.end())

using namespace std;

void computeLPS(vector<int> &lps, string &p){
    int len = 0, i=1, n=p.size();
    lps[len] = 0;
    while(i < n){
        if(p[i] == p[len]){
            len++;
            lps[i] = len;
            i++;
        }else if(p[i] != p[len]){
            if(len > 0){ 
                len = lps[len - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool kmp_find(string &s, string &p){
    int n = s.size(), m=p.size(), i=0, j=0;
    vector<int> lps(m);
    computeLPS(lps, p);
    while(i < n){
        if(s[i] == p[j]){
            i++;j++;
            if(j == m){
                /*
                    cnt++;
                    j = lps[j-1];
                */
                return true;
            }
        }else{
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return false;
}

vector<int> Zalgo_find(string &s, string &p){
    string w = p + " " + s;
    int n = w.size(),m = p.size();
    int l=0, r=0;
    vector<int> z(n);
    for(int i=1;i<n;i++){
        if(i >= r){
            l = i;
            r = i;
            while(w[r] == w[(r-l)]){
                r++;
            }
            z[i] = (r-l);
        }else{
            int k = i-l;
            z[i] = z[k];
            if(z[k] >= r-i){
                l = i;
                while(w[r] == w[(r-l)]){
                    r++;
                }
                z[i] = (r-l);
            }
        }
    }
    return z;
}

void solve(){

}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}