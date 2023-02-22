#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void deletationFromhead(Node* &head){
      Node* temp;
    temp = head;
    head = head->next;

    delete temp;
}

void search(Node* &head, int key)
{
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            cout<<key<<" found"<<endl;
            return;
        }
        temp = temp->next;
    }
    cout<<key<<" is not found in the list"<<endl;
}

void insertAtPos(Node* head, int pos, int number)
{
    Node* newnode = new Node;
    newnode->data = number;

    Node* temp = head;

    for(int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void insertAtHead(Node* &head, int number)
{
    Node* newnode = new Node;
    newnode->data = number;
    newnode->next = head;
    head = newnode;
}

void insertAtTail(Node* &head, int number)
{
   
    Node* newnode = new Node;
    newnode->data = number;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
       
        temp = temp->next;
    }
    temp->next = newnode;
}

void DisplayList(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<endl;

}

int main()
{
    Node *head = NULL;

    insertAtTail(head, 7);
    insertAtTail(head, 9);
    insertAtTail(head, 11);

    insertAtHead(head, 5);
    insertAtHead(head, 3);

    cout<<"Printing Our List: "<<endl;
    DisplayList(head);

   
    search(head, 11);
  
   deletationFromhead(head);


    cout<<"After deleting of new value"<<endl;
    DisplayList(head);
    return 0;
}