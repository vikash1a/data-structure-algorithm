#include <iostream>
#include <bits/stdc++.h>
using namespace std;

    int maxProduct(vector<int>& nums) {
        int nn = (int)nums.size()-1;
        vector<vector<int>> vv(nn+1, vector<int>(nn+1, 0));
        for(int length = 0; length<=nn; length++){
            for(int start=0; start+length<=nn; start++){
                if(length == 0)vv[start][start+length] = nums[start];
                else{
                    vv[start][start+length] = max(
                        vv[start][start+length-1],
                        vv[start][start+length]*numm[start+length]
                    );
                }
            }
        }
        return vv[0][nn];
    }

int main() {
    int v = maxProduct(1,2,3,4);
    std::cout << "Hello World!\n";
}