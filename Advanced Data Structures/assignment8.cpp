/*
Name: Disha Shetty
Roll No: SECOB246
Batch: B3
SE Computer


ASSIGNMENT : 8
A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
deleting keywords, updating values of any entry. Provide facility to display whole data sorted
in ascending/ Descending order. Also find how many maximum comparisons may require for
finding any keyword. Use Height balance tree and find the complexity for finding a keyword
*/

#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *lt,*rt;
    int ht;

}node;

class Avl
{
    node *root;
    int delFlag;

public:

    void insert(int x){

         root=insert1(root,x);
    }


    void Delete(int x)
    {
        delFlag=0;
        root=Delete1(root,x);

        if(delFlag)
            cout<<"\n Data deleted successfully..\n";
        else
            cout<<"\n Data not found!\n";
    }

    void init(){
         root=NULL;
    }

    void preOrder1();
    void inOrder1();
    void preOrder(node *);
    void inOrder(node *);

    int height(node *);
    node* insert1(node *,int);
    node* Delete1(node *,int);
    node *RR(node *);
    node *LL(node *);
    node *RL(node *);
    node *LR(node *);
    node *rotateRight(node *);
    node *rotateLeft(node *);
    int BF(node *);

};

node* Avl::insert1(node *t, int x)
{
    if(t==NULL)
    {
        t=new node;
        t->data=x;
        t->lt=t->rt=NULL;
    }
    else
        if(x>t->data)
        {
            t->rt=insert1(t->rt,x);
            if(BF(t)==-2)
                if(x>t->rt->data)
                    t=RR(t);
                else
                    t=RL(t);
        }
        else
        {
            t->lt=insert1(t->lt,x);
            if(BF(t)==2)
                if(x<t->lt->data)
                    t=LL(t);
                else
                    t=LR(t);
        }
    t->ht=height(t);
    return t;
}

node *Avl::Delete1(node *t, int x)
{
    node *p;
    if(t==NULL)
        return NULL;
    else
        if(x>t->data)           //case 1
        {
            t->rt=Delete1(t->rt,x);
            if(BF(t)==2)
            {
                if(BF(t->lt)>=0) //+ve BF -> left left
                    t=LL(t);
                else
                    t=LR(t);
            }
        }
        else
         if(x<t->data)          //case 2
        {
           t->lt=Delete1(t->lt,x);
            if(BF(t)==-2)
                if(BF(t->rt)<=0)
                    t=RR(t);
                else
                    t=RL(t);
        }
        else                    //case 3
         {
             delFlag=1;
             //data to be deleted is found
            if(t->rt!=NULL)
            {
                //delete inorder successor
                //Inorder succ of cn = leftmost(cn->rt)
                p=t->rt;
                while(p->lt!=NULL)
                    p=p->lt;

                //copy inorder succ data in node to be deleted, then delete the inorder succ
                t->data=p->data;

                //call delete fun for the inorder successor, which will return root of the subtree
                //attach new subtree to cn's right
                t->rt=Delete1(t->rt,p->data);

                //since right subtree that is returned is already balanced,
                //the imbalance may be caused only by the left subtree, so check if bf==+2 only.
                if(BF(t)==2)
                    if(BF(t->lt)>=0)
                        t=LL(t);
                    else
                        t=LR(t);
            }
            else
                return t->lt;
            //if there is no right subtree, then this is the case of deletion with single child.
            //so directly attach left of node to be deleted to its parent's left/right
         }
    //adjust height for each node if deletion node not found
    //while recursion unwinds all heights will be updated here
    t->ht=height(t);
    return t;
}


//Rotations and Calculations

int Avl::height(node *T)
{
    int lh,rh;
    if(T==NULL)
        return 0;
    if(T->lt==NULL)
        lh=0;
    else
        lh=1+T->lt->ht;
    if(T->rt==NULL)
        rh=0;
    else
        rh=1+T->rt->ht;
    if(lh>rh)
        return lh;
    return rh;
}

node *Avl::rotateRight(node *x)
{
    node *y;
    y=x->lt;
    x->lt=y->rt;
    y->rt=x;
    x->ht=height(x);
    y->ht=height(y);
    return y;
}

node *Avl::rotateLeft(node *x)
{
    node *y;
    y=x->rt;
    x->rt=y->lt;
    y->lt=x;
    x->ht=height(x);
    y->ht=height(y);
    return y;
}

node *Avl::LL(node *x)
{
    x=rotateRight(x);
    return x;
}

node *Avl::RR(node *x)
{
    x=rotateLeft(x);
    return x;
}

node *Avl::LR(node *x)
{
    x->lt=rotateLeft(x->lt);
    x=rotateRight(x);
    return x;
}

node *Avl::RL(node *x)
{
    x->rt=rotateRight(x->rt);
    x=rotateLeft(x);
    return x;
}

int Avl::BF(node *x)
{
    int lh,rh;
    if(x==NULL)
        return 0;
    if(x->lt==NULL)
        lh=0;
    else
        lh=1+x->lt->ht;
    if(x->rt==NULL)
        rh=0;
    else
        rh=1+x->rt->ht;
    return (lh-rh);

}

//Display
void Avl::preOrder(node *x)
{
    if(x!=NULL)
    {
        cout<<" "<<x->data;
        preOrder(x->lt);
        preOrder(x->rt);
    }
}

void Avl::inOrder(node *x)
{
    if(x!=NULL)
    {
        inOrder(x->lt);
        cout<<" "<<x->data;
        inOrder(x->rt);
    }
}

void Avl::preOrder1()
{
    cout<<"\n Preorder:";
    preOrder(root);
    cout<<endl;
}

void Avl::inOrder1()
{
    cout<<"\n Inorder: ";
    inOrder(root);
    cout<<endl;
}


int main()
{
    Avl obj;
    int n,d,ch;

    cout<<"\n******AVL TREE******";
    do{
        cout<<endl;
        cout<<" 1. Create new tree\n";
        cout<<" 2. Insert\n";
        cout<<" 3. Delete\n";
        cout<<" 4. Display\n";
        cout<<" 5. Exit\n";
        cout<<" Enter choice: ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
                    cout<<" Enter number of elements to insert: ";
                    cin>>n;
                    cout<<" Enter elements:\n";
                    obj.init();
                    for(int i=0;i<n;i++)
                    {
                        cout<<" ";
                        cin>>d;
                        obj.insert(d);
                    }
                    break;
        case 2:
                    cout<<" Enter data to insert: ";
                    cin>>d;
                    obj.insert(d);
                    cout<<"\n Data inserted successfully..\n";
                    break;
        case 3:
                    cout<<"\n Enter data to delete: ";
                    cin>>d;
                    obj.Delete(d);
                    break;
        case 4:
                    obj.inOrder1();
                    obj.preOrder1();
                    break;
        case 5:
                    cout<<"\n Exit\n";
                    break;
        default:    cout<<"Invalid choice!\n";
        }
        cout<<"\n---------------------------------------------\n";

    }while(ch!=5);

}
