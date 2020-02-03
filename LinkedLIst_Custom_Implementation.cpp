#include<iostream>
using namespace std;
struct Node
{
	int number;
	Node* next;
};
class LinkedList
{
private:
	Node *start;

public:
	LinkedList()
	{
		start = NULL;
	}
	void InsertBeg(int X);//Insert a new node at the beginning
	void InsertEnd(int x); //Insert a node at the end
	void DeleteBeg(); //Delete a node from the beginning
	void DeleteEnd(); //Delete a node from the end
	void Delete(int D); //Delete a node with a given value
	void Print(); //Print current list 
	Node* Search(int F); //Search an existing element in the list
	int Sum(); //Add list values to get sum
};

void LinkedList::InsertBeg(int x)
{
	Node *temp = new Node;
	temp->number = x;
	temp->next = start;

	start = temp;
}

void LinkedList::InsertEnd(int x)
{
	Node *t = new Node;
	t->number = x;
	t->next = NULL;

	if (start == NULL)
	{
		start = t;
	}

	else
	{
		Node *temp = start;
		Node *prev = NULL;
		while (temp != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = t;
	}
}

void LinkedList::DeleteBeg()
{
	//chaek the underflow condition
	if (start == NULL)
	{
		cout << "UNDERFLOW" << endl;
		exit(1);
	}
	//set a temp variable to start
	Node *temp = start;
	start = start->next; //saying that the new start will be the next of the current start
	//free used space by temp
	free(temp);
}

void LinkedList::DeleteEnd()
{
	//if there are no nodes underflow
	if (start == NULL)
	{
		cout << "UNDERFLOW" << endl;
		exit(1);
	}

	//deleting if there is only 1 node
	else if (start->next == NULL)
	{
		Node* temp = start;
		delete temp;
		start = NULL;
	}
	//deleting if there are more than 1 node
	else
	{
		Node *temp = start;  //temp variable
		while (temp->next->next != NULL) //traverse thorugh the list
		{
			temp = temp->next; //updatinf the next variables address
		}
		delete(temp->next); //deleting the temp node
		temp->next = NULL; 
		
	}	
}

void LinkedList::Delete(int D)
{
	//check for underflow
	if (start == NULL)
	{
		cout << "UNDERFLOW" << endl;
		exit(1);
	}
	
	Node *temp = start; //temp variabels to hold the current address and the last node's address
	Node *prev = NULL;
	while (temp->number != D) //traverse the list
	{
		prev = temp; //pointing to the next nodes
		temp = temp->next;
	}
	prev->next = temp->next; //setting the last node up
	free(temp); //free the space taken by the temp node
}

void LinkedList::Print()
{
	//underflow condition
	if (start == NULL)
	{
		cout << "UNDERFLOW" << endl;
		exit(1);
	}

	Node *temp = start; //temp variable
	while (temp != NULL)
	{
		cout << temp->number << ",\t"; //print the current value
		temp = temp->next;
	}
}

Node* LinkedList::Search(int F)
{
	//check underflow condition
	if (start == NULL)
	{
		cout << "UNDERFLOW" << endl;
		exit(1);
	}

	Node *temp = start; //temperory node for the start
	while (temp->number != F) //traversing through the list until we find the node with the desired number
	{
		temp = temp->next; //pointing to the next pointer
	}
	return temp; //return the address of the number
}

int LinkedList::Sum()
{
	//checking the onderflow condition
	if (start == NULL)
	{
		cout << "UNDERFLOW" << endl;
		exit(1);
	}

	int sum = 0; //initialixe the sum
	Node* temp = start; //temperory node

	while (temp!=NULL)  //traversing therough the list
	{
		sum += temp->number; //incriment the sum
		temp = temp->next; //point to the next variable
	}
	return sum;  //return the sum
}

//main function, program starts here
int main()
{
	int noOfNodes;
	cout << "No of Nodes : ";
	cin >> noOfNodes;

	LinkedList l;
	//getting the data for the linked list
	int input;
	for (int i = 0; i < noOfNodes; i++)
	{
		cout << "Input Data for Node " << i + 1 << " : ";
		cin >> input;
		l.InsertEnd(input);
	}
	l.Print();
	cout << endl << endl;
	//jumppoint for iteratin of the program to perform multiple tasks
jumppoint:
	//getting the desired input from user
	cout << "1 - Insert Beginning\n2 - Insert End\n3 - Delete Beginning\n4 - Delete End\n5 - Delete Value\n6 - Print\n7 - Search\n8 - Sum\n9 - Exit\n\nEnter Your Choice : ";
	cin >> input;
	//swirch case for performing the specified tasks
	switch (input)
	{
	case 1:
	{
		cout << "Input : ";
		cin >> input;
		l.InsertBeg(input);
		l.Print();
		cout << endl;
		break;
	}
	case 2:
	{
		cout << "Input : ";
		cin >> input;
		l.InsertEnd(input);
		l.Print();
		cout << endl;
		break;
	}
	case 3:
	{
		l.DeleteBeg();
		l.Print();
		cout << endl;
		break;
	}
	case 4:
	{
		l.DeleteEnd();
		l.Print();
		cout << endl;
		break;
	}
	case 5:
	{
		cout << "Number to Delete : ";
		cin >> input;
		l.Delete(input);
		l.Print();
		cout << endl;
		break;
	}
	case 6:
	{
		l.Print();
		cout << endl;
		break;
	}
	case 7:
	{
		cout << "Number to Search : ";
		cin >> input;
		cout << "Address : " << l.Search(input) << endl;
		break;
	}
	case 8:
	{
		cout << "Sum of the list = " << l.Sum() << endl;
		break;
	}
	case 9:
	{
		return 0; 
	}
	default:
		break;
	}
	goto jumppoint;
	system("pause");

}