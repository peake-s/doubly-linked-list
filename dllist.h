#include <stdbool.h>
#ifndef DLLIST_H
#define DLLIST_H
typedef struct header *dllist;
dllist createList(void);
// returns a newly created empty list; must be called before
// using list routines
void destroyList(dllist*);
// deallocates entire list; operation undefined if list hasn’t
// been created with createList
void clearList(dllist*);
// deallocates list items (if applicable) and sets list to empty
void *getItem(dllist,int);
// returns item at location if it exists, otherwise
// returns NULL
int addItem(dllist,void *ptr);
// adds item to end of list; returns index
// of new item or -1 if add was unsuccesful
int insertItem(dllist l,int i,void *ptr);
// inserts item into list at position; returns
// index of new item or -1 if unsuccessful; operation is successful
// when 0 <= i <= listSize(l) (0 is the first item in the list)
bool removeItem(dllist,int);
// removes item at position, returns true if operation
// successful, false otherwise
bool setItem(dllist,int,void *ptr);
// replaces item at location, returns true if operation
// is succesful, false otherwise
int listSize(dllist);
// returns current number of items in list
bool listEmpty(dllist);
// returns true if list is empty, false otherwise

#endif
