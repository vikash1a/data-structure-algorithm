#include <bits/stdc++.h>
using namespace std;

void print(vector<string> test){
    for(int i=0;i<=test.size()-1;i++){
        cout<<test[i]<<"_";
    }cout<<endl;
    return;
}

vector<string> quickSort(vector<string> vs){
    int n = vs.size()-1;
    if(n+1<=1)return vs;
    vector<string> left, right;
    for(int i=0;i<=n-1;i++){
        if(vs[i] < vs[n])left.push_back(vs[i]);
        else right.push_back(vs[i]);
    }
    left = quickSort(left);
    right = quickSort(right);
    vector<string> ans;
    ans.reserve( left.size() + right.size() +1); // preallocate memory
    ans.insert( ans.end(), left.begin(), left.end() );
    ans.push_back(vs[n]);
    ans.insert( ans.end(), right.begin(), right.end() );

    return ans;
}

int main() {
    // vector<string> test = {"1","9","3","4","8","7"};
    vector<string> test = {"10","80","30","90","40","50","70"};
    test = quickSort(test);
    print(test);
    std::cout << "Hello World!\n";
    return 0;
}


