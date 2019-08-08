#include <bits/stdc++.h>
using namespace std;

int keywordRec(char lexem[20]){
    char key[100][100]={"int","float","double","void","char","long","if","else"};
    for(int i=0;i<8;i++){
        if(strcmp(lexem,key[i])==0)
            return 1;
    }
    return 0;

}

int idRec(char lex[20]){
    if(isalpha(lex[0]) || lex[0]=='_'){
        for(int i=1; i<strlen(lex); i++){
            if(!(isalpha(lex[i]) || isdigit(lex[i]) || lex[i]=='_') ){
                return 0;
            }

        }
    }
    else
        return 0;

    return 1;

}

int main(){

    FILE *p1,*p2,*p3;
    char c,c2,c3,d;
    char str[100];
    int x=0;
    p1=fopen("LexicalInput.txt","r");
    p2=fopen("LexicalOutput.txt","w");
    if(!p1)
        cout<<"File can't be opened";
    else{
        c=fgetc(p1);
        c2=c;
        while( c!=EOF ){

            if(!isalnum(c) )
            {
                c=fgetc(p1);
                if(c=='='){
                    fputc(c,p2);
                }

                if(c2!=' ' && c!='_'){
                    fputc(' ',p2);
                }
            }

            fputc(c,p2);
            c2=c;
            c=fgetc(p1);
            ungetc(c,p1);
            c=fgetc(p1);
            if(!isalnum(c2) )
            {
                if(c!=' ' && c2!='_'){
                    fputc(' ',p2);
                }
            }


        }
    }

    return 0;
}
