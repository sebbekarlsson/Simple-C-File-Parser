#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>


/* Parse method */
int parse(char *filename){

    /* Setting vars */
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    /* Opening file from filename argument */
    fp = fopen(filename, "r");

    /* Returning false if we could not open the file */
    if (fp == NULL)
    return 0;
    
    /* Looping through each line of the file */
    while ((read = getline(&line, &len, fp)) != -1) {

        /* Printing the contents of the line */
        printf("%s", line);
    }

    /* Closing the file */
    fclose(fp);

    /* Freeing the line var from the RAM */
    if (line)
    free(line);
    
    /* Everything went good, returning True */
    return 1;
}

/* Main method */
int main(void){

    /* Parsing a file */
    parse("test.txt");

    /* The program finished */
    printf("parsed");
}
