/*
Name: Disha Shetty
Roll No: SECOB246
Batch: B3
SE Computer


ASSIGNMENT : 9
To create ADT that implement the "set" concept.
	a. Add (newElement) -Place a value into the set 
	b. Remove (element) Remove the value
	c. Contains (element) Return true if element is in collection
	d. Size () Return number of values in collection Iterator () Return an iterator used to loop
	   over collection
	e. Intersection of two sets 
	f. Union of two sets 
	g. Difference between two sets 
	h.Subset
*/

#include<iostream>
using namespace std;

typedef struct node{

	struct node *next;
	int data;

}node;

class set{

public:	node *hn;
		node *cn;

	set(){ hn=NULL; }

	void add();
	void display();
	void remove();
	void display_size();
	bool search(int);
	void uni(set,set);
	void intersect(set,set);
	void diff(set,set);

};

void set :: add(){

	int n;

	cout<<"\nEnter number of elements to add: ";
	cin>>n;

	while(n--){

		node *nn;
		nn = new node;
		nn->next = NULL;
		cout<<"Enter data: ";
		cin>>nn->data;

		if(!hn){

			hn = nn;

		}
		else{

			cn = hn;

			while(cn->next)
				cn = cn->next;

			cn->next = nn;
		}

	}
}

void set::display(){

	if(!hn)
		cout<<"\nNo elements to display\n";

	else{

		cout<<"\n{ ";

		cn = hn;

		while(cn){

			cout<<cn->data<<" ";
			cn = cn->next;
		}

		cout<<"}\n";
	}
}

void set::remove(){

	if(!hn)
		cout<<"\nNo elements in the set\n";
	else{

		int rmv;

		cout<<"\nEnter element to remove: ";
		cin>>rmv;

		if(hn->data == rmv){
			hn = hn->next;
			cout<<"\nElement removed from set\n";
		}
		else{

			cn = hn;
			node *pn;

			while(cn && cn->data != rmv){

				pn = cn;
				cn = cn->next;

			}


			if(cn->data == rmv){

				pn->next = cn->next;
				delete(cn);
				cout<<"\nElement removed from set\n";

			}
			else{

				cout<<"\nElement not found\n";
			}


		}
	}
}

void set::display_size(){

	cout<<"\nSize of set: ";
	int size=0;

	if(!hn)
		cout<<0<<endl;
	else{

		cn = hn;

		while(cn){

			++size;
			cn = cn->next;
		}

		cout<<size<<endl;
	}
}

bool set::search(int srh){

	if(!hn)
		return false;

	else{

		cn = hn;

		while(cn && cn->data != srh)
			cn = cn->next;

		if(cn && cn->data == srh)
            return true;
        return false;

	}
}

void set::intersect(set s1, set s2){

    if(s1.hn == NULL || s2.hn == NULL)
        cout<<"\n{  }\n";

    else{

        s1.cn = s1.hn;

        while(s1.cn){

        if(s2.search(s1.cn->data)){

            node *nn;
            nn = new node;
            nn->next = NULL;
            nn->data = s1.cn->data;

            if(hn == NULL)
                hn = nn;

            else{

                cn = hn;

                while(cn->next)
                    cn = cn->next;

                cn->next = nn;
            }

        }

        s1.cn = s1.cn->next;

        }
    }

}

void set::uni(set s1,set s2){

    if(s1.hn==NULL)
        s2.display();

    else if(s2.hn==NULL)
        s1.display();

    else{       /* copy set2 elements in the union list */

    s2.cn = s2.hn;

    while(s2.cn){

        node *nn;
        nn = new node;
        nn->next = NULL;
        nn->data = s2.cn->data;

        if(!hn)
            hn = nn;

        else{

            cn = hn;

            while(cn->next)
                cn = cn->next;

            cn->next = nn;
        }

        s2.cn = s2.cn->next;

    }
                /* copy elements that are unique in set1 */

       s1.cn = s1.hn;

        while(s1.cn){

        if(!s2.search(s1.cn->data)){

            node *nn;
            nn = new node;
            nn->next = NULL;
            nn->data = s1.cn->data;

            if(hn == NULL)
                hn = nn;

            else{

                cn = hn;

                while(cn->next)
                    cn = cn->next;

                cn->next = nn;
            }

        }

        s1.cn = s1.cn->next;

        }

    }

}

void set::diff(set s1,set s2){

    if(s1.hn==NULL && s2.hn==NULL)
        cout<<"\nNo elements to display\n";

    else if(s1.hn==NULL)
        s2.display();

    else if(s2.hn==NULL)
        s1.display();

    else{

        s1.cn = s1.hn; /* Copy unique elements if set1 */

        while(s1.cn){

        if(!s2.search(s1.cn->data)){

            node *nn;
            nn = new node;
            nn->next = NULL;
            nn->data = s1.cn->data;

            if(hn == NULL)
                hn = nn;

            else{

                cn = hn;

                while(cn->next)
                    cn = cn->next;

                cn->next = nn;
            }

        }

        s1.cn = s1.cn->next;

        }

        /* Copy unique elements of  set 2 */

         s2.cn = s2.hn;

        while(s2.cn){

        if(!s1.search(s2.cn->data)){

            node *nn;
            nn = new node;
            nn->next = NULL;
            nn->data = s2.cn->data;

            if(hn == NULL)
                hn = nn;

            else{

                cn = hn;

                while(cn->next)
                    cn = cn->next;

                cn->next = nn;
            }

        }

        s2.cn = s2.cn->next;

        }


    }

}

int main(){

	set s1,s2,in,un,ds;
	int choice,srh;
	do{

		cout<<"\n1. Add elements in set1";
		cout<<"\n2. Add elements in set2";
		cout<<"\n3. Remove element in set1";
		cout<<"\n4. Remove element in set2";
		cout<<"\n5. Search element in set1";
		cout<<"\n6. Search element in set2";
		cout<<"\n7. Display set1 elements ";
		cout<<"\n8. Display set2 elements";
		cout<<"\n9. Display size of set1";
		cout<<"\n10. Display size of set2";
		cout<<"\n11. Display intersection";
		cout<<"\n12. Display Union";
		cout<<"\n13. Display difference";
		cout<<"\n14. Subset";
		cout<<"\n15. Exit\n";
		cout<<"Choice: ";
		cin>>choice;

		switch(choice){

		case 1:	s1.add();
			break;

		case 2: s2.add();
			break;

		case 3: s1.remove();
			break;

		case 4: s2.remove();
			break;

		case 5:
                cout<<"\nEnter element to search: ";
                cin>>srh;

                if(s1.search(srh))
                    cout<<"\nElement present in the set\n";
                else
                    cout<<"\nElement not found\n";

			break;

		case 6:
                cout<<"\nEnter element to search: ";
                cin>>srh;

                if(s2.search(srh))
                    cout<<"\nElement present in the set\n";
                else
                    cout<<"\nElement not found\n";

			break;

		case 7: s1.display();
			break;

		case 8: s2.display();
			break;

		case 9: s1.display_size();
			break;

		case 10: s2.display_size();
			break;

		case 11: in.intersect(s1,s2);
                 in.display();
			break;

		case 12: un.uni(s1,s2);
                 un.display();
			break;

		case 13: ds.diff(s1,s2);
                 ds.display();
			break;

		case 14:  cout<<"\nFunction yet to be written\n";
			break;

		case 15: cout<<"\nExited\n";
			break;

		}

	}while(choice != 15);


}
