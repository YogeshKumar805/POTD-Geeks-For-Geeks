class Solution
{
    public:
    
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        
        for(auto ch : x){
            
            if(st.empty() && (ch==')' || ch =='}' || ch==']')){
                return false;
            }
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }else{
                char top = st.top();
                if(top=='[' && ch==']'){
                    st.pop();
                }
                else if(top=='{' && ch=='}'){
                    st.pop();
                }
                else if(top=='(' && ch==')'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }

};
