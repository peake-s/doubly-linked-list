#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dllist.h"

int main(void){
  dllist list = createList();
  int *item = 8;
  int size = addItem(list,*((int*)item));
  printf("%d",size);
}


/*
int  main(void) {
dllist test = createList();
listItem n2 = createListItem(5);
listItem n4 = createListItem(3);
// lmString(getItem(test,i)));
//  if(removeItem(test,1))
//    printf("item at index 1(4): %s\n",toItemString(getItem(test,0)));
//  printf("list size %d\n",listSize(test));
//  for(int i=0;i<listSize(test);i++)
//  printf("item at index %d(4): %s\n",i,toItemString(getItem(test,i)));
  printf("add item/link index %d\n",addItem(test,n2));
  printf("list size %d\n",listSize(test));
  for(int i=0;i<listSize(test);i++)
  printf("item at index %d(4): %s\n",i,toItemString(getItem(test,i))); 
  printf("index added %d, added 5\n",insertItem(test,2,n4));
  printf("list size %d\n",listSize(test));
  //printf("inserted item at index 1: %s\n",toItemString(getItem(test,1)));
  //printf("list size %d\n",listSize(test));
  for(int i=0;i<listSize(test);i++)
    printf("item at index %d: %s\n",i,toItemString(getItem(test,i)));
  //clearList(&test);
  //destroyList(&test);
  printf("list size %d\n",listSize(test));
  //removeItem(test,3);
  printf("list size %d\n",listSize(test));
  //printf("index 3 should be 5\n");
  for(int i=0;i<listSize(test);i++)
    printf("item at index %d: %s\n",i,toItemString(getItem(test,i)));
  printf("gyes\n");
  printf("inserted data at index %d: 5\n",insertItem(test,6,n4));
  for(int i=0;i<listSize(test);i++)
    printf("item at index %d: %s\n",i,toItemString(getItem(test,i)));
    printf("Reverse\n");
  for(int i=listSize(test)-1;i>=0;i--)
    printf("item at index %d: %s\n",i,toItemString(getItem(test,i)));
  return 0;
}
*/