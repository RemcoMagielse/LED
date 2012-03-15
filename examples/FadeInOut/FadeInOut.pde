#include <cppfix.h>
#include <LED.h>

/**
  // Set channel to the arduino pin to which the LED is connected, or use if for another channel (such as DMX Channel)
  LED( uint32_t channel );
  // Set AutoWrite to TRUE if you use Arduino pins to directly control the LED value. The intensity will automatically be written to the ardunio pin ('channel') on update()
  LED( uint32_t channel, bool autoWrite );
  // x and y can be used to let a light body move across a 2D plane
  LED( uint32_t channel, bool autoWrite, uint16_t x, uint16_t y );
  // use intensity and on to predetermine the values; defaults are respectively 0 and true 
  LED( uint32_t channel, bool autoWrite, uint16_t x, uint16_t y, uint8_t intensity, bool on );
**/

LED * led1  =  new LED( 3, true ); 

// Or create an Array of LEDs
// LED * lamps[10]; 

void setup()
{
/** In case of an array, initialize it
  for (int i=0; i < 10; i++) {
      lamps[i] = new LED( );
  }
**/
}

void loop()
{
  if( !led1->isAnimating()) // Returns true if the LED is in an animation
  {
    if (led1->getIntensity() == 0) // Returns the current intensity of the LED
    {
      led1->lightTo( 255, 2000 ); // Sets the desired LED value and the time (in millis) it should take to get there
    }
    else {
      led1->lightTo( 0, 2000 );
    }
  }
  // Always call the update function; if autoWrite is on, the Arduino will write the current intensity to the set channel 
  led1->update();
  /**
  // If autoWrite is OFF, manually set the desired value
  analogWrite( led1->getChannel(), led1->getIntensity() );
  **/
}
