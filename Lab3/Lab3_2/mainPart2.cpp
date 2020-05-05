#include "mbed.h"
#include "alphabet.h"
#include "uLCD_4DGL.h"
#include "SDFileSystem.h"
#include <string>
#include <time.h>
#include "PinDetect.h"
uLCD_4DGL uLCD(p28, p27, p29);
SDFileSystem sd(p5, p6, p7, p8, "sd");
PinDetect pb1(p16); // declare pins
PinDetect pb2(p17);
PinDetect pb3(p18);
enum InputType {NEXT, BACK, ENCRYPT, STAY, STOP};
enum StateType {Q0, Q1, Q2};
StateType state = Q0;
InputType input = STAY;

void pb1_hit_callback (void){
    input = NEXT;
}
void pb2_hit_callback (void){
    input = BACK;
}
void pb3_hit_callback (void){
    input = ENCRYPT;
}

char currLetter;
int main() {
    char* array = NULL;
    Alphabet list;
    array = list.getArray();
     pb1.mode(PullUp);
     pb2.mode(PullUp);
     pb3.mode(PullUp);
     wait(.01);
     pb1.attach_deasserted(&pb1_hit_callback);
     pb2.attach_deasserted(&pb2_hit_callback);
     pb3.attach_deasserted(&pb3_hit_callback);
     pb1.setSampleFrequency(); //default is 20KHz sampling
     pb2.setSampleFrequency();
     pb3.setSampleFrequency();
     int index = 0;
     char arrayCipher[1001];
     int position;
     char encrypt;
        FILE *fp = fopen("/sd/mydir/OTP.txt", "r");
            if(fp == NULL) {
                uLCD.printf("Open Error!!!\n"); }
            else
            {
                 fscanf(fp, "%s",arrayCipher);
                 fclose(fp);
            }
            // read
        FILE *fp2 = fopen("/sd/mydir/positionCipherSender.txt", "r");
            if(fp2 == NULL) {
                uLCD.printf("Open Error!!!\n"); }
            else
            {
                fscanf(fp2, "%i",&position);
                fclose(fp2);
            }//read
     

     
    while(1){
     if(input == STAY){
        uLCD.cls();
        currLetter = array[index];
        uLCD.locate(7,0);
        uLCD.text_width(5);
        uLCD.text_height(5);
        uLCD.printf("%s",currLetter);
        input = STOP;
        }
     else if (input == NEXT){
         if(index < 26){
           index += 1;
          }
         uLCD.cls();
         currLetter = array[index];
         uLCD.locate(7,0);
         uLCD.text_width(5);
         uLCD.text_height(5);
         uLCD.printf("%c",currLetter);
         input = STOP;
         }
     else if (input == BACK){
         if(index > 0){
           index -= 1;
          }
         uLCD.cls();
         currLetter = array[index];
         uLCD.locate(7,0);
         uLCD.text_width(5);
         uLCD.text_height(5);
         uLCD.printf("%c",currLetter);
         input = STOP;
         }
     else if (input == ENCRYPT){
         encrypt = (((currLetter - 65) + (arrayCipher[position] - 65))%26)+65;
         uLCD.cls();
         uLCD.locate(7,0);
         uLCD.text_width(5);
         uLCD.text_height(5);
         uLCD.printf("%c",encrypt);
         input = STOP;
         position += 1;
             fp2 = fopen("/sd/mydir/positionCipherSender.txt", "w");
             if(fp2 == NULL)
             {
               uLCD.printf("Error Open \n");
             }
             else
             {
               fprintf(fp2, "%i",position);
               fclose(fp2);
             }
        }
         
         
 }
}



