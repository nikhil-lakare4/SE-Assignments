/*
Name: Disha Shetty
Roll No: SECOB246
Batch: B3
SE Computer


ASSIGNMENT : 10
Department maintains a student information. The file contains roll number, name, division
and address. Allow user to add, delete information of student. Display information of
particular employee. If record of student does not exist an appropriate message is displayed.
If it is, then the system displays the student details. Use sequential file to main the data.
*/

#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class phonebook
{
	char name[20],phno[15];
public:
	void getdata();
	void showdata();
	char *getname(){return name;}
	char *getphno(){return phno;}	
	void update(char *nm,char *telno)
	{
		strcpy(name,nm);
		strcpy(phno,telno);
	}
};

void phonebook::getdata()
{
	cout<<"\n\nEnter name: ";
	cin>>name;
	cout<<"\nEnter telephone number: ";
	cin>>phno;
}

void phonebook::showdata()
{
	cout<<"\n\t"<<name<<"\t"<<phno;
}

int main()
{
	phonebook rec;
	fstream file;
	file.open("/home/dell-pc/phone.txt",ios::in | ios::out | ios::ate | ios::binary);
	char nm[15],telno[15];
	char op,c;
	int ch,found=0,cnt=0;
	
	do
	{
		cout<<"\n\t********** MENU **********\n\n";
		cout<<"\t1. Add Record\n";
		cout<<"\t2. Display all Record\n";
		cout<<"\t3. Search by name\n";
		cout<<"\t4. Search by telephone number\n";
		cout<<"\t5. Update Record\n";
		cout<<"\t6. Exit\n\n";
		cout<<"\tEnter ur choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				rec.getdata();
				cin.get(c);
				file.write((char*)&rec,sizeof(rec));
				break;
			case 2:
				file.seekg(0,ios::beg);
				cout<<"\n\t******* All Records ********\n\n";
				while(file)
				{
					file.read((char*)&rec,sizeof(rec));
						if(!file.eof())
						{
							rec.showdata();
						}
				}
				file.clear();
				break;
			case 3: 
				cout<<"\nEnter name: ";
				cin>>nm;
				file.seekg(0,ios::beg);
				found=0;
				while(file.read((char*)&rec,sizeof(rec)))
				{
					if(strcmp(rec.getname(),nm)==0)
					{
						found=1;
						rec.showdata();
					}			
				}
				file.clear();
				if(found==0)
				{
					cout<<"\n\tRecord not found....\n";
				}
				break;
				
			case 4:
				cout<<"\nEnter Telephone no: ";
				cin>>telno;
				file.seekg(0,ios::beg);
				found=0;
				while(file.read((char*)&rec,sizeof(rec)))
				{
					if(strcmp(rec.getphno(),telno)==0)
					{
						found=1;
						rec.showdata();
					}			
				}
				file.clear();
				if(found==0)
				{
					cout<<"\n\tRecord not found....\n";
				}
				break;
				
			case 5:
				cout<<"\nEnter name: ";
				cin>>nm;
				file.seekg(0,ios::beg);
				found=0;
				while(file.read((char*)&rec,sizeof(rec)))
				{
					cnt++;
					if(strcmp(rec.getname(),nm)==0)
					{
						found=1;
						break;
					}			
				}
				file.clear();
				if(found==0)
				{
					cout<<"\n\tRecord not found....\n";
				}
				else
				{
					int location;
					location=(cnt-1)*sizeof(rec);
					cin.get(c);
					if(file.eof())
					file.clear();
					
					cout<<"\nEnter new no: ";
					cin>>telno;
					file.seekp(location);
					rec.update(nm,telno);
					file.write((char*)&rec,sizeof(rec));
					file.flush();
				}	
				break;
		}
		cout<<"\n\nDo u want ot continue(y/n): ";
		cin>>op;
		
	}while(op=='y'||op=='Y');
}
