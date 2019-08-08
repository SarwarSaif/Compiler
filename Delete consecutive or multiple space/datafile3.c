#include <stdio.h>
int main(void)
{
    FILE *p1,*p2; char c;

    p1 = fopen("input.c", "r");
    p2 = fopen("header.txt","w");
    int n=1;
    if(!p1) printf("\nFile can't be opened!");
    else {
      	while((c = fgetc(p1)) != EOF) {



                while(c=='\n' || c==' '){
                        if(c=='\n')
                            fprintf(p2," ");
                    c = fgetc(p1);

                        if(c=='/'){
                        c=fgetc(p1);
                        if(c=='/')
                        {
                            while(c!='\n')
                                c=fgetc(p1);
                        }
                        else if(c=='*'){
                                c=fgetc(p1);
                            while(c!='*'){
                                c=fgetc(p1);
                            }
                            c=fgetc(p1);
                        }
                }


                }

            fputc(c, p2);


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


