/*
Name: Disha Shetty
Roll No: SECOB246
Batch: B3
SE Computer


ASSIGNMENT : 7
Consider telephone book database of N clients. Make use of a hash table implementation to
quickly look up client‘s telephone number.
*/


#include<iostream>
#define SIZE 10
using namespace std;

typedef struct telephone
{
	long number;
	string name;
}TELE;

int hashfun(long key)
{
return(key%SIZE);
}

class phone
{
	TELE *HT[SIZE];
	bool full[SIZE];
public:
	int pos;
	long key;

	void HashTable();
	void insert(TELE *rec);
	void display();
	void search(long key);
};

void phone::HashTable()
{

	for(int i=0;i<SIZE;i++)
	{
		full[i]=0;
	}
}

void phone::insert(TELE *rec)
{
	key=rec->number;
	pos=hashfun(key);
	for(int i=0;i<SIZE;i++)
	{
		if(!full[pos])
		{
			HT[pos]=rec;
			full[pos]=1;
			return;
		}
		else
		{
			pos=(pos+1)%SIZE;
		}
	}
	cout<<"Hash table is full";
}

void phone::display()
{
	cout<<"\nIndex\tNumber\t\tName\n";
	for(int i=0;i<SIZE;i++)
	{
		if(full[i]==0)
		cout<<i<<"\t"<<"-"<<"\t\t"<<"-\n";
		else
		cout<<i<<"\t"<<HT[i]->number<<"\t"<<HT[i]->name<<"\n";
	}
}

void phone::search(long key)
{
	pos=hashfun(key);
	for(int i=0;i++;i<SIZE)
	{
		if(full[pos] && (HT[pos]->number)==key)
		{
			break;
		}
		else
		{
			pos=(pos+1)%SIZE;
		}
	}
	
	if(full[pos] && (HT[pos]->number)==key)
	{
		cout<<"\nKey is present\n\n";
		cout<<HT[pos]->number<<"\t"<<HT[pos]->name<<"\n\n";
		
	}
	else
		cout<<"\nKey is not present\n\n";
}

int main()
{
	long key1;
	int i;
	char ch;
	phone h;
	h.HashTable();
	do
	{


		TELE *rec;
		rec=new TELE;
		cout<<"\nEnter number:";
		cin>>rec->number;
		cout<<"\nEnter name:";
		cin>>rec->name;
		h.insert(rec);
		cout<<"\nDo you want to continue(y/n):";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	h.display();
	cout<<"\nEnter phone number you want to search : ";
	cin>>key1;

	h.search(key1);
	
	return 0;
}

