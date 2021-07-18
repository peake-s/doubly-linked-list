//Samuel Peake Project 4 EGRE 246
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dllist.h"
#include "dlistItem.h"

typedef struct dnode{
  struct dnode *next;
  struct dnode *prev;
  //listItem data;
  void *data;
}dnode;

struct header{
  struct dnode *front;
  struct dnode *tail;
  int size;
};

dllist createList(void){
  dllist newList=malloc(sizeof(struct header));
  newList->front=NULL;
  newList->tail=NULL;
  newList->size=0;
  return newList;
}

int addItem(dllist x,void *y){
  if(x==NULL||y==NULL)
    return -1;
  dnode *newLink=malloc(sizeof(struct dnode));
  newLink->data=y;
  if(!newLink)//ensuring malloc was succsful
    return -1;
  if(x->front==NULL||x->size==0){//if the list is empty
    x->front=newLink;//set the nodes prev to the head
    x->tail=newLink;//set the nodes tail also to the new node
    newLink->prev=NULL;
    newLink->next=NULL;
    x->size++;//increase the size of the list to 1
    return x->size-1;//return size minus 1 to indicate index
  }
  else{
    x->tail->next=newLink;//puts
    newLink->prev=x->tail;//setting the prev value of the new link to the former end value
    newLink->next=NULL;//setting the next to null to indicate end of list
    x->tail=newLink;//
    x->size++;
    return x->size-1;
  }
}

int insertItem(dllist l, int i, void *y){
  if(l==NULL||y==NULL)//if l does not exist
    return -1;
    //i>l->size-1||
  if(i<0||i>l->size)//if the index is negative or if the index is greater than the size
    return -1;
  dnode *newLink=malloc(sizeof(struct dnode));
  if(!newLink)//ensuring malloc was succsful
    return -1;
  newLink->data=y;
  dnode *temp=l->front;

  if(l->size==0){//if adding to empty list
    addItem(l,y);
    return i;
  }
  if(l->size==i)//if adding to end of list
    return addItem(l,y);

  if(i==0){//if adding to the beginning of the list
    newLink->next=temp;//connect the new node to list in the corrrect position by making its next the former front of the list
    newLink->prev=NULL;//making prev null as it is in the beginning of list
    temp->prev=newLink;//creating the doubly link between temp and newLink
    l->front=newLink;//making the newLink the new front of the list
    l->size++;
    return i;
  }

  int count=0;//count<i-1 count!=i
  while(count<i-1){//loop to run until one before the location is reached
    temp=temp->next;
    count++;
  }

  newLink->next=temp->next;//setting newLink to point to the link formerly after temp
  newLink->prev=temp;////setting the newLink to point to one before temp
  temp->next=newLink;//setting the temps next to newLink so the list can be accessed with new link
  /*
  newLink->next=temp;
  newLink->prev=temp->prev;
  temp->prev->next=newLink;
  temp->prev=newLink;
  */
  l->size++;
  return i;
}

void *getItem(dllist x, int i){
  if(x->front==NULL||i>x->size-1||i<0)//return NULL if the location does not exist
    return NULL;
  struct dnode *temp=x->front;
  int count=0;
  while(count!=i){//loop to loop until the location is reached
    temp=temp->next;//count =0 i=0
    count++;
  }
  return temp->data;
}

void destroyList(dllist* x){
  if(!x)
    return;
  dllist copy=*x;
  //dllist temp;
  struct dnode *temp=copy->front;
  dnode *adv;
  if(copy->front==NULL)
    return;
  while(temp!=NULL){
    //printf("yes\n");
    adv=temp->next;//store the next node in the temp list to keep pointer to list
    free(temp);//free the current node
    temp=adv;//reset the link from copy to temp
  }
  *x=NULL;
}

void clearList(dllist *x){
  if(!x)
    return;
  dllist copy=*x;
  struct dnode *temp=copy->front;
  //dnode *adv;

  while(temp!=NULL){
    copy->front=temp->next;//store the next node in the temp list to keep pointer to list
    free(temp);//removeItem(copy->front->next,i);
    temp=copy->front;//reset the link from copy to temp
  }
  copy->size=0;
  copy->front=NULL;
  copy->tail=NULL;
}

bool setItem(dllist x, int i, void *y){
  if(x->front==NULL||i>x->size)//if list is empty or the index dne
    return false;
  struct dnode *temp=x->front;
  int count=0;
  while(count!=i){//loop to loop until the location is reached
    temp=temp->next;
    count++;
  }
  temp->data=y;
  return true;
}

bool removeItem(dllist x, int i){
  if(x->front==NULL||i>=x->size)
    return false;
  struct dnode *temp=x->front;
  int count=0;
  if(i==0){//if deleting first nodes
    x->front=temp->next;//change the front pointer to the next node
    temp->prev=NULL;
    free(temp);
    x->size--;
    return true;
  }
  while(count!=i){//traverse to index
    temp=temp->next;
    count++;
  }

  if(temp->next==NULL){//if deleting the last node
    temp->prev=temp->next;
    temp->next=NULL;
    free(temp);
    x->size--;
    return true;
  }

  temp->prev->next=temp->next;
  free(temp);
  x->size--;
  return true;
}


bool listEmpty(dllist x){
  if(x->front==NULL)
    return true;
  return false;
}

int listSize(dllist x){
  return x->size;
}
