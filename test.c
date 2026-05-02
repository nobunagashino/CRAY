#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/syslog.h>
void eputs(char *s);
/*
### DRAFT --needs checking...
# This allows the user to add two small numbers (result must be less
#then 10 ) in an interactive mode on a cray mp-x
# so what do you need..
# andrasrantos cray simulator up and running with DtCyber Running as the 
#front end. The DtCyber needs the NOS CCL Procedures for the CRAY installed
#https://github.com/kej715/COS-Tools
#has the details. You will also need the ack  
# https://github.com/kej715/ack
# installed as well...

############################
##ack -o test test.c
##use kermit to upload test.abs in "IAF on NOS2.8.7"
##login NOS (DtCyber) as guest/guest
##/CATLIST
##/SAVE,TEST
##/BEGIN,INSTALL,CRAY,TEST
## on the cray have a console running status and you will see the TEST
## being installed..
## on the DtCyber run
##/HELLO,ICF
##/logon,
##account,CRAY=AC.
##TEST,4,4.
#8
#There will also be an error message which I need to look at..


*/


int main(int argc, char *argv[]) 
{
char result[5];
/*    if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    } */

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    int sum = num1 + num2;
snprintf(result, sizeof(result), "%d", sum);
    printf("Sum: %d\n", sum);

eputs(result);
(*result)++;
/* eputs(result); */
    return 0;
}
void eputs(char *s) {
    syslog(s, SYSLOG_USER, 1, 1);
}

