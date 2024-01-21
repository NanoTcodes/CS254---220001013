#include <bits/stdc++.h>
using namespace std;

int md_partition(vector<int> &a, int l , int r){
    int lst = a[r], p = l;
    for(int i = l; i <= r; i++){
        if(a[i] < lst)
            swap(a[i], a[p++]);
    }
    swap(a[r], a[p]);
    return p;
}

int random_partition(vector<int> &a, int l, int r){
    int n = r - l + 1;
    int p = (rand() % n);
    swap(a[l + p], a[r]);
    return md_partition(a, l, r);
}

void median(vector<int> &a, int l, int r, int k, int &md1, int &md2){
    if(l > r)
        return;
    int par = random_partition(a, l, r);
    if(par == k){
        md2 = a[par];
        if(md1 != -1)
            return;
    }
    else if(par == k-1){
        md1 = a[par];
        if(md2 != -1)
            return;
    }
    if(par >= k)
        median(a, l, par-1, k, md1, md2);
    else
        median(a, par+1, r, k, md1, md2);
}

int find_median(vector<int> a){
    int md1 = -1, md2 = -1, n = a.size();
    median(a, 0, n-1, n/2, md1, md2);
    return md2;
}

int median_position(vector<int> &a, int l, int r){
    if(l == r)
        return l;
    vector<int> b;
    for(int i=l; i <= r; i++)
        b.push_back(a[i]);
    int mdv = find_median(b);
    for(int i=l; i<=r; i++)
        if(a[i] == mdv)
            return i;
}

int partition(vector<int> &a, int l, int r){
    int p = median_position(a, l, r);
    swap(a[p], a[r]);
    int piv = a[r];
    int lo = l;
    for(int i=l; i<r; i++){
        if(a[i] < piv)
            swap(a[i], a[lo++]);
    }
    swap(a[lo], a[r]);
    return lo;
}

void quick_sort(vector<int> &a, int l, int r){
    if(l >= r)
        return;
    int p = partition(a, l, r);
    quick_sort(a, l, p-1);
    quick_sort(a, p+1, r);
}

int main(){
    freopen("test_cases_Q6.txt","r",stdin);
    freopen("output_Q6.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        quick_sort(a, 0, n-1);
        cout << "Sorted Array: ";
        for(auto x:a)
            cout << x << " ";
        cout << endl;
    }
}