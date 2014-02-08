#include <stdio.h>


#define NUM 10000

char *my_fgets(char *s, int n, FILE *fp)
{
    char *const head = s;
    for (; n > 1; n--) 
    {
        int c = fgetc(fp);
        if (c == EOF)
            break;
        *s = c;
        s++;
        if (c == '\n')
            break;
    }
    if (s == head || ferror(fp))
        return NULL;
    *s = '\0';
    return head;
}


int main()
{	
	char str[NUM];	
	while(my_fgets(str, 4,stdin)!=NULL)
	{		
		printf("%s",str);
		fputs(str,stdout);
	}
	return 0;
}

