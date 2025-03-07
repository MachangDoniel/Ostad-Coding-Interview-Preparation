#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int info;
    node *link;
};

node *head=NULL,*temp;
void create(int data)
{
    node *ptr;
    ptr=new node();
    ptr->info=data;
    ptr->link=NULL;
    if(head==NULL) head=temp=ptr; // 1
    else temp->link=ptr,temp=ptr; 
}

void traverse()
{
    node *ptr;
    cout<<"The Linked List stands..."<<endl;
    for(ptr=head;ptr!=NULL;ptr=ptr->link) cout<<ptr->info<<" ";
    cout<<endl;
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int data; cin>>data;
        create(data);
    }
    traverse();
    return 0;
}