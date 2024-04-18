#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Map {
    int val;
    char* key;
} Map;

Map * linear_search(Map * map, size_t map_size, char * key){
    for (size_t i = 0; i< map_size; i++){
        if (strcmp(map[i].key, key) == 0){
            return &map[i];
        }
    }
    return NULL;
}

int main(){
    Map map[] = {{1,"a"}, {7, "b"}, {5, "c"}, {9, "d"}, {2, "e"}, {3, "f"}};
    size_t s = sizeof(map)/sizeof(map[0]);
    char * k = "c";
    Map * out = linear_search(map, s, "c");
    if (!out){
        return 0;
    }
    printf("c maps onto the value of %d\n", out->val);
    return 0;
}

