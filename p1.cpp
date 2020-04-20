#include<iostream>

struct Stack
{
	int max_size;
	char a[100];
	int current_size;
};

typedef struct Stack Stack;


//Iitializing the Stack
void init(Stack* S)
{
	S->current_size = 0;
}

//Checking whether the stack is empty or not
bool Empty(Stack *S)
{
	return(S->current_size == 0);
}

//Checking whether the Stack is Full or Not
bool Full(Stack *S)
{
	return(S->current_size == S->max_size);
}

//Displaying the Top value of the stack
bool Top(Stack *S, char &element)
{
	if(Empty(S))
		return false;
	else
		{
			element = S->a[S->current_size-1];
			return true;
		}
	
}

//Inserting a value at the top of the stack
bool Push(Stack *S, char d)
{
	if(Full(S))
		return false;
	else
	{
		S->a[S->current_size++] = d;
		return true;	
	}	
}


//Removing a value from the top of the stack
bool Pop(Stack *S, char &element)
{
	if(Empty(S))
		return false;
	else
	{
		S->current_size--;
		element = S->a[S->current_size];
		return true;
	}
}

int main()
{
	std::cout<<"Enter the value for the stack \n";
	int size;
	std::cin >> size;
	std::cout<<"The size of the stack is " << size <<"\n";
	Stack s1; 
	s1.max_size = size;
	char element;
	
	//Pushing element 1 to stack
	element = 'A';
	if(Push(&s1, element) == true)
		std::cout<<"Element is "<<element<<std::endl;
	else
		std::cout<<"Error cannot push because stack is full"<<std::endl;
	
	//Accessing Top Element
	if(Top(&s1, element) == true)
		std::cout<<"Top element is"<<element<<std::endl;
	else
		std::cout<<"Erro : Stack is Empty"<<std::endl;
		
	//Pop all elements from stack
	for(int i=0; i<=size; i++)
	{
		if(Pop(&s1, element) == true)
			std::cout<<"Element Popped: "<<element<<std::endl;
		else
		{
			std::cout<<"Error cannot pop, Stack Empty"<<std::endl;
			break;
		}
	}
	
	return 0;
}
