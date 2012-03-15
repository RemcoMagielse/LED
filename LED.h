/**
 * LED.h
 * 
 * Copyright (c) 2011 
 
 * Remco Magielse & Serge Offermans
 
 * Intelligent Lighting Institute (ILI), TU/e.
 *
 * All rights reserved. LAST UPDATE: 13-01-2012
**/

#ifndef LED_h
#define LED_h

/* The following code makes the Library compatible with Arduino 1.0 */
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
	#include "cppfix.h"
#endif


class LED
{
  public:
  	static const uint8_t LINEAR 		= 0;
  	static const uint8_t QUADRATIC 		= 1;
  	static const uint8_t EXPONENTIAL 	= 2;
  	static const uint8_t CIRCULAR 		= 3;
  	static const uint8_t SINUS 			= 4;
  
    LED();
    LED( uint16_t channel, uint8_t intensity = 255, bool on = true, uint16_t x = 0, uint16_t y = 0, bool autoWrite = true );
    ~LED();
    
    void init();
    void update();    
    void setIntensity( uint8_t intensity );
    void setX( uint16_t x );
    void setY( uint16_t y );
    void setPosition( uint16_t x, uint16_t y );
    void setChannel( uint16_t channel );
    void toggle();
	void toggle( uint32_t duration );
	void setToggle( bool toggle );
    void lightTo( uint8_t to, uint32_t duration );
    void lightFromTo( uint8_t from, uint8_t to, uint32_t duration );
    void moveTo( uint16_t newX, uint16_t newY, uint32_t duration );
    void setAnimationType( uint8_t type );
    
    bool isOn();
    bool isOff();
    bool isAnimating();
    
    uint8_t getChannel();
    uint8_t getIntensity();
    
    uint16_t getX();
    uint16_t getY();

  private:
  	bool _on, _autoWrite, _isAnimating;
    uint16_t _channel; 
    uint8_t _intensity;
    uint16_t _x, _y;
    /** Animation variables **/
    uint8_t _animType;
    long _startTime, _endTime;
    uint16_t _startVal, _endVal;
};

#endif

