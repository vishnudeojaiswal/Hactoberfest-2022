class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int n=b.size();
 	    stack<int> s;
        map<int,int> mp;
        vector<int> res;
        int i;
        for(i=n-1;i>=0;i--)
        {   
            while(!s.empty() && s.top() <= b[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                mp[b[i]]=-1;
                s.push(b[i]);
                continue;
            }
            else{
                mp[b[i]]=s.top();
                s.push(b[i]);
            }
        
        }
        n=a.size();
        for(i=0;i<n;i++)
        {
            res.push_back(mp[a[i]]);
        }
        return res;
        }
};
