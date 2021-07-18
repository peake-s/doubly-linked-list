#ifndef DLISTITEM_H
#define DLISTITEM_H

typedef void *listItem;

listItem createListItem(int);
void freeListItem(listItem);

int itemcmp(listItem n1,listItem n2); // returns -1 if n1<n2, 0 if n1==n2, 1 if n1>n2
char *toItemString(listItem);

#endif
