#include <bits/stdc++.h>
#define ll long long
#define el cout << '\n'
#define f0(i,n) for(ll i=0;i<n;i++)
using namespace std;

char* inp_file_name = "bai3";

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    if(inp_file_name != ""){
        char *s = new char[strlen(inp_file_name)+5];
        strcpy(s,inp_file_name);
        strcat(s, ".inp");
        freopen(s,"r",stdin);
        strcpy(s,inp_file_name);
        strcat(s, ".out");
        freopen(s,"w",stdout);
    }

    int n,k; cin >> n >> k;
    pair<int,int> a[n];


    f0(i,n) {cin >> a[i].first;a[i].second=i;}
    ll ans=a[0].first;

    // a[i].first la gia tri cua so hang thu i cua bieu thuc

    // a[i].second = i, muc dich de giu lai index ban dau cua so hang

    sort(a,a+n,greater<pair<int,int>>());
    int i = 0;
    while(k--){
        if(a[i].second != 0) ans+=a[i].first; // bo qua phan tu dau tien
        else k++;
        i++;
    }
    while(i < n){
        if(a[i].second != 0) ans -= a[i].first; // bo qua phan tu dau tien
        i++;
    }
    cout << ans;
    return 0;
}