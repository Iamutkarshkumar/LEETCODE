// class MyQueue {
// public:
//     stack<int> st1,st2;
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         st1.push(x);
//     }
    
//     int pop() {
//         while(!st1.empty()){
//             st2.push(st1.top());
//             st1.pop();
//         }
//         int x=st2.top();
//         st2.pop();
//         while(!st2.empty()){
//             st1.push(st2.top());
//             st2.pop();
//         }
//         return x;
//     }
    
//     int peek() {
//         while(!st1.empty()){
//             st2.push(st1.top());
//             st1.pop();
//         }
//         int x=st2.top();
//         while(!st2.empty()){
//             st1.push(st2.top());
//             st2.pop();
//         }
//         return x;
//     }
    
//     bool empty() {
//         return st1.size()==0;
//     }
// };

// method 2
//T.C : push - O(1), pop - Amortized O(1) , peek() - O(1), empty() - O(1)
//S.C : O(n)
class MyQueue {
public:
    stack<int> input,output;
    int peekEle=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()) peekEle=x;
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int temp=output.top();
            output.pop();
            return temp;
        } 
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int temp=output.top();
            output.pop();
            return temp;
        }
        return -1;
    }
    
    int peek() {
        if(output.empty()) return peekEle;
        return output.top();
    }
    
    bool empty() {
        return input.empty() and output.empty();
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
