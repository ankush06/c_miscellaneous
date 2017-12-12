#include<stdio.h>
#include<stdlib.h>
#include <regex.h> 
#include <ctype.h> 

#define RES_ICASE               0x0001
#define RES_NOSUB               0x0020
#define RES_EXTENDED            0
#define MAX_IP_LEN              19

//return 1 for valid ipv4 else 0
int isInValidIp(char *pIp)
{
    int    status;
    regex_t    re;

    char *dec_octet = "([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])";

    char regexp[5024]={'\0'};
    snprintf(regexp,5023,"^(%s\\.%s\\.%s\\.%s)$",dec_octet,dec_octet,dec_octet,dec_octet);

    if ( regcomp(&re, regexp, RES_EXTENDED|RES_NOSUB|RES_ICASE) != 0 )
    {
        return 0;
    }
    status = regexec(&re, pIp, (size_t) 0, NULL, 0);
    regfree(&re);
    if ( status != 0 )
    {
        return 0;
    }

    return 1;
}


int main()
{
    int rc = isInValidIp("10.207.18.17");

    if ( rc == 1)
        printf("valid\n");
    else
        printf("Invalid\n");

    return 0;
}

