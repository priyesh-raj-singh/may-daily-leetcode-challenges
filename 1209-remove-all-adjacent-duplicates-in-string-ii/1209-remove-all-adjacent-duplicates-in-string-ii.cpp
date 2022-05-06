class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty() || st.top().first!=s[i]){
                st.push({s[i],1});
            }
            else{
                auto prev=st.top();
                st.pop();
                st.push({s[i],prev.second+1});
            }
            if(st.top().second==k){
                st.pop();
            }
        }
        
        string result="";
        while(!st.empty()){
            auto element=st.top();
            st.pop();
            while(element.second--){
                result.push_back(element.first);
            }
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};