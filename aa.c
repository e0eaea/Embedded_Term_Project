#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>



#define SW1 0 // BCM_GPIO  17
#define SW2 1 // BCM_GPIO  18
#define SW3 2 // BCM_GPIO  27
#define SW4 3 // BCM_GPIO  22
#define SW5 4 // BCM_GPIO  23

#define LED1 5// BCM_GPIO 24
#define LED2 6// BCM_GPIO 25
#define LED3 7// BCM_GPIO 4
#define LED4 8// SDA
#define BUZZ 9// SCL


int main (int argc, char* argv[])
{

    if (wiringPiSetup() == -1)
        return 1 ;
    
    // 옵션 지정하지 않았을 때 에러 출력하고 종료
    if (argc == 1) {
        fputs("에러! 옵션을 입력하지 않으셨군요...\n", stderr);
        exit(1);
    }
    
    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);
    pinMode(SW4, INPUT);
    
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(BUZZ,OUTPUT);
    
    
    int current_led1=0;
    int current_led2=0;
    int current_led3=0;
    int current_led4=0;
    int buzz5=0;
    
    int light=0;
    if(!strcmp(argv[2],"1")) light=1;
    
    if(!strcmp(argv[1],"1"))
        digitalWrite(LED1,light);
    if(!strcmp(argv[1],"2"))
        digitalWrite(LED2,light);
    if(!strcmp(argv[1],"3"))
        digitalWrite(LED3,light);
    if(!strcmp(argv[1],"4"))
        digitalWrite(LED4,light);
    if(!strcmp(argv[1],"5"))
        digitalWrite(BUZZ,light);
    
    return 0 ;
}
