#include<iostream>
#include<string.h>
using namespace std;

class str
{
	string Name1, Name2, con;
	int l1, l2;
	public:
		void accept();
		void strlength();
		void strcopy();
		void strconcat();
		void strequal();
		void strsubs();
		void strreverse();
			
};

void str :: accept()
{	
	cout << "Enter the 1st string: ";
	getline(cin, Name1);
	cout << endl << "Enter the 2nd string: ";
	getline(cin, Name2);
	cout << endl << endl;		
}

void str :: strlength()
{	
	l1 = 0;
	for(int i = 0; ; i++)
	{	
		if(Name1[i] == '\0')
			break;
		else
			l1++;			
	}
	cout << "Length of 1st string is " << l1 << endl << endl;
	
	l2 = 0;
	for(int j = 0; ; j++)
	{	
		if(Name2[j] == '\0')
			break;
		else
			l2++;			
	}
	cout << "Length of 2st string is " << l2 << endl << endl;
	
}

void str :: strequal()
{
	
	if(l1 != l2)
		cout << "Strings are not equal!" << endl << endl;
	else
	{
		int flag = 0;
		for(int i = 0; i < l1; i++)
		{
			if(Name1[i] != Name2[i])
				flag++;		
		}
		if(flag == 0)
			cout << "Strings are equal!" << endl << endl;
		else
			cout << "Strings are not equal!" << endl << endl;
	}

}

void str :: strconcat()
{	
	int i;
	for(i = 0; i < l1; i++)
	{
		con[i] = Name1[i];	
	}
	
	i = 0;
	for(int j = l1; j < l1 + l2; j++)
	{
		con[j] = Name2[i];
		i++;
	}
	con[l1 + l2] = '\0';
	
	cout << "Concatination is : ";
	for(int k = 0; k < l1 + l2; k++)
	{
		cout << con[k];
	}
	cout << endl << endl;
}

void str :: strreverse()
{
	cout << "The reverse of 1st string is: ";
	for(int i = l1 -1; i >= 0; i--)
	{
		cout << Name1[i];
	}
	
	cout << endl << endl <<"The reverse of 2nd string is: ";
	for(int j = l2 -1; j >= 0; j--)
	{
		cout << Name2[j];
	}
	cout << endl << endl ;
}

void str :: strsubs()
{	
	string s;
	cout << "Enter the string which is to be searched :";
	getline(cin, s);

	int flag = 0, n = strlen(s.c_str()), count = 0;

        for(int j = 0; j < l1 + l2; j++)
        {	
        	if(flag != n - 1 && j != l1 + l2 -1)
        	{
                	if(s[flag] == con[j] && s[flag + 1] == con[j + 1])
                	{
                	        flag++;
                	}
        	}
                
                if(flag == n - 1)
                {
                	count++;
                	flag = 0;
                }
	}
        	
        if(count > 0)
	        cout << endl << "Found " << count <<" subtrings!" << endl;
	else 
	        cout << endl << "Could not found a single substring!" << endl;
}

void str :: strcopy()
{
	string copy;
	for(int i = 0; i < l1 + l2; i++)
	{
		copy[i] = con[i];
	}
	copy[l1 + l2] = '\0';
	
	cout << "Copied string is : ";
	for(int j = 0; j < l1 + l2; j++)
	{
		cout << copy[j];
	}
	cout << endl << endl;
}

int main()
{
	str s;
	s.accept();
	s.strlength();
	s.strequal();
	s.strreverse();
	s.strconcat();
	s.strcopy();
	s.strsubs();
}

