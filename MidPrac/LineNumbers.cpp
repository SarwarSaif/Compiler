#include <bits/stdc++.h>
using namespace std;
int main(){

    FILE *p1,*p2;
    char c;
    int n=1;
    p1=fopen("HeaderChecker.cpp","r");
    p2=fopen("LineAdder.txt","w");
    if(!p1)
        cout<<"File can't be opened";
    else{
        fprintf(p2,"%d: ",n);
        while( (c=fgetc(p1))!= EOF ){
            if(c=='\n'){
                fputc(c,p2);
                n++;
                fprintf(p2,"%d: ",n);
            }
            else{
                fputc(c,p2);
            }
        }
    }
    fclose(p1);
    fclose(p2);

    p2=fopen("LineAdder.txt","r");
    while( (c=fgetc(p2))!=EOF ){
        cout<<c;
    }


    return 0;
}
