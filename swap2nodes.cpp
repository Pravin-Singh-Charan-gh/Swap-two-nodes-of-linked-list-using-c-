#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
};
void print(Node**head){
    Node*temp=*head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void append(Node**head,int data){
    Node*newn=new Node();
    newn->data=data;
    newn->next=NULL;
    
    if(*head==NULL){
        *head=newn;
        return;
    }
    
    Node*temp=*head;
    while(temp->next)
    temp=temp->next;
    
    temp->next=newn;
}

void swapnodes(Node** head, int x, int y){
 if(x==y)
 return;
 
  Node*currX=*head, *currY=*head,   *prevX=NULL, *prevY=NULL;
  while(currX && currX->data!=x){
   prevX=currX;
   currX=currX->next;
  }
  while(currY && currY->data!=y){
   prevY=currY;
   currY=currY->next;
  }
  if(currX==NULL || currY==NULL)
  return;
  
  if(prevX!=NULL)
   prevX->next=currY;
  else
   *head=currY;
   
  if(prevY!=NULL)
   prevY->next=currX;
  else
   *head=currX;
   
   Node*temp=currY->next;
   currY->next=currX->next;
   currX->next=temp;
}
    

int main(){
    Node*head=NULL;
    append(&head,1);append(&head,2);append(&head,9);append(&head,6);
    
    print(&head);
    swapnodes(&head,1,9);
    print(&head);
    
    return 0;
}
