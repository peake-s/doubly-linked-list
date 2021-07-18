#include <stdio.h>
#include <stdlib.h>
#include "dlistItem.h"
  listItem createListItem(int n) {
    int *p = malloc(sizeof(int));
    *p = n;
    return p;
  }

void freeListItem(listItem n) {
  free(n); 
  }

int getListItem(listItem p) {
  return *((int*)p);
}

int itemcmp(listItem n1,listItem n2) {
  int *p1 = n1, *p2 = n2;
  return (*p1<*p2?-1:(*p1>*p2?1:0));
}

char *toItemString(listItem x) {
  char *str = malloc(15); // somewhat arbitrary length
  sprintf(str,"%d",*((int*)x));
  return str;
}
