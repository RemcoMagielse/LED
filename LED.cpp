/**
 * LED.cpp
 * 
 * Copyright (c) 2011 
 
 * Remco Magielse & Serge Offermans
 
 * Intelligent Lighting Institute (ILI), TU/e.
 *
 * All rights reserved. LAST UPDATE: 13-01-2012
**/
#include "LED.h"
#include "Calculate.h"

/** CONSTRUCTORS **/
LED::LED()
{
  _x          	=  	0;
  _y          	=  	0;
  _intensity 	=  	255;
  _channel   	=  	0;
  _on		 	=	true;
  _autoWrite	=	false;
  _isAnimating	=	false;
  _animType		= 	0;

	init();
}
LED::LED( uint16_t channel, uint8_t intensity, bool on, uint16_t x, uint16_t y, bool autoWrite)
{
  _x          	=  	x;
  _y          	=  	y;
  _intensity  	=  	intensity;
  _channel    	=  	channel;
  _on		 	=	on;
  _autoWrite	=	autoWrite;
  _isAnimating	=	false;
  _animType		= 	0;
  
  init();
}
LED::~LED()
{
}

/** VOID FUNCTIONS **/
void LED::init()
{
	if( _autoWrite )
	{
		pinMode( _channel, OUTPUT );
	}
}

void LED::update()
{
	if( _isAnimating )
	{
		//Check if the animation is still valid
		if( millis() < _endTime )
		{
			uint16_t animatedIntensity	=	0;
			uint32_t t	=	( millis() - _startTime );	//current time
			uint16_t b	=	_startVal;					//begin value
			int      c	=	( _endVal - _startVal );		//change (may be negative)
			uint32_t d	=	_endTime - _startTime;
			switch( _animType )
			{
				case QUADRATIC:
					animatedIntensity	=	Calculate.quadratic( (float)t, (float)b, (float)c, (float)d, true, true);
					break;
				case EXPONENTIAL:
					animatedIntensity	=	Calculate.exponential( (float)t, (float)b, (float)c, (float)d, true, true );
					break;
				case CIRCULAR:
					animatedIntensity	=	Calculate.circular( (float)t, (float)b, (float)c, (float)d, true, true );
					break;
				case SINUS:
					animatedIntensity	=	Calculate.sinus( (float)t, (float)b, (float)c, (float)d, true, true );
					break;		
				default:
					// Functions other than linear may not work as the float of c can somehow not be neagtive.
					animatedIntensity	=	Calculate.linear( t, b, c, d );
					break;
				
			}
			setIntensity( animatedIntensity );
		}
		else if( millis() >= _endTime)
		{
			setIntensity( _endVal );
			_isAnimating = false;
		}
		if( _autoWrite )
		{
			analogWrite(_channel, _intensity);
		}
	}
	/** If there is no animation going on,
		and the device is turned off,
		and the intensity is not set to 0,
		turn the LED off
	**/
	if( !_isAnimating && !_on && _intensity > 0 )
	{
		setIntensity( 0 );
	}
}

void LED::setIntensity( uint8_t intensity )
{
	if( intensity != _intensity )
	{
		_intensity = constrain( intensity, 0, 255 );
		analogWrite( _channel, (int) _intensity );
	}
}
void LED::setX( uint16_t x )
{
	_x	=	x;
}
void LED::setY( uint16_t y )
{
	_y	=	y;
}
void LED::setPosition( uint16_t x, uint16_t y )
{
	_x	=	x;
	_y	=	y;
}
void LED::setChannel( uint16_t channel )
{
	_channel	=	channel;
}
void LED::toggle()
{
	_on	=	!_on;
}
void LED::toggle( uint32_t duration )
{
	if( !isAnimating() )
	{
		if(_on)
		{
			lightTo( 0, duration );
		}
		else
		{
			lightTo( 255, duration );
		}
		_on	=	!_on;
	}
}
void LED::setToggle( bool toggle )
{
	_on	=	toggle;
}
void LED::lightTo( uint8_t to, uint32_t duration )
{
	_isAnimating	=	true;
	_startTime		=	millis();
	_endTime		=	millis() + duration;
	_startVal		=	_intensity;
	_endVal			=	to;
	_animType		= 	0;
}
void LED::lightFromTo( uint8_t from, uint8_t to, uint32_t duration )
{
	_isAnimating	=	true;
	_startTime		=	millis();
	_endTime		=	millis() + duration;
	_startVal		=	from;
	_endVal			=	to;
	//Implement the animations here
}
void LED::moveTo( uint16_t newX, uint16_t newY, uint32_t duration )
{
	//Something will happen here
}
void LED::setAnimationType( uint8_t type )
{
	_animType	=	constrain( type, 0, 5 );
}

/** bool FUNCTIONS **/
bool LED::isOn()
{
	return _on;
}
bool LED::isOff()
{
	return !_on;
}
bool LED::isAnimating()
{
	return _isAnimating;
}

/** INTEGER FUNCTIONS **/
uint8_t LED::getChannel()
{
	return _channel;
}
uint8_t LED::getIntensity()
{
	return _intensity;
}

/** uint16_t FUNCTIONS **/
uint16_t LED::getX()
{
	return _x;
}
uint16_t LED::getY()
{
	return _y;
}
