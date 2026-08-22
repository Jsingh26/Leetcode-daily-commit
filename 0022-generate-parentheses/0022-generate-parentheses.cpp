class Solution {
public:
    void solve(int n, vector<string>& ans, int open, int close, string st){
        if(st.size()==n*2){
            ans.push_back(st);
            return ;
        }

        if(open < n){
            st.push_back('(');
            solve(n,ans,open +1,close,st);
            st.pop_back();
        }
        if (close< open){
            st.push_back(')');
            solve(n,ans,open,close + 1,st);
            st.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string st = "";
        solve(n, ans, 0 , 0 , st);
        return ans;
    }
};