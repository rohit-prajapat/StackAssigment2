class Solution {
public:
    bool isValid(string s) {
        
        stack<char>data;
        int size = s.size();
        if(size%2) return 0;
        if(size ==0 )return 1;
        data.push(s[0]);
        for(int i=1; i<size; i++)
        {

            
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            data.push(s[i]);
            if(s[i] == ')' &&( !data.size() || data.top()!= '(' )) return 0;
            if(s[i] == ']' && ( !data.size() || data.top()!= '[' )) return 0;
            if(s[i] == '}' && ( !data.size() || data.top()!= '{' )) return 0;

           

           if(s[i] == ')' && data.top()== '(') data.pop();
            if(s[i] == ']' && data.top()== '[') data.pop();
            if(s[i] == '}' && data.top()== '{') data.pop();

        }
      
        if(data.size() == 0) return 1;
        else return 0;
    }
};


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int>ans;
        ans.push_back(0);
        if(head->next == nullptr)  return ans;
        
        vector<int>helper;
        stack<int>s;

        while(head)
        {
            helper.push_back(head->val);
            head= head->next;
        }   
        int ei = helper.size()-1;
        s.push(helper[ei]);
        
        for(int i = ei-1; i>=0; i--)
        {
           
            while(s.size()>0 && helper[i]>=s.top())
            {
                s.pop();
            }

            if(s.size() == 0)
            {
                ans.push_back(0);
            }
            else{
                 ans.push_back(s.top());
                
            }
            
            s.push(helper[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


class Solution {
public:

    void display(vector<int>arr)
    {
        for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";

        cout<<endl;
    }
    vector<int> finalPrices(vector<int>& prices) {
        
        int size = prices.size();
         vector<int>discount;
         discount.push_back(0);
        if(size == 1) return discount;
        stack<int>s;
        int ei = prices.size()-1;

        s.push(prices[ei]);
       
        
        for(int i = ei-1; i>=0; i--)
        {
            while(s.size()> 0 && s.top()>prices[i])
            {
                s.pop();
            }
            if(s.size()>0)
            discount.push_back(s.top());
            else 
            discount.push_back(0);

            s.push(prices[i]);
        }
        reverse(discount.begin(),discount.end());
        display(discount);
        for(int i=0; i<size; i++)
        {
            prices[i] -= discount[i];
        }
        return prices;

    }
};


