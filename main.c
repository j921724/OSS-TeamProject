#include <stdio.h>

#define MAX 1024

// 오브젝트 타입 구분
typedef enum{
    UNDEFINED = 0,
    OBJECT = 1,
    ARRAY = 2,
    STRING = 3,
    PRIMATIVE = 4
}type_t;

// 토큰 구조
typedef struct{
    type_t type;
    int start;
    int end;
    int size;
}jsmntok_t;


//start, end
int Parser(char data[], int length){

    jsmntok_t token;
    int num=0;  // 따옴표(")가 여는 건지 닫는 건지 파악
    int start;
    int end;
    for(int i = 0; i < length ; i++){

        if(data[i] == '"'){
            num++;
            if(num%2!=0){
                token.start = i+1;
                printf("%d ~", token.start);
            }
            else{
                token.end =i;
                printf(" %d\n", token.end);
            }
        }
    }
}


int main(){

    FILE *fp=fopen("example.json", "r");
    int fileLength;
    fseek(fp,0,SEEK_END);
    fileLength=ftell(fp);


    rewind(fp);

    int length=0;
    char buffer[fileLength];
    char data[fileLength];


    while((buffer[0]=fgetc(fp))>0){
        if(buffer[0]!=0X00){
            length++;
            data[length-1]=buffer[0];
            if(length>=fileLength-1) break;
        }
    }
    data[length]=0X00;
    fclose(fp);

    //type!!

    Parser(data, length);
    
    printf("\n");
}

