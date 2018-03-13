#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

struct node
{
    float value;
    node* next=NULL;
};
void showElement(node* cNode)
{
    if (!cNode)
    {
        cout<<"Element doesnt exist"<<endl;
        return;
    }
    cout<<cNode->value<<'\t'<<cNode<<'\t'<<cNode->next<<endl;
}
void show (node* cNode)
{
    node*temp=cNode;
    cout<<"elements in the list:"<<endl;
    if (!temp)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    do
    {
        cout<<temp->value<<'\t';
        temp=temp->next;
    } while (temp!=cNode);
    cout<<endl;
}
void add(node*& cNode, float value)
{
    node* newNode= new node;
    newNode->value=value;
    if (cNode)//list non-empty
    {
        newNode->next=cNode->next;
        cNode->next=newNode;
    }
    else
    {
        cNode=newNode;
        cNode->next=cNode;
    }
}
float max(node* cNode)
{
    float max;
    if (cNode==0)
    {
        cout<<"list is empty"<<endl;
        return nan("");
    }
    max=cNode->value;
    node* temp=cNode->next;
    while (temp!=cNode)
    {
        if (max<temp->value) max=temp->value;
        temp=temp->next;
    }
    return max;
}
void deleteAfter(node*& cNode, float value)
{
    if (cNode==0) return;
    node* temp=cNode;
    do
    {
        if (temp->value==value)
        {
            if (temp->next==temp)//list has only one element
            {
                delete temp;
                cNode=NULL;
                return;
            }
            if (temp->next==cNode)//last element in the list
            {
                cNode=temp;
            }
            node* aboutToDie=temp->next;
            temp->next=temp->next->next;
            delete aboutToDie;
            break;
        }
        temp=temp->next;
    } while (temp!=cNode);
}
int main()
{
    node* cycList=NULL;
    srand(time(NULL));
    for (int i=100; i<110; i++)
    {
        int x=rand()%i;
        add(cycList,x);
    }
    show(cycList);
    while (cycList)
    {
        deleteAfter(cycList,max(cycList));
        show(cycList);
    }
}