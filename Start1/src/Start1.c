/*
 ============================================================================
 Name        : Start1.c
 Author      : Luciano Miralles
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 4
#define LENI 30

int main(void) {

	setbuf(stdout,NULL);
    char loco[LEN];
    char loco1[LENI];


    printf("%d",sizeof(loco)-1);
    strncpy(loco1, "loco",sizeof(loco1));

    printf("\n%s", loco1);

    strncpy(loco, loco1, sizeof(loco)-1);
    printf("\n%s\n",loco);

    return 0;
}

