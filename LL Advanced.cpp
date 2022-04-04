#include<iostream>
using namespace std;
#include<cmath>

///Declaration of Class Node
class Node
{
public:
    int data;
    Node * next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};

///Function to take Input
Node * takeInput()
{
    cout<<"Enter the elements in the linked list"<<endl;
    int data;
    Node * head = NULL;
    Node * tail = NULL;
    cin>>data;

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
            tail->next = n;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

///Take input and store head at last element
Node * takeInput2()
{
    int data;
    Node * head = NULL;
    Node * tail = NULL;
    cin>>data;

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

///Insert a new Node
Node * insertNode(Node * head , int index, int data)
{
    if(index == 0)
    {
        Node * newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node * newNode = new Node(data);
    Node * temp = head;

    int count = 1;
    while(count <= index-1)
    {
        temp = temp->next;
        count++;
    }

    if(temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
    return head;
}

///Print All Nodes
void print(Node * head)
{
    Node * temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

///Length using recursion
int lengthRecursive(Node * head)
{
    if(head == NULL) return 0;

    head = head->next;
    return 1 + lengthRecursive(head);
}

///Search in Linked List
int searchNode(Node * head, int element)
{
    int i = 0;
    while(head != NULL)
    {
        if(head->data == element) return i;
        head = head->next;
        i++;
    }
    return -1;
}
//Using Recursion
int searchRecursive(Node * head, int element)
{
    if(!head) return 0;
    head = head->next;
    return 1 + searchRecursive(head, element);
}

///Mid point of Linked List
//Traversing 2 times method
Node * midNode(Node * head)
{
    Node * midNode = head;
    Node * temp = head;
    int length = 0;
    while(temp)
    {
        length++;
        temp = temp->next;
    }
    for(int i = 0; i < length/2; i++)
    {
        midNode = midNode->next;
    }
    return midNode;
}

//Traversing one time || slow and fast pointer approach
Node * midNode2(Node * head)
{
    Node * slow = head;
    Node * fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

///Reverse a Linked List
Node * reverseLL(Node * head)
{
    Node * curr = head;
    Node * prev = NULL;
    while(curr)
    {
        Node * n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
}

///Delete nth Node from end
/*.......*/

///Merge two sorted Linked Lists
Node * mergeLL(Node * head1 , Node * head2)
{
    if(!head1) return head2;
    if(!head2) return head1;

    Node * finalHead = NULL;

    if(head1->data <= head2->data){
        finalHead = head1;
        head1 = head1->next;
    } else{
        finalHead = head2;
        head2 = head2->next;
    }

    Node * finalTail = finalHead;

    while(head1 && head2)
    {
        if(head1->data < head2->data){
            finalTail->next = head1;
            head1 = head1->next;
        } else{
            finalTail->next = head2;
            head2 = head2->next;
        }
        finalTail = finalTail->next;
    }

    if(head1){
        finalTail->next = head1;
    } else if(head2){
        finalTail->next = head2;
    }
    return finalHead;
}

//Merging two sorted Linked List using Recursion
Node * mergeLL2(Node * head1, Node * head2)
{
    if(!head1) return head2;
    if(!head2) return head1;

    Node * newHead = NULL;
    if(head1->data < head2->data){
        newHead = head1;
        newHead->next = mergeLL2(head1->next, head2);
    }
    else{
        newHead = head2;
        newHead->next = mergeLL2(head1, head2->next);
    }

    return newHead;

}

int main()
{
    Node * head1 = takeInput();
    print(head1);
    cout<<endl;
    Node * head2 = takeInput();
    print(head2);
    cout<<endl;
    /*cout<<lengthRecursive(head);
    cout<<endl;
    head = insertNode(head, 0, 5);
    print(head);
    cout<<lengthRecursive(head);
    cout<<searchNode(head, 5)<<endl;
    cout<<searchRecursive(head ,5)<<endl;
    Node * mid = midNode2(head);
    cout<<"Middle Node: "<<mid->data;
    Node * reverseHead = reverseLL(head);
    print(reverseHead);*/
    cout<<"Merged Linked List"<<endl;
    Node * merged = mergeLL2(head1, head2);
    print(merged);
    return 0;
}
