class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        input.push(x);
    }
    
    int pop() 
    {
        if(!output.empty())
        {
            int val = output.top();
            output.pop();
            return val;
        }
        else
        {
            while(!input.empty())
            {
                int temp = input.top();
                output.push(temp);
                input.pop();
            }
            int val = output.top();
            output.pop();
            return val;
        }
    }
    
    int peek() 
    {
        if(!output.empty())
        {
            return output.top();
        }
        else
        {
            while(!input.empty())
            {
                int temp = input.top();
                output.push(temp);
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() 
    {
        if(output.empty() && input.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */