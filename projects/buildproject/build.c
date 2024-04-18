#include "./build.h"    
#define CFLAGS "-Wall" "-Wextra","-Wswitch-enum","-Wmissing-prototypes","Wconversion"

const char *toolchain[] = {
    "basm", "bme", "bmr", "debasm", "bdb", "basm2nasm"
};

int main(){

    printf("%s\n", PATH("foo", "bar", "baz",".test"));
    MKDIRS("build","bin");
    FOREACH_ARRAY(const char *, tool, toolchain, {
        printf("Building %s... \n", CONCAT(tool, ".c"));
        CMD(CFLAGS, "-o",
            PATH("build", "bin", tool),
            PATH("src", CONCAT(tool, ".c")));
    });
    //MKDIRS("build","examples");
#if 0 
    FOR_EACH_FILE_IN_DIR(example, "examples", {
        size_t n = strelen(example)
        assert (n>=4);
        if (strcmp(example + n - 4, "basm") == 0){
            cmd(PATH("build", "bin", "basm"), 
                "-g",
                example,
                PATH("build", CONCAT(example, ".bm")));
        }
    });
#endif 
    return 0;
}