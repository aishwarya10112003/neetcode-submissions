class Solution {
public:
    int evalRPN(vector<string>& st) {
     stack<int>stck;
     for(int i=0;i<st.size();i++)
     {
        if(st[i]=="+"||st[i]=="-"||st[i]=="*"||st[i]=="/")
        {
            int num1 = stck.top();stck.pop();
            int num2 = stck.top();stck.pop();
            if(st[i]=="+")
            {
                stck.push(num2+num1);
            }
             if(st[i]=="-")
            {
                stck.push(num2-num1);
            }
             if(st[i]=="*")
            {
                stck.push(num2*num1);
            }
             if(st[i]=="/")
            {
                stck.push(num2/num1);
            }
        }
        else {
            int num = stoi(st[i]);
            stck.push(num);
        }
     }
     
    
     return stck.empty()?0:stck.top();

    }
};
