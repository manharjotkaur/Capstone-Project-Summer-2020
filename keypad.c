//C code for Interfacing 4x4 Matrix Keypad with Beaglebone Black using GPIO pins
#include <stdio.h>
#include <unistd.h>
#include <iobb.h> //GPIO input_output library..

int main(void)
{
iolib_init(); //Initializing Library

//Set GPIO PIN Direction IN/OUT
iolib_setdir(8, 7, DigitalIn);   //GPIO_66 In Direction
iolib_setdir(8, 9, DigitalIn);   //GPIO_69 In Direction
iolib_setdir(8, 11, DigitalIn);  //GPIO_45 In Direction
iolib_setdir(8, 15, DigitalIn);  //GPIO_47 In Direction
iolib_setdir(8, 8, DigitalOut);  //GPIO_67 Out Direction
iolib_setdir(8, 10, DigitalOut); //GPIO_68 Out Direction
iolib_setdir(8, 12, DigitalOut); //GPIO_44 Out Direction
iolib_setdir(8, 14, DigitalOut); //GPIO_26 Out Direction

//Set Column pins to high
pin_high(8,8);
pin_high(8,10);
pin_high(8,12);
pin_high(8,14);

//set Row pin to low and pulled up through resister.
pin_low(8,7);
pin_low(8,9);
pin_low(8,11);
pin_low(8,15);


while(1) //infinite loop for checking user input
{
//set column_1 pin high
pin_low(8, 8);
//checking Row_1 pins input

if(is_low(8,7))
{printf("1");} //print "1"

if(is_low(8,9))
{printf("4");}  //print "4"

if(is_low(8,11))
{printf("7")}  //print "7"

if(is_low(8,15))
{printf("*")}  //print "*"

//set column_1 pin low
pin_high(8,8);

//For column_2
pin_low(8, 10);
if(is_low(8,7))
{printf("2");}  //print "2"
if(is_low(8,9))
{printf("5");}  //print "5"
if(is_low(8,11))
{printf("8")}  //print "8"
if(is_low(8,15))
{printf("0")}  //print "0"
pin_high(8,10);

//For column_3
pin_low(8, 12);
if(is_low(8,7))
{printf("3");}  //print "3"
if(is_low(8,9))
{printf("6");}  //print "6"
if(is_low(8,11))
{printf("9")}  //print "9"
if(is_low(8,15))
{printf("#")}  //print "#"
pin_high(8,12);

//For column_4
pin_low(8, 14);
if(is_low(8,7))
{printf("A");}  //print "A"
if(is_low(8,9))
{printf("B");}  //print "B"
if(is_low(8,11))
{printf("C")}  //print "C"
if(is_low(8,15))
{printf("D")}  //print "D"
pin_high(8,14);

}
iolib_free();// Reset GPIO pins
return(0);
}