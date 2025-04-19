#include <bits/stdc++.h>
using namespace std;

void print(vector<string> test){
    for(int i=0;i<=test.size()-1;i++){
        cout<<test[i]<<"_";
    }cout<<endl;
    return;
}
vector<string> merge(vector<string> v1, vector<string> v2){
    vector<string> ans;
    int n1 = v1.size()-1,n2 = v2.size()-1;
    int i1=0,i2=0;
    while(1){
        if(v1[i1]<=v2[i2]){
            ans.push_back(v1[i1]);
            i1++;
        }
        else{
            ans.push_back(v2[i2]);
            i2++;
        }
        if(i1>n1 || i2>n2)break;
    }
    while(i1<=n1){
        ans.push_back(v1[i1]);
        i1++;
    }
    while(i2<=n2){
        ans.push_back(v2[i2]);
        i2++;
    }
    return ans;
}
vector<string> mergeSort(vector<string> vs){
    int nvs = vs.size();
    if(nvs <=1)return vs;
    vector<string> v1 = vector<string>(vs.begin(),vs.begin()+nvs/2);
    vector<string> v2 = vector<string>(vs.begin()+nvs/2,vs.end());
    v1 = mergeSort(v1);
    v2 = mergeSort(v2);
    vs = merge(v1,v2);
    // cout<<"v1 - ";print(v1);
    // cout<<"v2 - ";print(v2);
    // print(vs);
    return vs;
}

int main() {
    vector<string> test = {"1","9","3","4","8","7"};
    test = mergeSort(test);
    print(test);
    std::cout << "Hello World!\n";
    return 0;
}


