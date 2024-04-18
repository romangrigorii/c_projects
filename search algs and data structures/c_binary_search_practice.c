#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct entry {
    int value;
    char * key;    
} entry;

int cmp(const void * e1, const void * e2){
    entry * e1_ = (entry *) e1;
    entry * e2_ = (entry *) e2;
    return strcmp(e1_->key, e2_->key);
}

entry * binary_search(entry * ent, char * key, size_t length){
    int left = 0;
    int right = length - 1;
    int comp;
    while (left <= right){
        int mid = (right + left)/2;
        comp = strcmp(ent[mid].key, key);
        if (comp == 0){
            return &ent[mid];
        }
        if (comp<0){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return NULL;
}

int main(void){ 
    entry map[] = {{1,"a"}, {7, "b"}, {5, "c"}, {9, "d"}, {2, "e"}, {3, "f"}};
    size_t L = sizeof(map)/sizeof(map[0]);
    entry * out;
    out = binary_search(map, "c", L);
    if (out){
        printf("binary search found %s with value of %d\n", out->key, out->value);
    }
    entry key = {0, "c"};
    out = bsearch(&key, map, L, sizeof(entry), cmp);
    if (out){
        printf("binary search found %s with value of %d\n", out->key, out->value);
    }
    return 0;
}

    