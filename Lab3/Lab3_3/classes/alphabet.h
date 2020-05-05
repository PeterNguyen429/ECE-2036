#include "mbed.h"


class Alphabet{
    public:
        Alphabet();
        char* getArray();
    private:
        char array[27];
    };
    
    Alphabet::Alphabet(void){
        for(int i = 0; i < 26; i++){
            array[i] = i+65;
            }
            array[26] = '\0';
    }
    char* Alphabet::getArray(){
        return array;
    }