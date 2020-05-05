#include "mbed.h"
#include "temperature.h"
#include "uLCD_4DGL.h"
#include "SDFileSystem.h"
#include <string>
#include <time.h>
#include "PinDetect.h"

//declare objects for pins used with pushbuttons
PinDetect pb1(p16); // declare pins
PinDetect pb2(p17);

TMP36::TMP36(PinName pin) : _pin(pin) {}
TMP36 myTMP36(p15);
uLCD_4DGL uLCD(p28, p27, p29);
SDFileSystem sd(p5, p6, p7, p8, "sd");

enum InputType {YES, NO, STAY}; // Input yes, no, stay
enum StateType {Q0, Q1, Q2};
InputType input = STAY;
StateType state = Q0; // initialize

void pb1_hit_callback (void)
{
input = YES;
if(state == Q0){
    uLCD.printf("Would you like to download another cipher key? \n");
}
else if (state == Q1){
    uLCD.printf("Download Complete");
}
}//yes button
void pb2_hit_callback (void)
{
input = NO;
uLCD.printf("Program Complete");
}//no button

int main(){
      float tempC_1; // first temperature
      float tempC_2; // second temperature
      int temp_diff; // temperature diff in an int
      char rand_key; // final random cipher key between 0-25
      char cipherText[1001]; // 1000 cipher keys
      cipherText[1000] = '\0'; //end of string character
      wait(0.5);
      for(int i=0; i<1000; i++){
         tempC_1 = myTMP36.read();
         tempC_2 = myTMP36.read(); // reads second temp
         temp_diff = int ((tempC_1 - tempC_2) * 1000); //takes diff and multiply by 1000
         srand(time(NULL)); // seed for rand number 
         rand_key = (temp_diff + rand())%26; // adds temp diff and rand number and mods it by 26 
         rand_key = rand_key + 65;
         cipherText[i] = rand_key;
    }
    
     pb1.mode(PullUp);
     pb2.mode(PullUp);
     wait(.01);
     pb1.attach_deasserted(&pb1_hit_callback);
     pb2.attach_deasserted(&pb2_hit_callback);
     pb1.setSampleFrequency(); //default is 20KHz sampling
     pb2.setSampleFrequency();
     
    mkdir("/sd/mydir", 0777);
    
    FILE *fp = fopen("/sd/mydir/positionCipherSender.txt", "w");
    if(fp == NULL) {
        uLCD.printf("Error Open \n"); 
        }
    fprintf(fp, "%d", 0);
    fclose(fp);  
    
    FILE *hp = fopen("/sd/mydir/positionCipherReceiver.txt", "w");
    if(hp == NULL) {
        uLCD.printf("Error Open \n"); 
        }
    fprintf(hp, "%d", 0);
    fclose(hp);  
     
     uLCD.printf("Would you like to download the cipher key?\n");
     while(1) {
        switch(state)
        {
        case(Q0):
        if (input == YES){
            state = Q1;
            FILE *gp = fopen("/sd/mydir/OTP.txt", "w");
            if(gp == NULL) {
                 uLCD.printf("Error Open \n"); 
             }
             fprintf(gp, "%s", cipherText);
             fclose(gp);
             input = STAY;
            }
        else if (input == NO){
            state = Q2;
            input = STAY;
            }
        else //input should be stay
            state = Q0;
        break;
        case(Q1):
        if (input == YES){
            state = Q2;
            FILE *gp = fopen("/sd/mydir/OTP2.txt", "w");
            if(gp == NULL) {
                 uLCD.printf("Error Open \n"); 
             }
            fprintf(gp, "%s", cipherText);
            fclose(gp);
            input = STAY;
            }
        else if (input == NO){
            state = Q2;
            input = STAY;
            }
        else //input should be stay
            state = Q1;
        break;
        case(Q2):
        break;
        }
        
        
        
        
        }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    FILE *gp = fopen("/sd/mydir/OTP.txt", "w");
    if(gp == NULL) {
        uLCD.printf("Error Open \n"); 
        }
    fprintf(gp, "%s", cipherText);
    fclose(gp);
}       
