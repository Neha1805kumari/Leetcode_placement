class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n);         //temperorily return the ans vector 
        stack<int > st;
        for (int i =n-1; i>=0;i--){
            while (!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if (!st.empty()){
                ans[i]=st.top();
            }else{
                ans[i] =-1;
            }
            st.push(nums2[i]);
        }
        unordered_map <int, int> mp;
        for (int i=0 ; i<n;i++){
            mp[nums2[i]]=ans[i];
        }
        vector <int> final_a;
        for (int x : nums1){
            final_a.push_back(mp[x]);
        }
        return final_a;


    }
};