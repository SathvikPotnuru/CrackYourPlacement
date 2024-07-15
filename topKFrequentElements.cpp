// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/description/

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution{
    public:
    vector <int> topKFrequent(vector <int> &nums, int k){
        unordered_map <int,int> frequencyOfElements;
        for(auto el: nums){
            frequencyOfElements[el]++;
        }
        priority_queue <pair<int,int>, vector<pair<int,int>>> pq;
        for(auto ele: frequencyOfElements){
            pq.push({ele.second, ele.first});
        }
        vector <int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
class Question{
    public:
    void questionRequirements(){
        
        int n,k;
        cout << "Enter size of array: ";
        cin >> n;
        cout << "Enter the nums array: ";
        vector <int> nums;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            nums.push_back(x);
        }
        cout << "Enter value of k: ";
        cin >> k;
        
        Solution s;
        vector <int> ans = s.topKFrequent(nums, k);
        cout << "Ans: " << endl;
        for(auto el: ans){
            cout << el << " "; 
        }
        cout << endl;
    }
};

int main(){
    Question q;
    q.questionRequirements();
    return 0;
}