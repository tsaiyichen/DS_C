#include <bits/stdc++.h>

using namespace std;

class Queue{
private:
    stack<int> s1, s2;
public:
    void enqueue(int a);
    int dequeue();
};

class Stack{
private:
    queue<int> q;
public:
    void push(int a);
    int pop();
};

class Stack2{
private:
    queue<int> q1, q2;
public:
    void push(int a);
    int pop();
};

void Queue::enqueue(int a) {
    s1.push(a);
}

int Queue::dequeue() {
    if(s2.empty()){
        if(s1.empty()){
            cout << "queue is empty." << endl;
            return INT_MIN;
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    int item = s2.top();
    s2.pop();
    return item;
}

void Stack::push(int a) {
    q.push(a); //enqueue a
}

int Stack::pop() {
    int k = q.size();
    if(k == 0){
        cout << "Stack is empty." << endl;
        return INT_MIN;
    }
    for(int i = 1; i <= k - 1; i++){
        q.push(q.front());
        q.pop();
    }
    int item = q.front();
    q.pop();
    return item;
}

void Stack2::push(int a) {
    q1.push(a);
}

int Stack2::pop() {
    if(q1.size() == 0){
        cout << "Stack2 is empty." << endl;
        return INT_MIN;
    }
    while(q1.size() > 1){
        q2.push(q1.front());
        q1.pop();
    }

    int item = q1.front();
    q1.pop();

    //swap
    queue temp = q1;
    q1 = q2;
    q2 = temp;

    return item;
}
int main(){
    Queue q;
    cout << q.dequeue() << endl;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.dequeue() << endl;
    q.enqueue(3);
    q.enqueue(4);
    cout << q.dequeue() << endl;
    q.enqueue(5);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    Stack s;
    cout << s.pop() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    s.push(4);
    cout << s.pop() << endl;
    s.push(5);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    Stack s2;
    cout << s2.pop() << endl;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    cout << s2.pop() << endl;
    s2.push(4);
    cout << s2.pop() << endl;
    s2.push(5);
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
}