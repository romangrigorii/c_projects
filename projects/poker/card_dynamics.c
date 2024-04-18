#include <stdio.h>
#include <stdlib.h>

#define HANDS {"2C", "2D", "2H", "2S","3C", "3D", "3H", "3S","4C", "4D", "4H", "4S","5C", "5D", "5H", "5S","6C", "6D", "6H", "6S","7C", "7D", "7H", "7S","8C", "8D", "8H", "8S","9C", "9D", "9H", "9S","TC", "TD", "TH", "TS","JC", "JD", "JH", "JS","QC", "QD", "QH", "QS","KC", "KD", "KH", "KS","AC", "AD", "AH", "AS"}
#define SUITS "CDHS"
#define NCARDS 52
#define NSUITS 4
#define NSUITED 13

int evaluate_hand(int cards, char *hand[cards]);// given 7 cards, the program gives a value to the hand, with royal flush being 0

int straight_flush(int cardarr[NSUITS][NSUITED]);
int four_of_kind(int cardarr[NSUITS][NSUITED]);
int full_house(int cardarr[NSUITS][NSUITED]);
int flush(int cardarr[NSUITS][NSUITED]);
int straight(int cardarr[NSUITS][NSUITED]);
int three_of_kind(int cardarr[NSUITS][NSUITED]);
int two_pair(int cardarr[NSUITS][NSUITED]);

int one_pair(int cards, char *hand[cards]);// identifies if there is a pair in the deck
int createarr(int cards, char *hand[cards], int cardarr[NSUITS][NSUITED]); // will place a hand on a 2D array from which counting is made easier
int giveval(char *card); // given a card this function returns its face falue
int givesuit(char *card); // given a card this function return the suit
int inrow(int *arr, int len); // given an array of 0s and 1s returns -1 if there is no 5-straight and returns the highest value card in a 5-straight if there is
void print_table(int cardarr[NSUITS][NSUITED]); // will print the 4x13 table of the card in possesion

void print_table(int cardarr[NSUITS][NSUITED]){
    for (int i=0; i<NSUITS; i++){
        for (int j=0; j<NSUITED; j++){
            printf("%d ", cardarr[i][j]);
        }
        printf("\n");
    }
}

int giveval(char  *card){
    if ((card[0]-'2')>=0 && (card[0]-'2')<=7){
        return card[0] - '2';
    } else {
        return 8*(card[0]=='T') + 9*(card[0]=='J') + 10*(card[0]=='Q') + 11*(card[0]=='K') + 12*(card[0]=='A');
    }
}

int givesuit(char *card){
    return (card[1]==SUITS[1]) + 2*(card[1]==SUITS[2]) + 3*(card[1]==SUITS[3]);
}

int createarr(int cards, char *hand[cards], int cardarr[NSUITS][NSUITED]){
    for (int i=0;i<cards;i++){
        cardarr[givesuit(hand[i])][giveval(hand[i])] = 1;
    }
}

int inrow(int *arr, int len){
    int i, count = 0, highest = -1;
    for (i=0;i<len;i++){
        if (arr[i]){
            count++;
        } else {
            count = 0;
        }
        if (count >= 5)
            highest = i;
    }
    return highest;
}

int straight_flush(int cardarr[NSUITS][NSUITED]){
    int straight = 0;
    for (int s = 0; s<NSUITS; s++){
        straight = inrow(cardarr[s],13);
        if (straight){
            return straight+1;
        }
    }
    return straight;
}

int four_of_kind(int cardarr[NSUITS][NSUITED]){
    int four_of_kind = 0;
    for (int c = 0; c<NSUITED;c++){
        four_of_kind = (c+1)*(cardarr[0][c]==1 && cardarr[1][c]==1 && cardarr[2][c]==1 && cardarr[3][c]==1);
        if (four_of_kind)
            return four_of_kind;
    }
    return four_of_kind;
}

int main(){
    //char *hand[] = {"2C","5C","9D","AS","5D","5H","2C"};
    // char *hand[] = {"AC","QC","KC","TS","TC","5H","JC"};
    char *hand[] = {"AC","QC","KC","AS","TC","AH","AD"};
    int cardarr[NSUITS][NSUITED], i, j;
    for (i=0;i<NSUITS;i++){
        for (j=0;j<NSUITED;j++){
            cardarr[i][j] = 0;
        }
    }
    createarr(7, hand, cardarr);
    print_table(cardarr);
    
    printf("%d\n",straight_flush(cardarr));
    printf("%d\n",four_of_kind(cardarr));
    return 0;
}