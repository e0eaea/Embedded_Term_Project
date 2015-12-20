#include <stdio.h>
#include <mysql/mysql.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <errno.h>

#define HOST "localhost" // 연결할 host 주소
#define USER "root" // 사용자 이름
#define PASS "al421s" // 패스워드
#define NAME "Term_Project" // 접속할 데이터베이스 이름

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
    char* query="select * from news_setting"; // 실행할 쿼리
    int len;
   
    MYSQL* conn_ptr; // MySQL과의 연결을 담당
    MYSQL_RES* res; // 쿼리에 대한 결과를 받는 변수
    MYSQL_ROW row; // 쿼리에 대한 실제 데이터 값이 들어있는 변수
    conn_ptr=mysql_init(NULL); // 초기화
    if(!conn_ptr){
        printf("mysql_init failed!!\n");
    }
    // MySQL에 연결
    conn_ptr=mysql_real_connect(conn_ptr, HOST, USER, PASS, NAME, 3306, (char*)NULL, 0);
    if(conn_ptr){
        printf("연결 성공\n");
    }else{
        printf("연결 실패\n");
    }
    
    if (wiringPiSetup() == -1)
        return 1 ;
    
    pinMode(SW1, INPUT);
    pinMode(SW2, INPUT);
    pinMode(SW3, INPUT);
    pinMode(SW4, INPUT);
    
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(BUZZ,OUTPUT);
    
    
    int current_led[4]={0};
    
    
    
    for(;;)
    {
        len=mysql_query(conn_ptr, query);
        res=mysql_store_result(conn_ptr); // 전속한 결과 값을 MYSQL_RES 변수에 저장
        // 쿼리 결과 값 출력
        int i=0;
        while((row=mysql_fetch_row(res))!=NULL)// 한 ROW 씩 얻어 온다
            current_led[i]=(int)row[4];
        
        if(digitalRead(SW1) == 0)
        {  current_led[0]=(current_led[0]==0) ?1 : 0 ; digitalWrite(LED1, current_led[0]); delay(300); }
        
        if(digitalRead(SW2) == 0)
        {  current_led[1]=(current_led[1]==0) ?1 : 0 ; digitalWrite(LED2, current_led[1]); delay(300);  }
        
        if(digitalRead(SW3) == 0)
        {  current_led[2]=(current_led[2]==0) ?1 : 0; digitalWrite(LED3, current_led[2]); delay(300);  }
        
        if(digitalRead(SW4) == 0)
        {  current_led[3]=(current_led[3]==0)? 1 : 0 ; digitalWrite(LED4, current_led[3]); delay(300);  }
        
    }
    return 0 ;
}
