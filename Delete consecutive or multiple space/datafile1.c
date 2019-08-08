#include <stdio.h>
int main(void)
{
    FILE *p1,*p2; char c;

    p1 = fopen("input.c", "r");
    p2 = fopen("header.txt","w");

    if(!p1) printf("\nFile can't be opened!");
    else {
      	while((c = fgetc(p1)) != EOF) {
        		if ((c == '<')){
                    c = fgetc(p1);
                     while(c!='>'){
                            fputc(c, p2);
                        c = fgetc(p1);


                     }

                fputc('\n',p2);
                //printf(c);
        		}


        }
    }
    fclose(p1);
    fclose(p2);

    p2 = fopen("header.txt","r");
    while((c=fgetc(p2))!=EOF)
		printf("%c",c);
    fclose(p2);

    return 0;
}
