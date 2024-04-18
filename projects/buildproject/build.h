#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
int mkdir(const char *pathname, mode_t mode);

#define PATH_SEP "/"
#define PATH_SEP_LEN sizeof(PATH_SEP)-1

#define FOREACH_VARGS(param, arg, args, body)               \
    do {                                                    \
        va_start(args, param);                              \
        for (const char * arg = va_arg(args, const char*);  \
            arg != NULL;                                    \
            arg = va_arg(args, const char*))                \
        {                                                   \
            body;                                           \
        }                                                   \
        va_end(args);                                       \
    } while (0)                                             
    
// This is a wrapper for the PATH() function, which
// takes an arbitary naumber of strings and concatenates
// them to make a path. 

const char* concat_sep_impl(const char *sep, ...)
{
    const size_t sep_len = strlen(sep);
    size_t length = 0;
    ssize_t seps_count  = -1;
    va_list args;
    FOREACH_VARGS(sep, arg, args, {
        length+= strlen(arg);                           
        seps_count+=1;                                        
    });
    assert(length>0);

    char * result = malloc(length + seps_count*sep_len + 1); // allocate all of the space we need
    length = 0;

    FOREACH_VARGS(sep,arg,args,{
        size_t n = strlen(arg);
        memcpy(result+length, arg, n); 
        length += n;
        if (seps_count=-1 >= 0){
            memcpy(result + length, sep, sep_len);
            length += sep_len;
        }
    });
    result[length] = '\0';
    return result;
}

#define CONCAT_SEP(sep,...) concat_sep_impl(sep,__VA_ARGS__, NULL)

#define PATH(...) CONCAT_SEP(PATH_SEP, __VA_ARGS__)

void mkdirs_impl(int ignore, ...) {
    //int mkdir(const char *pathname, mode_t mode);
    size_t length = 0;
    ssize_t seps_count = -1;
    va_list args;
    FOREACH_VARGS(ignore, arg, args, {
        length+= strlen(arg);                           
        seps_count++;                                        
    });
    assert(length>0);
    char * result = malloc(length + seps_count*PATH_SEP_LEN + 1); // allocate all of the space we need 
    length = 0;
    FOREACH_VARGS(ignore, arg,args,{
        size_t n = strlen(arg);
        memcpy(result+length, arg, n);
        length += n;
        if (seps_count-- >= 0){
            memcpy(result + length, PATH_SEP, PATH_SEP_LEN);
            length += PATH_SEP_LEN;
        }
        result[length] = '\0';
        printf("[INFO] mkdir %s\n", result);
        if (mkdir(result, 0755) < 0){
            fprintf(stderr, "[ERROR] could not create directory %s: %s",
                result, strerror(errno));
            exit(1);
        }
    });

}

#define MKDIRS(...) mkdirs_impl(69,__VA_ARGS__, NULL)

#define FOREACH_ARRAY(type,item,items,body)             \
    do {                                                \
        for (size_t i = 0;                              \
            i < sizeof(items) / sizeof(items[0]);       \
            i++)                                        \
        {                                               \
            type item = items[i];                       \
            body;                                       \
        }                                               \
    } while(0);

const char * concat_impl(int ignore, ...)
{
    size_t length = 0;
    va_list args;
    FOREACH_VARGS(ignore, arg, args, {
        length += strlen(arg);
    });
    char * result = malloc(length + 1);
    length = 0;
    FOREACH_VARGS(ignore, arg, args, {
        size_t n = strlen(arg);
        memcpy(result + length, arg, n);
        length += n;
    });
    result[length] = '\0';
    return result;
}

#define CONCAT(...) concat_impl(69,__VA_ARGS__,NULL)

void cmd_impl(int ignore, ...)
{   
    size_t argc = 0;
    va_list args;
    size_t length = 0;
    size_t n;
    ssize_t seps_count  = -1;
    FOREACH_VARGS(ignore,arg,args,{
        argc++;
        length+= strlen(arg);     
        seps_count++;                  
    });

    const char **argv = malloc(sizeof(const char)*(argc + 1));

    char * result = malloc(length + seps_count*sizeof(" ") + 1); 

    FOREACH_VARGS(ignore, arg, args, {
        argv[argc++] = arg; // we place each of the args into an array. this is for linux implementaton
        n = strlen(arg);
        memcpy(result+length, arg, n);
        length += n;
        if (seps_count-- >= 0){
            memcpy(result + length, " ", 1);
            length += 1;
        }
    });
    printf("%s\n", result);
    assert(argc>0);  // to move on we assume that we have at least command 

    // pid_t cpid = fork();
    // if (cpid==-1){
    //     fprintf(stderr, "[ERROR] could not fork a child process: %s \n", strerror(errno));
    //     exit(1);
    // }
    // if (cpid==0){
    //     execvp(argv[0], argv);
    // } else {
    //     wait(NULL);  /* Wait for child */
    // }   
    // execvp(argv[0], argv);
}

#define CMD(...)                                                    \
    do {                                                            \
        printf("[INFO] ", CONCAT_SEP(" ", __VA_ARGS__));            \
        /*cmd_impl(69, __VA_ARGS__, NULL);*/                         \
    } while(0);     


