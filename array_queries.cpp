#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin >>n>>q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }
    multiset<int> ele(arr.begin(), arr.end());
    map<int, int> result;
    for (int k : queries) {
        if (result.find(k) !=result.end()) {
            continue; 
        }
        multiset<int> temp_ele = ele; 
        for (int i = 0; i < k; ++i) {
            if (temp_ele.size() < 2) {
                break;
            }
            auto min_iter = temp_ele.begin();
            auto max_iter = prev(temp_ele.end());
            int min_val = *min_iter;
            int max_val = *max_iter;
            temp_ele.erase(min_iter);
            temp_ele.erase(max_iter);
            int new_val = max_val-min_val;
            temp_ele.insert(new_val);
        }
        int sum = 0;
        for (int x : temp_ele) {
            sum += x;
        }
        result[k] = sum;
    }
    for (int k : queries) {
        cout<<result[k]<<" ";
    }
    cout<<endl;
}
