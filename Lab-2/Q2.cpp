#include <bits/stdc++.h>
using namespace std;

int nxt_gap(int gap){
    if(gap <= 1)
        return 0;
    return ceil(gap/2.0);
}

// O(n log(n)) solution
void sort(vector<int> &a, int m){
    int n = a.size();
    if(m == 0 || m == n)
        return;
    for(int cgap = nxt_gap(n); cgap > 0; cgap = nxt_gap(cgap)){
        for(int i=0; i+cgap < n; i++){
            int j = i+cgap;
            if(a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

// We can also use the following O(n) solution if there elements in the array are in the range [1, 10^9]
void lsort(vector<long long> &a, int m){
    int n = a.size();
    int i = 0, j = m, k = 0;
    long long md = 10000000000;
    while(k < n){
        if(j == n || (a[i]%md) < (a[j]%md)){
            a[k] += md*(a[i]%md); 
            i++; k++;
        }
        else if(i == m || (a[i]%md) >= (a[j]%md)){
            a[k] += md*(a[j]%md);
            j++; k++;
        }
    }
    for(int i=0; i<n; i++)
        a[i] = (a[i]/md);
}

int main(){
    freopen("test_cases_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        sort(a, m);
        cout << "Sorted Array: ";
        for(auto x:a)
            cout << x << " ";
        cout << endl;
    }
}