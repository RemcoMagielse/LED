/*  LED Pogo example  */
#include <LED.h>  //Include the library

/* Initialize several LED Objects.
Since the LED is a complete object, you will initialize a pointer to the object. Instead
of accessing a function by using a dot (.), you use a pointer reference (->)

The LED constructor is as follows:
LED(  uint16_t channel,           This represents the channel (or pin) at which the LED operates. E.g. pin 3
      uint8_t intensity = 255,    This represents the intensity when initialized (0 - 255). Standard set to 255.
      bool on = true,             This determines whether the LED is ON or OFF (true, false)
      uint16_t x = 0,             This determines the x position of the LED.
      uint16_t y = 0,             This determines the y position of the LED
      bool autoWrite = true );    Determines whether the LED object should automatically write to the PWM pins.
      
Application #1
--------------
If you intend to use the LED as a representation of a physical LED, you will often select a channel that
represents a PWM pin on the Arduino and set the autoWrite function to 'true'.

Application #2
--------------
If you use the LED in a more complex program, for example when controlling DMX lights, you may want
to set the channel to the DMX channel and turn the autoWrite function off.
You then have to manually request the LED value with LED->getIntensity() and write this to the correct
output (e.g. DMX output).
*/

//Here we only define the channel and start intensity. We leave the other variables to standard
LED slowLED  =  new LED( 5, 0 );
LED fastLED  =  new LED( 6, 0 );

void setup()
{
  /*  Initialize both LEDs  */
  slowLED->init();
  fastLED->init();
}

void loop()
{
  /*  For the LEDs we check whether it is currently being animated.
      If it is not being animated, we start a new animation in which
      we subtract the current intensity from 255, thus effectively we
      reverse the intensity. Please note that this only works if you 
      animate between 255 and 0.
      We animate the slowLED in 3500 milliseconds to its new state
      and the fastLED in 500 milliseconds.
  */
  if( !slowLED->isAnimating() )
  {
    slowLED->lightTo( 255 - slowLED->getIntensity(), 3500 );
  }
  
  if( !fastLED->isAnimating() )
  {
    fastLED->lightTo( 255 - fastLED->getIntensity(), 500 );
  }
  
  slowLED->update();
  fastLED->update();
}
