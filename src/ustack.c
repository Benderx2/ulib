#include <ustack.h>
int PushtoStack(stack_t* stack, int object);
int PopFromStack(stack_t* stack);
int GetItemS(stack_t* stack, int idx);
stack_t* CreateStack(void);
int Duplicate(stack_t* stack);
void SetItemS(stack_t* stack, int idx, int i);
void init_stack_construct(void)
{
	Stack.Duplicate = &Duplicate;
	Stack.GetItem = &GetItemS;
	Stack.Push = &PushtoStack;
	Stack.Pop = &PopFromStack;
	Stack.Create = &CreateStack;
	Stack.SetItem = &SetItemS;
}
int Duplicate(stack_t* stack)
{
	PushtoStack(stack, stack->content[stack->no]);
	return 0;
}
int GetItemS(stack_t* stack, int idx)
{
	if(idx > stack->no){ return -1; }
	else { return (stack->content[idx]); }
}
void SetItemS(stack_t* stack, int idx, int i)
{
	if(idx > stack->no){ return; }
	else { stack->content[idx] = i; }
}
stack_t* CreateStack(void)
{	
	stack_t* new_stack = (stack_t*)malloc(sizeof(stack_t)); // Allocate stack structure
	new_stack->content = NULL;
	new_stack->no = 0 ;
	return new_stack;
}
int PushtoStack(stack_t* stack, int object)
{
	int* new_content_stk = (int*)malloc((stack->no+1)*sizeof(int));
	for(int i = 0; i < stack->no; i++)
	{
		new_content_stk[i] = stack->content[i];
	}
	stack->no++;
	new_content_stk[stack->no] = object;
	free(stack->content);
	stack->content = new_content_stk;
	return 0;
}
int PopFromStack(stack_t* stack)
{
	int a = stack->content[stack->no];
	stack->no--;
	int* new_content_stk = (int*)malloc(stack->no * sizeof(int));
	for(int i = 0; i < stack->no-1; i++)
	{
		new_content_stk[i] = stack->content[i];
	}
	free(stack->content);
	stack->content = new_content_stk;
	return a;
}
