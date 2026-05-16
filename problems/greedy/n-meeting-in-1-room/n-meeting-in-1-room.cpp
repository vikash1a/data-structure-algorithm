#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

vector<int> getMeetings(int n, vector<int> startTime, vector<int> endTime){
    vector<pair<int,int>> vp;
    vector<int> result;
    for(int i=0;i<=n-1;i++){
        vp.push_back(pair(startTime[i], endTime[i]));
    }
    sort(vp.begin(), vp.end(), compare);
    int lastTime = 0;
    for(int i=0;i<=n-1;i++){
        if(vp[i].first >lastTime){
            result.push_back(i+1);
            lastTime = vp[i].second;
        }
    }

    return result;
}

int main() {
    vector<int> result = getMeetings(6, {1,3,0,5,8,5}, {2,4,5,7,9,9});
    for(int k: result)cout<<k<<" ";
    cout<<endl;
    std::cout << "Hello World!\n";
}