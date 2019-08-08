#include <bits/stdc++.h>
using namespace std;

int main (){

    FILE *p1,*p2;
    char c;
    p1=fopen("headerInput.txt","r");
    p2=fopen("headerOutput.txt","w");
    if(!p1)
        cout<<"File can't be opened";
    else{
        while( (c=fgetc(p1))!=EOF ) {
            if(c=='#'){
                while( (c=fgetc(p1))!='<' ){
                    ;
                }
                while( (c=fgetc(p1))!='>' ){
                    fputc(c,p2);
                }
                fputc('\n',p2);

            }
        }
    }
    fclose(p1);
    fclose(p2);
    p2=fopen("headerOutput.txt","r");
    cout<<"Header File Names\n";
    if(!p2)
        cout<<"File can't be opened";
    else{
        while( (c=fgetc(p2))!=EOF ){
            cout<<c;
        }
    }
    fclose(p2);
    return 0;
}
