#include<stdio.h>
#include<ctype.h>
int main()
{
    char str1[1001],str2[1001];
    int i;
    gets(str1);
    for(i=0;str1[i]!=NULL;i++)
    {
    if(isupper(str1[i]))
    {
        str2[i]=tolower(str1[i]);
    }
    else if(islower(str1[i]))
    {
        str2[i]=toupper(str1[i]);
    }
    else str2[i]=str1[i];
    }
        printf("%s",str2);
}