#include <bits/stdc++.h>

using namespace std;

FILE* input;
FILE* output;

int main()
{
    ///STEP 1:

    char c;
    int ln = 1;
    input = fopen("Input.cpp", "r");
    output = fopen("Output1.cpp", "w");

    fprintf(output,"%d ",ln);
    ln++;
    while((c=fgetc(input))!=EOF)
    {
        if(c=='\n')
        {
            fprintf(output,"\n%d ",ln);
            ln++;
        }
        else
            fputc(c, output);

    }
    fclose(input);
    fclose(output);

    printf("\nINPUT FILE: \n\n");
    input = fopen("Input.cpp", "r");
    while((c=fgetc(input))!=EOF)
    {
        printf("%c",c);
    }

    fclose(input);

    printf("\nLine no added : \n\n");
    input = fopen("Output1.cpp", "r");
    while((c=fgetc(input))!=EOF)
    {
        printf("%c",c);
    }
    printf("\n\n\n");

    printf("\n\n\nALL CHECKED ERRORS ARE : \n\n");

    ///Parenthesis Balance Checker:

    input = fopen("Output2.cpp", "r");

    ln=1;
    int parBalance = 0;
    while((c=fgetc(input))!=EOF)
    {
        if(c=='\n')
        {
            ln++;
        }
        else if(c=='{')
        {
            parBalance++;

        }
        else if(c=='}')
        {
            parBalance--;

        }
        if(parBalance <0)
        {
            printf("PARENTHESIS ERROR AT LINE %d\n",ln);
            parBalance=0;
        }
    }
    fclose(input);

    ///semicolon mismatch checker:

    input = fopen("Output2.cpp", "r");
    ln=1;
    printf("\n\n");
    int semiBalance = 0;
    char chk[100],chk2[100];
    int  j=0;
    while((c=fgetc(input))!=EOF)
    {
        chk[j]=c;
        j++;
        if(c=='\n')
        {
            chk[--j]=NULL;

            if(strcmp(chk,chk2)==0)
                printf("DUPLICATE  TOKEN = %s AT LINE %d\n",chk,ln);
            strcpy (chk2,chk);
            ln++;
            j=0;
        }
        if(c==' ')
        {
            chk[--j]=NULL;

            if(strcmp(chk,chk2)==0)
                printf("DUPLICATE  TOKEN = %s AT LINE %d\n",chk,ln);
            strcpy (chk2,chk);

            j=0;
        }
    }
    fclose(input);

    ///If else balance checker :

    input = fopen("Output2.cpp", "r");
    ln=1;
    printf("\n\n");
    int ifBalance = 0;


    while((c=fgetc(input))!=EOF)
    {
        chk[j]=c;
        if(c=='\n')
            ln++;
        j++;
        if(c==' ')
        {
            chk[--j]=NULL;
            if(strcmp(chk,"if")==0)
            {
                ifBalance=1;
            }
            else if(strcmp(chk,"else")==0)
            {
                ifBalance--;
            }

            if(ifBalance <0)
            {
                printf("EXTRA ELSE DETECTED AT LINE %d\n",ln);
                ifBalance=0;
            }

            strcpy (chk2,chk);
            j=0;
        }
    }
    fclose(input);

}
