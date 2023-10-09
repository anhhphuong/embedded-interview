#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct 
{
    char* ptr;
    uint8_t length;
    uint8_t quantity;
    bool status;
}words;

uint8_t sizeString(char string[]){
    uint8_t size = 1;
    while (*string != '\0')
    {
        if(*string == ' ') size ++;
        string ++;
    }
    return size;
}

// ham tinh do dai cua 1 word trong chuoi
words* splitString(char string[], uint8_t size, words array[]){

    uint8_t count = 0;
    uint8_t index = 0;
    array[index].ptr = string;

    while(*string != '\0'){
        if(*string == ' '){
            array[index].length = count;
            count = 0;
            string ++;
            index ++;
            array[index].ptr = string;
        }
        else{
            string ++;
            count ++;
        }
    }
    array[index].length = count;
    return array;
}

// nam hoang mai son nam
// ham dem so lan ten xuat hien
void CountName(words array[], uint8_t size){
    for(uint8_t i = 0; i < size; i++){
        uint8_t cnt = 0;
        for(uint8_t j = 0; j < size; j++){
            uint8_t index = 0;
            while(array[i].ptr[index] == array[j].ptr[index]){
                index ++;
                if(array[i].length == index && array[j].length == index){
                    cnt ++;
                    //chong trung lap ten
                    if(cnt >= 2) array[j].status = false;
                    else array[j].status = true;
                    break;
                }
            }
            index = 0;
        }
        array[i].quantity = cnt;
    }
}

void printStr(words array[], uint8_t size){
    printf("\n");
    for (uint8_t i = 0; i < size; i++){
        if(array[i].status == true){ //ko in trung lap ten
            for (uint8_t j = 0; j < array[i].length; j++){
                printf("%c", array[i].ptr[j]);
            }
            printf(":\t %d\n", array[i].quantity);
        }
    }
}

int main(int argc, char const *argv[]){
    char string[] = "nam hoang mai son nam trung hoang son nam";
    uint8_t size = sizeString(string);
    words array[size];
    splitString(string, size, array);
    CountName(array, size);
    printStr(array, size);
    return 0;
}
