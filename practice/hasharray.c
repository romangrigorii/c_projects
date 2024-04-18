#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define hashsize 20

struct DataItem {
  int data;
  int key;
};

struct DataItem* hashArray[10];
struct DataItem* dummy;

int hashkey(int key){
  return key%hashsize;
}

void insert(int data, int key){
  // inserts a data with a key into hash table. if key already references another data, replaces it with a new one.
  struct DataItem* newitem = (struct DataItem*) malloc(sizeof(struct DataItem));
  newitem->data = data;
  newitem->key = key;
  int i = 0;
  while (hashArray[i] != NULL && i<hashsize){
    if (hashArray[i]->key == key){
      hashArray[i] = newitem;
      break;
    }
    i++;
    }
  if (i<hashsize){
    hashArray[i] = newitem;
  }
}

struct DataItem* get(int key){
  int i = 0;
  while (i<hashsize){
    i++;
    if (hashArray[i] != NULL && hashArray[i]->key == key){
      return hashArray[i];
    }
  }
  return NULL;
}

int* addsup(int* nums, int len, int target){
  int * ret = (int*) malloc(sizeof(int)*len);
  // int ret[2];
  insert(0,target - nums[0]);
  for (int i=1;i<len;i++){
    if (get(nums[i])){
      ret[0] = get(nums[i])->data;
      ret[1] = i;
      return ret;
    } else {
      insert(i,target - nums[i]);
    }
  }
  return ret;
}

int main() {

  insert(3,0);
  insert(3,2);
  insert(3,1);
  insert(4,1);

  char *k;
  k = (char*)malloc(sizeof(char)*100);
  k[0] = 10;
  //
  printf("Well Hello there!%d\n",k[0]);

  printf("%d\n", hashArray[0]->key);
  printf("%d\n", hashArray[1]->key);
  printf("%d\n", hashArray[2]->key);
  printf("%d\n", hashArray[2]->data);

  int nums[] = {2,7,11,15};
  int *ret = addsup(nums,4,13);
  printf("%d%d\n",ret[0],ret[1]);
  return 0;
}
