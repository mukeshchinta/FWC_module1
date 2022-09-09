#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
int main(void)
{
bool a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,X=0,Y=0,Z=0;
DDRC=0b11110000;
PORTC=0b00001111;
DDRD=0b11000011;
PORTD=0b00111100;
DDRB=0b00000111;
while(1)
{
a=(PINC&(1<<PINC1))==(1<<PINC1);
b=(PINC&(1<<PINC2))==(1<<PINC2);
c=(PINC&(1<<PINC3))==(1<<PINC3);
d=(PINC&(1<<PINC4))==(1<<PINC4);
e=(PIND&(1<<PIND2))==(1<<PIND2);
f=(PIND&(1<<PIND3))==(1<<PIND3);
g=(PIND&(1<<PIND4))==(1<<PIND4);
h=(PIND&(1<<PIND5))==(1<<PIND5);
X=(a*e+!a*!e)&(b*f+!b*!f)&(c*g+!c*!g)&(d*h+!d*!h); 
Y=(d*!h)|((c*!g)&(d*h+!d*!h))|((b*!f)&(c*g+!c*!g)&(d*h+!d*!h))|((a*!e)&(c*g+!c*!g)&(d*h+!d*!h)&(b*f+!b*!f)); 
Z=(!d*h)|((!c*g)&(d*h+!d*!h))|((!b*f)&(c*g+!c*!g)&(d*h+!d*!h))|((!a*e)&(c*g+!c*!g)&(d*h+!d*!h)&(b*f+!b*!f));

PORTB |=(X<<0);
PORTB |=(Y<<1);
PORTB |=(Z<<2);
}
return 0;
}
