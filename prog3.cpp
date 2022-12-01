/*
CSC 1254 Project 3 - Thomas O'Donnell 
*/
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;


class Node
{
public:
    Node(int value) { data = value; }
    Node* nextNode;
    int data;
};


class Stack
{
public:
    Stack() { top = nullptr; }

    static void EmptyAccess()
    {
        cout << "Error trying to pop on empty stack" << endl;
        exit(42);
    }

    bool isEmpty() { return top == nullptr; }

    void push(int value)
    {
        if (isEmpty()) { top = new Node(value); }
        else
        {
            Node* oldTop = top;
            top = new Node(value);
            top->nextNode = oldTop;
        }
    }

    int pop()
    {
        if(isEmpty()) { Stack::EmptyAccess(); }
        else
        {
            Node* topReturning = top;
            top = top->nextNode;
            int returningData = topReturning->data;
            delete topReturning;
            return returningData;
        }
    }

protected:
    Node* top;
};


void postfixStackAdd(Stack* stack)
{
    int a, b, c; 
    a = stack -> pop(); 
    b = stack -> pop(); 
    c = a + b; 
    stack -> push(c);
     /*}
    else {

        int a;
        a = stack -> pop();  
        a++; 
        stack -> push(a); 
    } */
    return; 
}

//not sure if I am iterating right, am I reading input from left to right?
void postfixStackMultiAdd(Stack* stack)
{
    int i = 0, a, b = 0; 
    a = stack -> pop(); 
    for (; i < a; i++) b += stack -> pop(); 
    stack -> push (b);
}


void postfixStackMultiply(Stack* stack)
{
    int a, b, c; 
    a = stack -> pop(); 
    b = stack -> pop(); 
    c = a * b; 
    stack -> push(c);
    return; 

}


void postfixStackSubtract(Stack* stack)
{
    int a, b, c; 
    a = stack -> pop(); 
    b = stack -> pop(); 
    c = b - a; 
    stack -> push(c);
    return;

}


void postfixStackDivide(Stack* stack)
{
    int a, b, c; 
    a = stack -> pop(); 
    b = stack -> pop(); 
    c = b / a; 
    stack -> push(c);
    return;
// do I need to account for remander?
// or is this asking for integer division as structured above?
}

//not sure if order is right here.
void postfixStackPower(Stack* stack)
{
    int a, b, c; 
    a = stack -> pop(); 
    b = stack -> pop(); 
    c =  pow(b,a); 
    stack -> push(c);
    return;

}


void postfixStackFactorial(Stack* stack)
{
    int a, b = 1; 
    a = stack -> pop(); 
    for(int i = a;i > 1; i--) b *= i; 
    stack -> push(b);
}


void postfixStackIncrement(Stack* stack)
{
    int a; 
    a = stack -> pop();
    a++; 
    stack -> push(a); 
}


void postfixStackModulo(Stack* stack)
{
    int a, b, c; 
    a = stack -> pop(); 
    b = stack -> pop(); 
    c =  b % a; 
    stack -> push(c);
    return;
}


void postfixStackDecrement(Stack* stack)
{
    int a; 
    a = stack -> pop();
    a--; 
    stack -> push(a); 

}


void postfixStackAbsoluteValue(Stack* stack)
{
    int a; 
    a = stack -> pop(); 
    a = abs(a); 
    stack -> push(a); 
}


// Don't edit any of the code below this.
void postfixStackPrint(Stack* stack)
{
    cout << stack->pop() << endl;
}


void processTerm(string term, Stack* stack)
{
    if (term == "+")        postfixStackAdd(stack);

    else if (term == "&+")  postfixStackMultiAdd(stack);

    else if (term == "*")   postfixStackMultiply(stack);

    else if (term == "-")   postfixStackSubtract(stack);

    else if (term == "/")   postfixStackDivide(stack);

    else if (term == "^")   postfixStackPower(stack);

    else if (term == "!")   postfixStackFactorial(stack);

    else if (term == "++")  postfixStackIncrement(stack);

    else if (term == "%")   postfixStackModulo(stack);

    else if (term == "--")  postfixStackDecrement(stack);

    else if (term == "||")  postfixStackAbsoluteValue(stack);

    else if (term == "p")   postfixStackPrint(stack);

    else stack->push(stoi(term));
}


void processPostfixExpression(string inputString)
{
    Stack* stack = new Stack();

    char space = ' ';
    stringstream sstream(inputString);
    string term;

    while (getline(sstream, term, space)) { processTerm(term, stack); }
}


int main()
{
    string postfixInputString;
    getline(cin, postfixInputString);
    processPostfixExpression(postfixInputString);
}