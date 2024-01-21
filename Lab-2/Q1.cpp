#include <bits/stdc++.h>
using namespace std;

vector<int> Merge(vector<int> &a, vector<int> &b){
    int n = a.size(), m = b.size();
    vector<int> c(n+m);
    int i=0, j=0, k=0;
    while(k < m+n){
        if(j == m || a[i] <= b[j])
            c[k++] = a[i++];
        if(i == n || a[i] > b[j])
            c[k++] = b[j++];
    }
    return c;
}

vector<int> Union(vector<int> &a, vector<int> &b){
    int n = a.size(), m = b.size();
    vector<int> c;
    int i=0, j=0;
    while(i < n && j < m){
        if(c.size() > 0 && c.back() == a[i])
            i++; 
        else if(c.size() > 0 && c.back() == b[j])
            j++;
        else if(a[i] <= b[j])
            c.push_back(a[i++]);
        else if(a[i] > b[j])
            c.push_back(b[j++]);
    }
    while(i<n){
        if(c.back() != a[i])
            c.push_back(a[i]);
        i++;
    }while(j<m){
        if(c.back() != b[j])
            c.push_back(b[j]);
        j++;
    }
    return c;
}

vector<int> Intersection(vector<int> &a, vector<int> &b){
    int n = a.size(), m = b.size();
    vector<int> c;
    int i=0, j=0;
    while(i < n && j < m){
        if(a[i] < b[j])
            i++;
        else if(a[i] > b[j])
            j++;
        else{
            if(!c.size() || c.back() != a[i])
                c.push_back(a[i]);
            i++; j++;
        }
    }
    return c;
}

int main(){
    freopen("test_cases_Q1.txt","r",stdin);
    freopen("output_Q1.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int j=0; j<m; j++)
            cin >> b[j];
        vector<int> marr = Merge(a, b);
        vector<int> iarr = Intersection(a, b);
        vector<int> uarr = Union(a, b);
        cout << "Merged Array: ";
        for(auto x:marr)
            cout << x << " ";
        cout << endl;
        cout << "Intersection Array: ";
        for(auto x:iarr)
            cout << x << " ";
        cout << endl;
        cout << "Union Array: ";
        for(auto x:uarr)
            cout << x << " ";
        cout << endl;
    }
}