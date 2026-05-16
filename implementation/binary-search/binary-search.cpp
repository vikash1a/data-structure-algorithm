#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> v, int k){
    int n = v.size()-1;
    int s = 0, e = n;
    while(s<=e){
        int m = s+(e-s)/2;
        if(v[m] < k)s=m+1;
        else if(v[m] > k)e = m-1;
        else return m;
    }
    return -1;
}
int main(){
    vector<int> v = {1,2,3,5,6,7};
    int ans = binarySearch(v,5);
    cout<<" ans "<< ans <<endl;
    return 0;
}
