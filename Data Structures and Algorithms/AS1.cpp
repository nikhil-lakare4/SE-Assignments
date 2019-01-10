#include <iostream>
#include <string.h>

using namespace std;

class student 
{
	string name[50];
	int marks[50], N, abstd;
	public:
	void accept();
	void absent();
	bool allabs();
	float average();
	int highlow();
	int mostmarks();
};

void student :: accept() 
{
	
	cout << endl << "Enter the total number of student (not more than 50): ";
	cin >> N;
	cout << endl << "Enter the name and marks of students: " << endl;
	for(int i = 0; i < N; i++) 
	{
		cin >> name[i] >> marks[i];
	}
	cout << endl << "You have entered the following details: " << endl;
	for(int j = 0; j < N; j++) 
	{
		cout << name[j] << "\t" << marks[j] << endl;
	}
}

void student :: absent()
{       
        abstd = 0;
	cout << endl << "List of absent students is: " << endl;
	for(int i = 0; i < N; i++)
	{	
		if(marks [i] == -1)
		{
			cout << name[i] << endl;
			abstd++;
		}	
	}
	
	if(abstd == 0)
		cout << endl << "No ansent students :)" << endl;
}

bool student :: allabs()
{
        if(abstd == N)
                return true;
        else 
                return false;
}

float student :: average()
{
	float sum = 0, count = 0;
	for(int i = 0; i < N; i++)
	{
		if(marks[i] == -1)
			count++;
		else
			sum = sum + marks[i]; 
	}
	cout << endl << "Average score of class is " << sum / (N - count) << endl;
	
	return 0;
}

int student :: highlow()
{
	int min = 1000;
	for(int i = 0; i < N; i++)
	{
		if(marks[i] != -1)
		{
			if(min > marks[i])
				min = marks[i];
		}
		
	}
	
	int max = 0;
	for(int j = 0; j < N; j++)
	{	
		if(marks[j] != -1)
		{
			if( max < marks[j])
			max = marks[j];
		}
	
	}
	
	cout << endl << "Max marks is " << max << " and Min marks is " << min << endl;
	
	return 0;
}

int student :: mostmarks()
{
	int count = 0;
	int freq[100];
	int maxm =0;
	for(int l = 0; l < 100; l++)
	{
	        freq[l] = 0;
	}
	for(int i = 0; i < N; i++)
	{
		count = 0;
		
		if(marks[i] != -1)
		{
		        for(int j = 0; j < N; j++)
		        {
			        if(marks[i] == marks[j])
				        count++;
		        }
		        freq[marks[i]] = count;
		}
	}
	
	int max = freq[0];
	
	for(int k = 0; k < 100; k++)
	{	
		if(k + 1 == 100)
		{
			break;
		}
		else
		{
		        if( max < freq[k + 1])
		        {
			        max = freq[k + 1];
			        maxm = k + 1;
		        }
		}
	} 
	
	if(max == 1)
	        cout << endl << "Every student has unique marks" << endl << endl;
	else
	cout << endl << "Most of the students i.e. " << max << " students scored "<< maxm << " Marks" << endl << endl; 
	
	return 0;
}


int main()
{
	student s;
	s.accept();
	s.absent();
	
        if(s.allabs() == true)
        {
                cout << endl << "All students are absent! :( Can't perform further operations!" << endl << endl;
        }
        else
        {
	        s.average();
	        s.highlow();
	        s.mostmarks();
	}
}
