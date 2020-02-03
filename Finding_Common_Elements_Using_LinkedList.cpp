#include<iostream>
using namespace std;
//linked list (NODE)
struct Node
{
	int number; //to hold data
	Node* next; //to hold next address
};
//class for linked list
class LinkedList
{
public:
	Node *start;   //start should be made public for access outside the class
	LinkedList() //constructor
	{
		start = NULL;
	}
	void InsertEnd(int x); //Insert a node at the end
	void Print(); //Print current list 
	LinkedList Compare(const LinkedList A, const LinkedList B) const; //comparing two linked list for similar values
};


void LinkedList::InsertEnd(int x)
{
	//creating a brand new node for inserting new daya
	Node *t = new Node;
	t->number = x;
	t->next = NULL;   //setting the next address as NULL, because it will be the last node

	//traversing through the list to find the last element
	Node *temp = start;
	Node *prev = NULL;
	//while loop for going through every node
	//will stop at the last node
	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	//if there are no elements in the list
	//the first node is created
	if (start == NULL)
	{
		start = t;
	}
	//if there are nodes, the next node is added to the end
	else
	{
		prev->next = t;
	}
}

void LinkedList::Print()
{
	//traversing the list
	Node *temp = start;
	while (temp != NULL)
	{
		//printing to the console
		cout << temp->number << ",\t";
		temp = temp->next;
	}
}

bool CheckForDuplicates(Node* N)
{
	struct Node *temp1, *temp2, *temp;
	temp1 = N;

	// Pick elements one by one
	while (temp1 != NULL && temp1->next != NULL)
	{
		temp2 = temp1;

		//Compare the picked element with rest of the elements
		while (temp2->next != NULL)
		{
			// If duplicate then delete it
			if (temp1->number == temp2->next->number)
			{
				// return true of a similar elemtent is found
				return true;
			}
			else 
				temp2 = temp2->next; //the next element is linked
		}
		temp1 = temp1->next; //the next element is linked
	}
	return false; //returns false if there are no duplicate elements
}

LinkedList LinkedList::Compare(const LinkedList A, const LinkedList B) const //constant function
{
	//assigning the start values of the list to temprory variables
	Node* tempA = A.start;
	Node* tempB = B.start;
	Node*temp;
	//check for duplicates in list A
	if (CheckForDuplicates(tempA))
	{
		cout << "Error" << endl;
		system("pause");
		exit(1);
	}
	//check for duplicates in list B
	else if (CheckForDuplicates(tempB))
	{
		cout << "Error" << endl;
		system("pause");
		exit(1);
	}
	//reassigning the variables as they are changed in the checking process
	//i. e. because they are passed as pointers and functions change the pointers
	tempA = A.start;
	tempB = B.start;
	temp = tempB;
	LinkedList l;
	//outer loop to change the value of list B
	while (tempA != NULL)
	{
		//inner loop to change the value of list A
		while (temp != NULL)
		{
			//check for similarity
			if (tempA->number == temp->number)
			{
				l.InsertEnd(tempA->number);
			}
			//update the next adddress
			//and looped
			temp = temp->next;
		}
		//the address of A is updated to next;
		tempA = tempA->next;
		//address of B is reset;
		temp = tempB;
	}
	return l;
}

//main function
//program begins here
int main()
{
	//two lengths
	int length1,length2;
	//two lists
	LinkedList l1, l2;
	//getting user inputs
	cout << "No of Nodes : ";
	cin >> length1;

	int input;
	//getting the user to input to the lists
	for (int i = 0; i < length1; i++)
	{
		cout << "Input Data for Node " << i + 1 << " : ";
		cin >> input;
		l1.InsertEnd(input);
	}
	//print the list
	l1.Print();
	cout << endl << endl;
	//same procedure to get and print the list B
	cout << "No of Nodes : ";
	cin >> length2;

	for (int i = 0; i < length2; i++)
	{
		cout << "Input Data for Node " << i + 1 << " : ";
		cin >> input;
		l2.InsertEnd(input);
	}
	l2.Print();
	cout << endl << endl;

	//calling compare function
	LinkedList result = l1.Compare(l1, l2);
	system("cls");
	cout << "List 1 Values : ";
	l1.Print();
	cout << "List 2 Values : ";
	l2.Print();
	cout << "Common Values : ";
	//print the list
	result.Print();

	//end of the program
	system("pause");
	return 0;
}