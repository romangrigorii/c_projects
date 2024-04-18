#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**************************************************************************
/* The following will grab a speicified number of characters from a file 
and output them to another file. These files can be stdin and stdout or 
some files saved in a directory.
We ultimately compare two files and print the first line of characters where they differ.
*/
/***************************************************************************

// int strcmpR(char *s1, char *s2){
//   while (*s1 != '\0' && *s2 != '\0' && *s1++ == *s2++)
//     ;
//   return *s1 - *s2;
// }

// char *fgetsR(char *s, int n, FILE *iop){
//   register int c;
//   register char *cs;

//   cs = s; // set the adress of cs to be the same as s

//   while (--n > 0 && (c = getc(iop)) != EOF){ // --n instead of n-- because we want to leave room for '\0'
//     if ((*cs++ = c) == '\n') // sets the cs points to a new c and check if its equal to newline
//       break;
//   }
//   *cs = '\0';
//   return (c == EOF && cs == s) ? NULL : s; // if the new character is EOF, in other words we did not read n charcaters, or if no charatcers were read, return NULL
//   // otherwise we return the pointer to first entry in cs which is coincidentally the pointer to first element in s
// }
// int fputsR(char *s, FILE *iop){
//   char c;
//   while (c=*s++)
//     putc(c,iop);
//   return ferror(iop) ? EOF : 0;
// }
// int comparefiles(FILE *f1, FILE *f2, int max){
//   char *str1 = (char*) malloc(max*sizeof(char));
//   char *str2 = (char*) malloc(max*sizeof(char));
//   int flag = 0;
//   while (fgetsR(str1, max, f1)!=NULL && fgetsR(str2, max, f2)!=NULL && strcmpR(str1,str2)==0)
//     flag = 1;
//   if (flag){
//     fputsR(str1, stdout);
//     fputsR(str2, stdout);  
//   }
//   return flag;
// }

// // int main(){
// //   char *al = (char *) malloc(10*sizeof(char));
// //   fgetsR(al, 10,stdin);
// //   fputsR(al, stdout);
// //   return 0;
// // }

// int main(){
//   char *al = (char *) malloc(20*sizeof(char));
//   FILE *f1 = fopen("example1.txt", "r");
//   FILE *f2 = fopen("example1.txt", "r");
//   comparefiles(f1,f2,20);
//   return 0;
// }

//// ***************************************************************************
/* the following function will find the longest line in a stream given line and print it */
/*                       more on this on page 29 of TCPL                      */
//// ***************************************************************************
// #define MAX_LEN 100 // defines maximum length of the line
// int getlineR(char s[], int lim);
// void copy(char to[], char from[]);
// int main(){
//   int len = 0, max = 0;
//   char line[MAX_LEN], longest[MAX_LEN];
//   while ((len = getlineR(line, MAX_LEN))>0){
//     if (len>max){
//       max = len;
//       copy(longest,line);
//     }
//   }
//   printf("%s", longest);
//   return 0;
// }
// int getlineR(char s[], int lim){
//   // the program will save a line into string s and return its length
//   int c, i;
//   for (i = 0; i<lim && (c = getchar()) != EOF && c!='\n'; i++){
//     s[i] = c;
//   }
//   if (c=='\n'){
//     s[i] = c;
//   }
//   s[i+1] = '\0';
//   return i;
// }
//
// void copy(char *to, char *from){
//   for(int i=0;(to[i]=from[i]) != '\0';i++)
//     ;
// }
//// ***************************************************************************
/*              defining some escape sequence characters                      */
//// ***************************************************************************
// #define VTAB '\xF4'
// #define BELL '\x7'
//
// int main (){
//   printf("%d\n", VTAB);
//   printf("%c\n", BELL);
//   printf("%s\n", "this is"
//   " concat test.");
//   enum WEATHER {RAINING = false, WINDY=true, TEMPERATURE = 65} weather;
//   // weather = TEMPERATURE;
//   printf("%d\n", TEMPERATURE);
//   return 0;
// }
//// ***************************************************************************
/*          writing a function to convert from hex string to int value        */
/*            ex. 2-3                                                         */
//// ***************************************************************************
// long int htoi(char *);
// int main(){
//   printf("%d\n", htoi("0xf1fAB"));
//   return 0;
// }
// long int htoi(char s[]){
//   long int val = 0;
//   int cur;
//
//   for(int i = ((s[0]!='\0')*(s[1]!='\0')*((s[0]=='0')*((s[0]!='x')||(s[0]!='X')))*2); s[i]!='\0';i++){
//     cur = 0;
//     if ((s[i]>='0')*(s[i]<='9')){
//       cur = s[i] - '0';
//     }
//     else if ((s[i]>='a')*(s[i]<='f')){
//       cur = s[i] - 'a' + 10;
//     }
//     else if ((s[i]>='A')*(s[i]<='F')){
//       cur = s[i] - 'A' + 10;
//     }
//     val = (val*16 + cur);
//   }
//   return val;
// }
//// ***************************************************************************
/*                        strcat implementation                               */
//// ***************************************************************************
// void strcatR(char *, char *);
// int main(){
//   char first[] = "Hello";
//   char second[] = "World!";
//   strcatR(first,second);
//   printf("%s\n", first);
//   return 0;
// }
//
// void strcatR(char to[], char from[]){
//   int i = -1;
//   int j = 0;
//   while (to[++i]!='\0')
//     ;
//   while ((to[i++]=from[j++])!='\0')
//     ;
//   printf("%s\n",to);
// }
//// ***************************************************************************
/*                            count the number of 1 bits                      */
//// ***************************************************************************
// int bitcount(int);
// int main(int argc, char *argv[]){
//   printf("%d\n", bitcount(atoi(argv[1])));
//   return 0;
// }
// int bitcount(int val){
//   int bts;
//   for (bts = 0; (val&=(val-1))>0; bts++)
//     ;
//   return (bts += bts>0);
// }
//// ***************************************************************************
/* using goto statement to check if any elements in one array match in the other */
//// ***************************************************************************
// void findmatch(char a[], char b[]);
// int main(){
//   findmatch("Hello","Swing");
//   return 0;
// }
// void findmatch(char a[], char b[]){
//   int i, j;
//   for(i=0;a[i]!='\0';i++){
//     for(j=0;b[j]!='\0';j++){
//       if (a[i] == b[j]){
//         goto foundmatch;
//       }
//     }
//   }
//   printf("no matching elements found\n");
//   foundmatch:
//       {
//         printf("matching elements is %c\n", a[i]);
//       }
// }
/*     quicksort algorithm   */
//// ***************************************************************************
// void quicksort(int v[], int l, int r);
// void swap(int*, int, int);
// int main(){
//   int tosort[] = {1,0,6,3,6,2,4,9,7,3,6};
//   printf("array needing sorting:");
//   printarr(tosort,11);
//   quicksort(tosort, 0, 10);
//   printf("sorted array:");
//   printarr(tosort,11);
//   return 0;
// }
// void swap(int* v, int p1, int p2){
//   int temp;
//   temp = v[p1];
//   v[p1] = v[p2];
//   v[p2] = temp;
// }
// void quicksort(int v[], int l, int r){
//   int ind = l; // represents the current locations
//   int cent = l; // represents the partition location
//   if (l>=r){
//     return;
//   }
//   while(++ind<=r){
//     if (v[ind]<v[cent]){
//       swap(v,cent,ind);
//       if (++cent != ind)
//         swap(v,cent,ind);
//     }
//   }
//   quicksort(v, l,cent);
//   quicksort(v,cent+1,r);
// }
//// ***************************************************************************
/*                              reverse recusrive                             */
//// ***************************************************************************
// void reverserec(int*,int,int);
// int main(){
//   int arr[] = {1,2,3,4,5,6,7,8,9};
//   printarr(arr,9);
//   reverserec(arr,0,8);
//   printarr(arr,9);
//   return 0;
// }
// void reverserec(int arr[], int s, int e){
//   if (e<=s)
//     return;
//   int temp;
//   temp = arr[s];
//   arr[s++] = arr[e];
//   arr[e--] = temp;
//   reverserec(arr,s,e);
// }
//// ***************************************************************************
/*                      impelmenting strlen using pointers                    */
//// ***************************************************************************
// int strlenR(char *);
// int main(){
//   char word[] = "Hello World!";
//   printf("The length of string is %d", strlenR(word));
//   return 0;
// }
//
// int strlenR(char *word){
//   char *p = word;
//   for(;*p != '\0';p++)
//     ;
//   return p - word;
// }
//// ***************************************************************************
/*                      implementing strlen using pointers                    */
//// ***************************************************************************
// int getlineR(char*, int);
// int main(){
//   char p[10];
//   getlineR(p, 10);
//   printf("%s\n",p);
//   //printarrC(p,10);
//   return 0;
// }
//
// int getlineR(char *line, int lim){
//   int i;
//   for(i = 0;((*line = getchar())!='\0') && (*line != '\n') && (i<=lim); i++, line++)
//     ;
//   *line = '\0';
//   return 0;
// }
//// ***************************************************************************
/*                              using array of pointers                       */
//// ***************************************************************************
// int main(){
//   char *months[] = {"January", "February","March","April","May","June","July","August","September","Octuber","November","December"};
//   printf("%s\n",months[1]);
//   return 0;
// }
//// ***************************************************************************
/*                        echo command line arguments                         */
//// ***************************************************************************
// int main(int argc, char *argv[]){
//   int i;
//   printf("program name is %s\n", *argv);
//
//   for (i=1;i<argc;i++)
//     printf("and program input is %s%s", argv[i], (i<(argc-1)) ? " " : "");
//   return 0;
// }
//// ***************************************************************************
/*                        reverse Polish expression     (not finished) */
//// ***************************************************************************
// int main(int argc, char* argv[]){
//   char *s = argv[1], *e = argv[1];
//   for(;*(++e)!='\0';)
//     ;
//   --e;
//   printf("%c%c\t%d\n", *s, *e, e-s+1);
//
//   while (e>s){
//     while ((*e == '*')+(*e == '/')+(*e == '+')+(*e == '-'))
//       e--;
//     switch(*(e+1)){
//       case '*':
//         *(e-1) *= *e;
//         break;
//       case '+':
//         *(e-1) += *e;
//         break;
//       case '/':
//         *(e-1) /= *e;
//         break;
//       case '-':
//         *(e-1) -= *e;
//         break;
//     }
//     e = e + 2;
//   }
//   printf("result of %s is %d",argv[1], *e);
// }
//// ***************************************************************************
/*                                structure play                              */
//// ***************************************************************************

// int main(){
//
//   struct point {
//     double x;
//     double y;
//   };
//
//   struct rect {
//     struct point pt1;
//     struct point pt2;
//   };
//
//   double computedist(struct rect r){
//     return sqrt((r.pt1.x - r.pt2.x)*(r.pt1.x - r.pt2.x) + (r.pt1.y - r.pt2.y)*(r.pt1.y - r.pt2.y));
//   }
//
//   struct rect rr;
//
//   rr.pt1.x = 1;
//   rr.pt2.x = 3;
//   rr.pt1.y = 4;
//   rr.pt2.y = 8;
//
//   printf("%lf\n", computedist(rr));
//
//   return 0;
// }
//// ***************************************************************************
/* a program to print one word per line... Exercize 1-12 in TCPL */
//// ************************************************************************
// while ((q=getchar()) != EOF){
//   if (!(q == '\n' || q == ' ' || q == '\t' )){
//     printf("%c", q);
//   } else {
//     printf("\n");
//   }
// }
//// ************************************************************************
/* a program to print our a histogram of frequencies of different characters in the input ... Exercize 1-14 in TCPL */
//// ************************************************************************
// int charins[26], maxval = 0, c = 0;
// char q;
// for (c=0;c<26;c++){
//   charins[c] = 0;
// }
// maxval = 0;
// while ((q = getchar()) != EOF){
//   if (!(q=='\n' || q==' ' || q == '\t')){
//     charins[q - 'a'] += 1;
//     maxval = (maxval>charins[q - 'a']) ? maxval : charins[q - 'a'];
//   } else {
//     while (maxval>0){
//       // printf("%d\n",maxval);
//       for (c=0;c<26;c++){
//         if (maxval == charins[c]){
//           charins[c]--;
//           printf("X");
//         } else{
//           printf(".");
//         }
//       }
//       maxval--;
//       printf("\n");
//     }
//     for (c=0;c<26;c++){
//       printf("%c", c+'a');
//     }
//     printf("\n");
//   }
// }
//// ************************************************************************
/*    Count if the two values are equal without using equality operator     */
//// ************************************************************************

// int main(int argc, char * argv[]){
//     if (argc!=3){
//         printf("Give me two values\n");
//     } else {
//         printf("%d and %d ", atoi(argv[1]), atoi(argv[2]));
//     }

//     if (atoi(argv[1]) & atoi(argv[2])){
//         printf("are equal");
//     } else {
//         printf("are not equal");
//     }
//     return 0;
// }

//// ************************************************************************
/*                                  Linked lists                           */
//// ************************************************************************

// typedef struct LinkedList {
//         int data;
//         struct LinkedList *next;
//     } LinkedList;
    

// void printLL(LinkedList *head){
//     printf("[ ");
//     while (head){ // checks if its a null poiner 
//         printf("%d ", head->data);
//         head = head->next;
//     }
//     printf("] \n");
// }

// void Insert(int data, LinkedList **head){ // inserts element in front of the list
//     LinkedList *newElem = (LinkedList *) malloc(sizeof(LinkedList)); // this just creates a new element in the memory of appropriate size
//     newElem->next = *head;
//     newElem->data = data;
//     *head = newElem;
// }

// void Delete(LinkedList ** head){ // delets element in the front of the list
//     *head = (*head)->next;
// }

// void DeleteElement(LinkedList ** head, int key){

//     LinkedList *elem = *head;

//     if (*head && key == (*head)->data){
//         *head = (*head)->next;
//         return;
//     }

//     while(elem){
//         if (elem->next->data == key){
//             elem->next = elem->next->next;
//             return;
//         }
//         elem = elem->next;
//     }
   
// }

// void DeleteElements(LinkedList ** head, int key){
   
//     if (*head && key == (*head)->data){
//         *head = (*head)->next;
//     }
//     LinkedList *elem = *head;
//     while(elem && elem->next){
//         if ((elem->next)->data == key){
//             elem->next = (elem->next)->next;
//         } else {
//             elem = elem->next;
//         }
//     }
   
// }

// int Mbehindhelper(int pos, int *val, LinkedList *head){
//     if (head){
//         int q = 1 + Mbehindhelper(pos,val,head->next);
//         if (q == pos){
//             *val = head->data;
//         }
//         return q;
//     } else {
//         return 0;
//     }
// }
// // mbehind prints the nth element from the tail of a linked list recursively
// int Mbehind1(int pos, LinkedList **head){
//     int *val;
//     Mbehindhelper(pos,val,*head);
//     return *val;
// }


// int Mbehind2(int pos, LinkedList **head){
//     LinkedList *train1, *train2;
//     train1 = train2 = *head;
//     for (int i = 0; i<pos;i++){
//         if (train1->next){
//             train1 = train1->next;
//         } else {
//             return -1;
//         }
//     }
//     while (train1->next){
//         train1 = train1->next;
//         train2 = train2->next;
//     }
//     return train2->data;
// }
    
// int DtermineIfCyclic(node *head){
//     node * fast, *slow;
//     fast = slow = head;
//     whie (1){
//         if (!fast || ! fast->next){
//             return 0;
//         } else if (fast == slow || fast->next == slow){
//             return 1;
//         }
//         slow = slow->next;
//         fast = fast->next->next;
//     }
// }

// int main(){

//     LinkedList *LL = NULL;
//     Insert(11,&LL);
//     Insert(12,&LL);
//     Insert(13,&LL);
//     Insert(14, &LL);
//     Insert(15,&LL);
//     Insert(16,&LL);
//     Insert(17,&LL);
//     Insert(18,&LL);
//     printLL(LL);
//     DeleteElements(&LL, 12);
//     printLL(LL);
//     printf("%d\n", Mbehind1(3, &LL));
//     printf("%d\n", Mbehind2(3, &LL));
//     //printLL(LL);
//     return 0;
// }

//// **********************************************************************/
//// **********************************************************************/
/* * * * * * * * * * * * * * * Binary trees * * * * * * * * * * * * * * * */
//// **********************************************************************/
//// **********************************************************************/

// typedef struct BT {
//     int val;
//     struct BT *left;
//     struct BT *right;
// } BT;

// void createNewNode(BT ** node, int val){ // we pass a pointer to a pointer 
//     BT * newnode = (BT *) malloc(sizeof(BT));
//     newnode->val = val;
//     newnode->left = NULL; // these have to be null for good initialization
//     newnode->right = NULL;
//     *node = newnode; // we set the pointer to the pointer of node to point to the same address where newnode is.
//                      // thus we update the contents of the adress that is being pointed to 
// }

// void BSTinsert(BT ** tree, int val){
//     if (*tree){ // checks if the tree pointer is null 
//         if(((*tree)->val)>val){
//             if ((*tree)->left){
//                 BSTinsert(&((*tree)->left), val);
//             } else {
//                 createNewNode(&(*tree)->left, val);
//             }
//         } else {
//             if ((*tree)->right){
//                 BSTinsert(&((*tree)->right), val);
//             } else {
//                 createNewNode(&(*tree)->right, val);
//             }
//         }
//     } else {
//         createNewNode(tree,val);
//     }
// }

// int BSTdepth(BT ** tree){ // returns the depth of the tree
//     if (*tree){
//         int l,r;
//         l = BSTdepth(&(*tree)->left) + 1;
//         r = BSTdepth(&(*tree)->right) + 1;
//         return (l>r)*l + (r>=l)*r;
//     }
//     return 0;
// }

// void BSTprintATdepth(BT ** tree, int depth, int space){
//     if (*tree){
//         if (depth == 0){
//             for (int i = 0; i<space; i++){
//                 printf(" ");
//             }
//             printf("%d", (*tree)->val);
//         } else {
//             BSTprintATdepth(&(*tree)->left, depth - 1, space);
//             BSTprintATdepth(&(*tree)->right, depth - 1, space);
//         }
//     }
// }

// void BSTprint(BT ** tree){
//     int len = BSTdepth(tree);
//     int slots = pow(2,len) - 1;
//     for (int i = 0; i<len; i ++){
//         BSTprintATdepth(tree, i, slots = (slots+2)/2);
//         printf("\n");
//     }

// }

// int LowestCommonAncestor(BT ** tree, int val1, int val2){ // find the lowest common ancestor of two nodes in a tree
//     if ((*tree)->val < val2){
//         if ((*tree)->val < val1)
//             return LowestCommonAncestor(&(*tree)->left, val1, val2);
//         else
//             return (*tree)->val;
//     } else {
//         return LowestCommonAncestor(&(*tree)->right, val1, val2);
//     }
// }

// int main (){
//     BT * tree = NULL;
//     BSTinsert(&tree, 10);
//     BSTinsert(&tree, 5);
//     BSTinsert(&tree, 3);
//     BSTinsert(&tree, 2);
//     BSTinsert(&tree, 13);
//     BSTinsert(&tree, 6);
//     printf("%d\n", tree->left->left->val);
//     printf("%d\n", BSTdepth(&tree));
//     BSTprint(&tree);
//     return 0;
// }

//// **********************************************************************/
//// **********************************************************************/
/* * * * * * * * * * * * * String manipulation * * * * * * * * * * * * * */
//// **********************************************************************/
//// **********************************************************************/

// char * flipSentance(char * sentance){ // this is one way to flip words in a sentance
//     int senlenS = strlen(sentance)-1; // this index will hit the last letter in the sentance 
//     int bufpos = 0, senlenC, senlenE;
//     char * buffer = (char * ) malloc(senlenS + 2);
//     printf("The passed sentance is %d letters long\n", senlenS);

//     while ((senlenE = senlenC = senlenS) > 0){ // if senlenS is 0 we hit the start of the sentance so we stop
//         while((senlenC>0) & (sentance[senlenC--] != ' ')){
//             ;
//         }
//         if (senlenC<0)
//             senlenC = 0;
//         senlenS = senlenC;
//         senlenC+=(2*(senlenC>0));
//         while (senlenC<=senlenE){
//             buffer[bufpos++] = sentance[senlenC++];
//         }
//         buffer[bufpos++] = ' ';
//     }
//     buffer[bufpos] = '\0';
//     return buffer;
    
// }

// void PermuteHelper(int used[], char * out, char * str, int length, int gathered){
//     if (gathered == length){
//         printf("%s\n", out);
//         return;
//     }
//     for (int i=0; i<length; i++){
//         if (used[i])
//             continue;
//         out[gathered] = str[i];
//         used[i] = 1;
//         PermuteHelper(used,out,str,length,gathered+1);
//         used[i] = 0; // once we have found all of permutations of a character being used in specific location we reset that location
//     }
// }

// void Permute(char * str){
//     int length = strlen(str), i;
//     int used[length]; // this array keeps track of which of the letters have already been used
//     char * out = (char *) malloc(length+1);
//     out[length] = '\0';

//     for (i = 0; i<length; i++){ // reset the used array
//         used[i] = 0;
//     }
//     PermuteHelper(used,out,str,length,0);
//     free(out);
//     free(used);
// }

// void DoCombine(char * str, char * out, int length, int cur, int start){
//     for (int i = start; i<length; i++){
//         out[cur] = str[i];
//         out[cur+1] = '\0';
//         printf("%s\n", out);
//         if (i<length-1) // if we haven't reached the end of the strin, we can tag another character
//             DoCombine(str,out,length,cur+1,i+1);
//     }
// }

// int Combine( char * str){
//     int length = strlen(str);
//     char * out;
//     out = (char *) malloc(length + 1);
//     if (!out)
//         return 0; // failed
//     DoCombine(str,out,length,0,0);
//     free(out);
//     return 0;
// }

// int main(int a, char * b[] ){

//     // printf("%s\n", b[1]);
//     // char * flipped = flipSentance(b[1]);
//     // printf("%s", flipped);   
//     // free(flipped);

//     printf("We want to find all char permutations of %s \n",b[1]);
//     Permute(b[1]);

//     printf("We want to find all  char combinations of %s \n",b[1]);
//     Combine(b[1]);

//     return 1;
// }

//// **********************************************************************/
//// **********************************************************************/
/* * * * * * * * * * * * * Computer vision prob * * * * * * * * * * * * * */
//// **********************************************************************/
//// **********************************************************************/

typedef struct pt {
    int x;
    int y;
} pt;

typedef struct rect {
    struct pt UL;
    struct pt LR;
} rect;

bool Overlap(rect A, rect B){ // thid function finds if the two lectanbles overlap
    return ((A.UL.x <= B.LR.x) && (A.LR.x >= B.UL.x) && (A.UL.y>=B.LR.y) && (A.LR.y<=B.UL.y));
}

int Endianess1(){ // returns 1 if little endian and 0 if big endian
    int num = 1;
    return ((char) num) > 0; 
}

int Endianess2(){ // returns 1 if little endian and 0 if big endian
    union {
        int theInt;
        char theByte;
    } endiantest;
    endiantest.theInt = 1;
    return endiantest.theByte;
}

int countOnes(int val){ // counts the number of ones in a bit representaiton of a number
    int count = 0;
    while (val>0){
        count += (val & 1);
        val>>=1;
    }
    return count;
}

int main(int a, char * b[]){
    // printf("%d %d\n", Endianess1(), Endianess2());
    printf("The number %d has %d in bit representation", atoi(b[1]), countOnes(atoi(b[1])));
    return 1;
}