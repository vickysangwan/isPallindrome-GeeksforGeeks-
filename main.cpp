#include <iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* create(int size)
{
    struct node* head;
    head=NULL;
    for(int i=0;i<size;i++)
    {
        int data;
        cout<<"Enter data in linked  list"<<endl;
        cin>>data;
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            struct node* ptr;
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }
    return head;
}
void isPallindrome(struct node* head)
{
    stack<int> temp;
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        temp.push(ptr->data);
        ptr=ptr->next;
    }
    while(head!=NULL)
    {
        if(head->data==temp.top())
        {
            temp.pop();
        }
        head=head->next;
    }
    if(temp.empty())
    {
        cout<<"Pallindrome"<<endl;
    }
    else
    {
        cout<<"Not Pallindrome"<<endl;
    }
}
int main()
{
    struct node* head=NULL;
    int size;
    cout<<"Enter size of linked list"<<endl;
    cin>>size;
    head=create(size);
    isPallindrome(head);
    return 0;
}
