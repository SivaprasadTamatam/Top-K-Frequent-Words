#include <iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
struct Cmp {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
};


vector<string> topKFrequent(vector<string>& words, int k) {
      map<string, int> mp;
    vector<string> res;
    
    for(auto w :words){
        mp[w]++;
    }
   priority_queue<pair<string, int>, vector<pair<string, int>>, Cmp> pq;
    
    for( auto i : mp){
        pq.push(make_pair(i.first, i.second));
        if(pq.size() > k){
            pq.pop();
        }
    }
    
    while(!pq.empty()){
        auto it = pq.top();
        res.push_back(it.first);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> v = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    
    auto res = topKFrequent(v, 4);
    for(auto w : res){
        cout<<w<<endl;
    }
    return 0;
}
