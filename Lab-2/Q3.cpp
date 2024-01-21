#include <bits/stdc++.h>
using namespace std;

int nxt_gap(int gap){
    if(gap <= 1)
        return 0;
    return ceil(gap/2.0);
}

// O(n log(n)) merge
void merge(vector<int> &a, int l, int r){
    int n = a.size();
    for(int cgap = nxt_gap(r-l+1); cgap > 0; cgap = nxt_gap(cgap)){
        for(int i=l; i+cgap <= r; i++){
            int j = i+cgap;
            if(a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

// O(n * log(n) * log(n)) sort
void sort(vector<int> &a, int l, int r){
    if(l >= r)
        return;
    int mid = l + (r-l)/2;
    sort(a, l, mid);
    sort(a, mid+1, r);
    merge(a, l, r);
}

void sort(vector<int> &a){
    sort(a, 0, a.size()-1);
}

int main(){
    freopen("test_cases_Q3.txt","r",stdin);
    freopen("output_Q3.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        sort(a);
        for(auto x:a)
            cout << x << " ";
        cout << endl;
    }
}