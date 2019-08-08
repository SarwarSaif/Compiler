#include <bits/stdc++.h>
using namespace std;
int main(){

    FILE *p1,*p2;
    char c;
    int line=0;
    p1=fopen("remInput.c","r");
    p2=fopen("remOutput.txt","w");
    if(!p1)
        cout<<"File can't be opened";
    else{
        while( (c=fgetc(p1))!= EOF ){
            if(c=='\n'){
                if(line==0){
                    fputc(' ',p2);
                }
                line++;
            }
            else{
                if(c==' '){
                    fputc(c,p2);
                    while( (c=fgetc(p1))==' ' ){
                        ;
                    }
                }
                if(c=='/'){
                    c=fgetc(p1);
                    if(c=='/'){
                        while( (c=fgetc(p1))!='\n' )
                        {
                            ;
                        }
                        line++;
                        while( (c=fgetc(p1))=='\n' ){

                        }
                        //c=fgetc(p1);
                    }
                    else if(c=='*'){
                        while( (c=fgetc(p1))!='*' )
                        {
                            ;
                        }
                        c=fgetc(p1);
                        c=fgetc(p1);
                        while( (c=fgetc(p1))=='\n' ){
                            line++;
                        }
                    }
                }
                fputc(c,p2);
                line=0;
            }
        }
    }

    fclose(p1);
    fclose(p2);

    p2 = fopen("remOutput.txt","r");
    while((c=fgetc(p2))!=EOF)
		printf("%c",c);
    fclose(p2);

    return 0;
}
