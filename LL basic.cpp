#include <iostream>
using namespace std;

class Node{

public:
     int data;
     Node *next;
     Node *head;

     Node(int data){
         this->data = data;
         next = NULL;
     }


};

void print(Node *head)
{
   /* Node * temp = head;
    while(temp != NULL){
    cout<<temp->data<<" -> ";
    temp = temp->next;
   }
   cout<<"NULL"<<endl; */

    while(head != NULL){
    cout<<head->data<<" -> ";
    head = head->next;
   }
   cout<<"NULL"<<endl;
}

void increment(Node *head)
{
    Node * temp = head;
    while(temp!= NULL){
        temp->data++;
        temp = temp->next;
    }
}

Node * takeInput()
{
    int data;
    cin>>data;

    Node * head = NULL; //Empty LL
    Node * temp;
    Node * tail = NULL; //Empty LL

    while(data != -1){
        Node * n = new Node(data);

        if(head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next; //or we can do " tail = n "
        }

        cin>>data;

    }
    return head;
}


Node * takeInput2()
{
    int data;
    cin>>data;

    ///Creating Linked List and taking input
    Node *head = NULL;
    Node *tail = NULL;

    while(data != -1)
    {
        Node * n = new Node(data);
        if(head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }

        cin>>data;
    }
    return head;
}

///Print Length
int length(Node * head)
{
    Node * temp = head;
    int counter = 0;
    while(temp != NULL)
    {
        counter ++;
        temp = temp->next;
    }
    return counter;
}

///Print ith Node
//Time Complexity O(n+i)
void ithNode(Node * head , int index)
{
    Node * temp = head;
    int len = length(temp);
    if(index > len-1 || index < 0) cout<<"This index does not exist in the Linked List"<<endl;
    for(int i=0; temp != NULL; i++)
    {
        if(i == index)
        {
            cout<<temp->data;
            break;
        }
        temp = temp->next;
    }
}

//Time Complexity O(i)
ithNode2(Node * head , int index)
{
    int i;
    for(i = 0; head != NULL; i++)
    {
        if(i == index)
        {
            cout<<head->data;
            break;
        }
        head = head->next;
    }
    if(i < 0 || index > i) cout<<"-1"<<endl;
}

///Insert Node at nth position
Node * insertNode(Node *head, int index, int data)
{
    Node * newNode = new Node(data);
    Node * temp = head;
    int i=0;
    if(index < 0 || index > length(head))
    {
        cout<<"Invalid Index"<<endl;
        return head;
    }
    if(index == 0)
    {
        newNode->next = temp;
        return newNode;
    }

    for(i = 1; temp != NULL; i++)
    {
        if(i == index-1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        if(i == length(head))
        {
            temp->next = newNode;
            newNode->next = NULL;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//Alternate way, with less time complexity
Node * insertNode2(Node * head, int index , int data)
{
    Node * temp = head;
    if(index<0) return head;
    if(index==0){
        Node * newNode = new Node(data);
        newNode->next = temp;
        return newNode;
    }

    int count = 1;
    while(count <= index-1 && temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    if(temp){
        Node * newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
    return head;
}

///Delete Node at ith Position
Node * deleteNode(Node * head , int index)
{
    Node * temp = head;
    if(index<0) return head;
    if(index==0 && head){
        Node * tempHead = head;
        return head->next;
        delete tempHead;
    }

    int count = 1;
    while(count <= index-1 && temp !=NULL)
    {
        temp = temp->next;
        count++;
    }
    if(temp && temp->next)
    {
        Node * del = temp->next;
        temp->next = temp->next->next;
        del->next ==NULL:
        delete del;
        return head;
    }
    return head;
}

int main(){
   /* //Creating Nodes
   Node *n1 = new Node(2);
   Node *n2 = new Node(3);
   Node *n3 = new Node(1);
   Node *n4 = new Node(6);
   Node *n5 = new Node(4);

   //HEAD and TAIL Pointers
   Node *head = n1;
   Node *tail = NULL;

   //Creating Connections
   n1->next = n2;
   n2->next = n3;
   n3->next = n4;
   n4->next = n5; */

   //
   Node * head = takeInput();
   print(head);
   cout<<"Length of Linked List: "<<length(head)<<endl;
   ithNode2(head, 2);
   cout<<endl;
   /*head= insertNode2(head,5,5);
   print(head);
   cout<<"Length of Linked List: "<<length(head)<<endl;*/

   head = deleteNode(head, 4);
   print(head);
   cout<<"Length of Linked List: "<<length(head)<<endl;

   return 0;
}
