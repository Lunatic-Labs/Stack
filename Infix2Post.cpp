//Created By Ian Reitmaier

// I got this code from a youtube video but I implemented my LStack
// Here is the link: https://www.youtube.com/watch?v=vq-nUF0G4fI 

#include "LStack.cpp"
#include "Logger.cpp"
#include<string>
#include <fstream>
#include <sstream>

using namespace std;

// Function to convert Infix expression to postfix 
string InfixToPostfix(string expression);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator or not. 
bool IsOperator(char C);

// Function to verify whether a character is a letter or numeric digit or not. 
bool IsOperand(char C);
int EvalPostfix(string e);

int main() 
{
	Logger logger("./test.txt");
	string expression;
	int var;
	cout << "Enter Infix Expression: \n";
	getline(cin,expression);
	string postfix = InfixToPostfix(expression);
	var = EvalPostfix(postfix + ")");
	stringstream ss;
	ss << var;
	string newString = ss.str();
	logger.EnableConsoleLogging();
	logger.Log("Output = " + postfix);
	logger.Log("Evaluation = " + newString); 

	
}

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
	// Declaring a Stack from the LStack that we created
	LStack<char> S;
	string postfix = ""; // Initialize postfix as empty string.
	for(int i = 0; i < expression.length(); i++) 
    {

		// Scanning each character from left.  
		if(expression[i] == ' ' || expression[i] == ',')
        {
            continue;
        } 

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if(IsOperator(expression[i])) 
		{
			while(!S.IsEmpty() && S.Top() != '(' && HasHigherPrecedence(S.Top(),expression[i]))
			{
				postfix+= S.Top();
				S.Pop();
			}
			S.Push(expression[i]);
		}
		// Else if character is an operand
		else if(IsOperand(expression[i]))
		{
			postfix += expression[i];
		}

		else if (expression[i] == '(') 
		{
			S.Push(expression[i]);
		}

		else if(expression[i] == ')') 
		{
			while(!S.IsEmpty() && S.Top() !=  '(') 
            {
				postfix += S.Top();
				S.Pop();
			}
			S.Pop();
		}
	}

	while(!S.IsEmpty()) 
    {
		postfix += S.Top();
		S.Pop();
	}

	return postfix;
}
int EvalPostfix(string e)
{
	string eval;
    char ch;
    int val;
    int A;
	int B;
	LStack <char> myStack;
	char postfix[100];
	for(int i = 0; i < e.length(); i++)
	{
		postfix[i] = e[i];
	}

    /* evaluate postfix expression */
    for (int i = 0; postfix[i] != ')'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            //we saw an operand,push the digit onto stack
			//ch - '0' is used for getting digit rather than ASCII code of digit 
            myStack.Push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            //we saw an operator
			//pop top element A and next-to-top elemnet B
			//from stack and compute B operator A

            A = myStack.Pop();
            B = myStack.Pop();

            switch (ch) 
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            
            myStack.Push(val);
        }
    }
    return(myStack.Pop());
}

// Function to verify whether a character is english letter or numeric digit. 
bool IsOperand(char C) 
{
	if(C >= '0' && C <= '9'){
        return true;
    } 
	if(C >= 'a' && C <= 'z'){
        return true;
    }
	if(C >= 'A' && C <= 'Z'){
        return true;
    }
    else{
        return false;
    }
	
}

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C)
{
	if((C == '+') || (C == '-') || (C == '*') || (C == '/') || (C== '$')){
        return true;
    }
    else{
        return false;
    }
}

// Function to verify whether an operator is right associative or not. 
int IsRightAssociative(char op)
{
	if(op == '$'){
        return true;
    }
    else{
        return false;
    }
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative. 
	// return false, if right associative. 
	// if operator is left-associative, left one should be given priority. 
	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)){
            return false;
        }
		else
        {
            return true;
        }
	}
    else
    {
        return op1Weight > op2Weight ?  true: false;
    }
	
}
