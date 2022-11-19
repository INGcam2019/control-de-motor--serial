#include "mbed.h"

DigitalOut myled(LED1);

Serial Computador(USBTX,USBRX);

PwmOut PWM1(PB_7);

DigitalOut IN1(PB_13);
DigitalOut IN2(PB_14); 
int RPM=0;
void DERECHA()
{
    IN1=1;
    IN2=0;
    

}

void IZQUIERDA()
{IN1=0;
    IN2=1;
     
}

void ACELERAR()
{if((IN1==0)&&(IN2==0)){
    PWM1=0;
    
}else{
    //int x=70;
    PWM1.period_ms(100);
PWM1=PWM1+0.1;


myled=!myled;

}
}
void FRENAR()
{
if((IN1==0)&&(IN2==0)){
    PWM1=0;
    
}else{
    //int x=10;
    PWM1.period_ms(100);
PWM1=PWM1-0.1;


//myled=!myled;

}
}
void DETENER()
{
    IN1=0;
    IN2=0;
PWM1=0;
}
void LeerSerial()
{
    if (Computador.readable())
    {
        char c = Computador.getc();
        /*if(c=='A')
        myled = !myled;
        */
        switch (c)
        {
            case 'A':
                DERECHA();
            break;
            case 'B':
                IZQUIERDA();
            break;
            case 'C':
                ACELERAR();
            break;
            case 'D':
                FRENAR();
            break;
            case 'E':
                DETENER();
            break;

        }
    }
}

int main() {

Computador.baud(9600);
Computador.attach(&LeerSerial);
    while(1) {
    }
}
