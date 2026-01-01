#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/syslog.h>
#define NUM_FIBS 10
/* Version of Kevin Jordans Fib example
   which will run in CRAY Interactive mode
https://github.com/kej715/ack
To run
Compile with ack
Upload to DtCyber front end as FIB
use procedure to install on CRAY eg
https://github.com/kej715/COS-Tools
BEGIN,INSTALL,CRAY,FIB.
On the DtCyber start a CRAY Inteteractive session
/HELLO,ICF
/LOGON
!ACCOUNT,AC=CRAY.
and then run
!FIB

*/

void eputs(char *s);
int main(int argc, char *argv[]) {
    int i1, i2, i3, n;
char result1[20];
char result2[20];
    i1 = 0;
    i2 = 1;
    for (n = 1; n <= NUM_FIBS; n++) {
      printf(" %d: %d\n", n, i2);
snprintf(result1, sizeof(result1), "%d :", n);
snprintf(result2, sizeof(result2), "%d", i2);
strcat(result1,result2);
eputs(result1);
      i3 = i1 + i2;
      i1 = i2;
      i2 = i3;
    }

    return 0;
}
void eputs(char *s) {
    syslog(s, SYSLOG_USER, 1, 1);
}

