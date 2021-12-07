#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node
{
int data;
struct node*link;
} node;
node *head, *tail;
node *xor (node *a,node *b)
{
  return (node *)((uintptr_t)a^(uintptr_t)b);
}

void insert(node **head_ref, int data)
{
node *newnode=(node *)malloc(sizeof(node));
newnode->data=data;
if(head==NULL){
 newnode->link=NULL;
 head = tail = newnode;
}
else
{
newnode->link = xor(tail,NULL);
tail->link = xor(xor(tail->link,NULL),newnode);
tail = newnode;
}
}

void traverse()
{
 node *curr=head;
 node *prev=NULL,*next;
 while(curr!=NULL)
 {
 printf("%d ",curr->data);
 next=xor(prev,curr->link);
 prev=curr;
 curr=next;
 }
 printf("\n");
}

int delete(bool from_tail)
{
int data;
node *ptr;
if(from_tail)
{
ptr=tail;
data=ptr->data;
node *prev=xor(ptr->link,NULL);
if(prev==NULL)
{
head=NULL;
}
else{
 prev->link=xor(ptr,xor(prev->link,NULL));
}
tail=prev;
}
free(ptr);
ptr=NULL;
return data;
}

int main()
{
int data;
int n;
printf("Enter the size of the list: ");
scanf("%d",&n);
int arr[n];
printf("Insertion\n");
printf("Enter the values to be inserted\n");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
insert(&head, arr[i]);
}
printf("List: ");
traverse();
printf("\n");
int x;
printf("Deletion\n");
printf("Enter the number of values to be deleted from the end\n");
scanf("%d",&x);
for (int i=0;i<x;i++)
{
data=delete(i < x);
printf("Deleted %d\n",data);
}
printf("List: ");
traverse();
return 0;
}
