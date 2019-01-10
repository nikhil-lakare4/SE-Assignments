#include <iostream>
using namespace std;

class players
{
	int total, ncnb;       
        // NC = Number of cricket players, NB = Number of badminton players
	int NC, cricket[20]; 
	int NB, badmint[20];
	
	public:
	        //accept user input
		void accept();
		//for finding union
		void unions();
		//for finding intersection
		void intrsec();
		//only for cricketers by heart
		void ocricket();
		//only for badminton players by heart
		void obadmint();
		//for number of student who don't play anything
		void ncnbf();
};

void players :: accept()
{
	cout << "Enter the total number of students (not more than 20): ";
	cin >> total;
	
        cout << endl << "Number of student who play cricket (not more than 20): ";
        cin >> NC;
        
        cout << endl << "Enter the roll numbers of student who play cricket:" << endl;
	for(int i = 0; i < NC; i++)
	{
		cin >> cricket[i];
	}
	
	cout << endl << "Number of student who play badminton (not more than 20): ";
	cin >> NB;
	
	cout << endl << "Enter the roll numbers of student who play badminton:" << endl;
	for(int j = 0; j < NB; j++)
	{
		cin >> badmint[j];
	}
	
	//To printing recieved input from user	
	cout << endl << "You have entered :" << endl;

	cout << endl << "Students who play cricket = { ";
        for(int k = 0; k < NC; k++)
	{       
	        //for not printing ',' after last element
	        if(k == NC - 1)
	                cout << cricket[k] << " ";
	        else
		        cout << cricket[k] << ", ";
	}
        cout << "}" << endl;

	cout << endl << "Students who play badminton = { ";
        for(int l = 0; l < NB; l++)
	{
	        if( l == NB - 1)
		        cout << badmint[l] << " ";
		else 
		        cout << badmint[l] << ", ";		
	}
        cout << "}" << endl << endl << "Hence," << endl << endl;

}

void players :: intrsec()
{
        int size, temp = 0;
        
        //ternary operator to decide size of intersection array        
        (NB < NC) ? size = NB : size = NC;
        
        int result[size];
        
	for(int i = 0; i < NB; i++)
	{
		for(int j = 0; j < NC; j++)
		{
			if(badmint[i] == cricket[j])
			{
				result[temp] = badmint[i];
				//To keeping track of how many elements are found
				temp++;
				//We are done with current badminton element
				break;
			}
		}
	}

	cout << "Students who play both cricket and badminton = { ";
	for(int k = 0; k < temp; k++)
	{       
	        if( k == temp - 1)
		        cout << result[k] << " ";
		else 
		        cout << result[k] << ", ";
	}
        cout << "}" << endl << endl;
}

void players :: ocricket()
{
	int result[NC], count, temp = 0;
	
	for(int i = 0; i < NC; i++)
	{
	        //Increase count iff current cricket element is present in badminton set 
		count = 0;
		for(int j = 0; j < NB; j++)
		{
			if(cricket[i] == badmint[j])
			 {
			 	count++;
			 	//We are done with current cricket element
				break;
			 }
		}

                //Store the current cricket element iff it is not present in badminton set 
		if(count == 0)
		{
			result[temp] = cricket[i];
			temp++;
		}
	}

	cout << "Students who play only cricket = { ";
	for(int k = 0; k < temp; k++)
	{       
	        if(k == temp - 1)
		        cout << result[k] << " ";
		else
		        cout << result[k] << ", ";
	}
        cout << "}" << endl << endl;

}

void players :: obadmint()
{
	int result[NB], count, temp = 0;
	
	for(int i = 0; i < NB; i++)
	{
	        //Increase count iff current badminton element is present in cricket set 
		count = 0;
		for(int j = 0; j < NC; j++)
		{
			if(badmint[i] == cricket[j])
			 {
			 	count++;
			 	break;
			 }
		}
                //Store the current badminton element iff it is not present in cricket set 
		if(count == 0)
		{
			result[temp] = badmint[i];
			temp++;
		}
	}

	cout << "Students who play only badminton = { ";
	for(int k = 0; k < temp; k++)
	{
	        if(k == temp - 1)
		        cout << result[k] << " ";
		else
		        cout << result[k] << ", ";
	}
        cout << "}" << endl << endl;
}

void players :: unions()
{
        //Max element in union set can be NC+NB, so set it as the size of union array
	int result[NC + NB], count, temp = NC;
	//To set every element of union array to 0 for further simplication for checking
	for(int m = 0; m < NC + NB; m++)
	{
		result[m] = 0;
	}
	//store cricket array in union array as it is
	for(int i = 0; i < NC; i++)
	{
		result[i] = cricket[i];
	}
	//temp = NC cause rest of the badminton elements should get stored after last cricket element in union array
	for(int j = 0; j < NB; j++)
	{
	        //Increase count iff current badminton element is present in resultant set 
		count = 0;
		for(int k = 0; k < NC; k++)
		{
			if(badmint[j] == result[k])
			{
				count++;
				break;
			}
		}
		////Store the current badminton element iff it is not present in resultant set 
		if(count == 0)
		{
			result[temp] = badmint[j];
			temp++;
		}
	}

	cout << "Students who play either cricket or badminton or both = { ";
	
	ncnb = 0;
	
	for(int l = 0; l < NC + NB && result[l] != 0; l++)
	{
	        if(l == NC + NB - 1 || result[l + 1] == 0)
		{        
			cout << result[l] << " ";
			ncnb++;
		}
		else
		{
		        cout << result[l] << ", ";
		        ncnb++;
		}
	}
        cout << "}" << endl;
}

void players :: ncnbf()
{
	cout << endl << total - ncnb << " students don't play anything!" << endl << endl;
}

int main()
{
	players P;

	P.accept();
	P.intrsec();
	P.ocricket();
	P.obadmint();
	P.unions();
	P.ncnbf();
}
