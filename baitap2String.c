#include "stdio.h"
#include "stdint.h"

typedef struct
{
    char *ptr;
    uint8_t length;
}words;

uint8_t sizeString(const char string[]){
    uint8_t index = 1;
    for(uint8_t i = 0; string[i] != '\0'; i++)
        if(string[i] == ' ')
            index++;            
    return index;
}

void reverseString(const char string[]){
    uint8_t size = sizeString(string);
    words array[size];
    uint8_t index = 0;
    uint8_t count = 0;
    uint8_t i = 0;
    while ( *string != '\0')
    {
        if( *string == ' '){
            array[index].ptr = string - count;
            array[index].length = count;
            string++;
            index++;
            count = 0;
        }
        else{
            string++;
            count++;
        }
    }
    array[index].ptr = string - count;
    array[index].length = count;
    for (uint8_t i = size -1; i != 0 ; i--)
    {
        for (uint8_t j = 0; j < array[i].length; j++)
        {
            printf("%c",array[i].ptr[j]);
        }
        printf(" ");
    }  
    for (uint8_t j = 0; j < array[0].length; j++)
    {
        printf("%c",array[0].ptr[j]);
    }
}

int main(int argc, char const *argv[])
{
    char string[] = "nam hoang mai son nam trung hung thanh tung son nam";
    reverseString(string);
    return 0;
}

