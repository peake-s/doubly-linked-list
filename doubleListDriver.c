#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dllist.h"

int main(void){
  dllist list = createList();
  int *item = 8;
  int size = addItem(list,item);
  printf("%d\n",getItem(list,0)); 
  return 0;
}
