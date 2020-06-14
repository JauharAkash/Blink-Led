// blink.c
// Akash Jauhar
// Blink Lab
//
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
#include <bcm2835.h>
#include <stdio.h>
// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_V2_GPIO_P1_11
#define PIN2 RPI_V2_GPIO_P1_13 //defining the new pin
int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
//    bcm2835_set_debug(1);
    if (!bcm2835_init())
      return 1;
    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_OUTP);
    
    // Blink
while(1)
    {
        // Turn PIN On
        bcm2835_gpio_write(PIN, HIGH);
         // Turn PIN2 Off
        bcm2835_gpio_write(PIN2, LOW);
        // wait a bit
        bcm2835_delay(500);
        // Turn PIN Off
        bcm2835_gpio_write(PIN, LOW);
       // bcm2835_delay(500);
       // Turn PIN2 On
        bcm2835_gpio_write(PIN2, HIGH);
        // wait a bit
        bcm2835_delay(500);
    }

    bcm2835_close();
    return 0;

}

