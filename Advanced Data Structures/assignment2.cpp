/*
Name: Disha Shetty
Roll No: SECOB246
Batch: B3
SE Computer


ASSIGNMENT : 2
For a given expression eg. a-b*c-d/e+f construct inorder sequence and
traverse it using inorder, preorder and post order traversal(non-recursive)
*/

#include<iostream>
#include<cstring>

using namespace std;

typedef struct node
{
	char data;
	struct node *L,*R;
}node;


class stack				//Stack implementation
{
	node* stk[20];
	int top;
public:
	stack()
	{
		top=-1;
	}
	void push(node*);
	node* pop();
	int isEmpty();
	int isFull();
	node* getTop();
};

int stack::isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int stack::isFull()
{
	if(top==19)
		return 1;
	else
		return 0;
}

void stack::push(node *x)
{
	top++;
	stk[top]=x;
}

node* stack::pop()
{
    node *x=stk[top];
    top--;
    return x;
}

node* stack::getTop()
{
	return stk[top];
}


class tree				//Tree implementation
{
public:
	int priority(char);
	int isOpr(char);
	node* create_node(char);
	node* create(char *exp);
	void post(node*);
	void in(node*);
	void pre(node*);
};

int tree::priority(char a)
{
	if(a=='+' || a=='-')
		return 1;
	else if(a=='*' || a=='/')
		return 2;
	else if(a=='^')
		return 3;
	else
		return 0;
}

int tree::isOpr(char a)
{
	if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^')
		return 1;
	else
		return 0;
}

node* tree::create_node(char x)
{
	node *nn;
    nn= new node;
    nn->data=x;
    nn->L=nn->R=NULL;
    return nn;
}

node* tree::create(char *exp)
{
        int i=0;
        stack s1,s2;
        node *opr,*opnd1,*opnd2,*nn;

       while(exp[i]!='\0')
       {
            if(!isOpr(exp[i]))
            {
                nn=create_node(exp[i]);
                s1.push(nn);
            }
            else
            {
                if(!s2.isEmpty())
                {
                    if(priority(s2.getTop()->data) <= priority(exp[i]))
                    {
                     nn=create_node(exp[i]);
                   	 s2.push(nn);                    
                    }
                  	else
                  	{
                                        opr=s2.pop();
                                        opnd2=s1.pop();
                                        opnd1=s1.pop();
           				opr->R=opnd2;
           				opr->L=opnd1;
           				s1.push(opr);
           				nn=create_node(exp[i]);
                    	s2.push(nn);
                  	}

                }
                else
                {
                    nn=create_node(exp[i]);
                    s2.push(nn);
                }
            }
           i++;
       }
       while(!s2.isEmpty())
       {
           opr=s2.pop();
           opnd2=s1.pop();
           opnd1=s1.pop();
           opr->R=opnd2;
           opr->L=opnd1;
           s1.push(opr);
       }
       return s1.pop();
}

void tree::post(node *cn)			//Post order 
{
	stack s1,s2;
    node *temp;
       
        if(cn!=NULL)
        {
            s1.push(cn);
            while(!s1.isEmpty())
            {
                temp=s1.pop();
                s2.push(temp);
                if(temp->L)
                    s1.push(temp->L);
                if(temp->R)
                    s1.push(temp->R);
            }
            while(!s2.isEmpty())
            {
                temp=s2.pop();
                cout<<temp->data;
            }
        }
        else
        {
            cout<<"\nEmpty Tree!\n";
        }
}

void tree::in(node *cn)				//Inorder
{
	stack s;
	
	if(cn==NULL)
  	{
        cout<<"\nEmpty Tree!\n";
    }
    else
    {
        while(1)
        {
            if(cn)
            {
                s.push(cn);
                cn=cn->L;
            }
            else
            {
                if(!s.isEmpty())
                {
                    cn=s.pop();
                    cout<<cn->data;
                    cn=cn->R;
                }
                else
                    break;

            }
        }
    }
}

void tree::pre(node *cn)			//Preorder
{
    stack s;
    node *t;
    	if(cn==NULL)
        {
            cout<<"\nEmpty Tree!\n";
        }
        else
        {
            s.push(cn);
            while(!s.isEmpty())
            {
                t=s.pop();
                cout<<t->data;
                if(t->R)
                    s.push(t->R);
                if(t->L)
                    s.push(t->L);
            }
        }
}

int main()
{
	tree obj;
	char a[30];
	node *z;
	char ch;
	int choice;
	do
	{
		cout<<"\n\t******* MENU *********\n";
		cout<<"\n\t1. Create expression tree";
		cout<<"\n\t2. Display Inorder ";
		cout<<"\n\t3. Display Postorder ";
		cout<<"\n\t4. Display Preorder ";
		cout<<"\n\t5. Exit";
		cout<<"\n\n\tEnter ur choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter infix expression: ";
				cin>>a;
				cout<<"\nInfix expression is  "<<a;
				z=obj.create(a);
				break;
			case 2:
				cout<<"\n\nInorder : ";
				obj.in(z);
				break;
			case 3:
				cout<<"\n\nPostorder : ";
				obj.post(z);
				break;
			case 4:
				cout<<"\n\nPreorder : ";
				obj.pre(z);
				break;
			case 5:
				cout<<"\nBye...\n";
				return 0;
			default:
				cout<<"\nInvalid choice....\n";
				
		}
		cout<<"\nContinue(y/n): ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	
	return 0;
}

