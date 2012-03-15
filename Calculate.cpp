/**
 * Calculate.cpp - A library for calculations not available in the standard Arduino language.
 *
 * Copyright (c) 2011 Remco Magielse, Intelligent Lighting Institute (ILI), TU/e. 
 * All rights reserved.
 */

#include "Calculate.h"

static const float PII = 3.14159265;

/** A linear transition **/
uint16_t CalculateClass::linear( uint32_t t, uint16_t b, int c, uint32_t d )
{
  uint16_t calculation = c * ((float)t/(float)d) + b;
  /** Serial.print("calc ");
  Serial.print(c);
  Serial.print("* (");
  Serial.print(t);
  Serial.print("/");
  Serial.print(d);
  Serial.print(") + "); 
  Serial.print(b);
  Serial.print( "=");
  Serial.println(calculation); **/

  return calculation;
}

/** A quadratic easing equation **/
float CalculateClass::quadratic( float t, float b, float c, float d, boolean easeIn, boolean easeOut )
{
  if(easeIn && !easeOut)
  {
    /** Checked: CORRECT **/
    t /= d;
    float calculation = c*t*t + b;
    return calculation;
  }
  
  else if(!easeIn && easeOut)
  {
    /** Checked: CORRECT **/
    t /= d;
    float calculation = -c*t*(t-2) + b;
    return calculation;
  }
  
  else
  {
    t /= d/2;
    if(t < 1)
    {
      float calculation = (c/2)*t*t + b;
      return calculation;
    }
    else
    {
      t--;
      float calculation = (-c/2) * (t*(t-2) - 1) + b;
      return calculation;
    }
  }
}

/** An exponential easing equation **/
float CalculateClass::exponential( float t, float b, float c, float d, boolean easeIn, boolean easeOut )
{
  if(easeIn && !easeOut)
  {
    t /= d;
    float calculation = c * sq(10 *(t/d - 1)) + b;
    return calculation;
  }
  
  else if(!easeIn && easeOut)
  {
    t /= d;
    float calculation = c * (-sq(-10 * t/d) + 1) +b;
    return calculation;
  }
  
  else
  {
    t /= d/2;

    if(t < 1)
    {
      float calculation = c/2 * sq(10 * (t-1) ) + b;
      return calculation;
    }
    else
    {
      t--;
      float calculation = c/2 * (-sq( -10 * t) + 2) + b;
      return calculation;
    }

  }
}

/** An circular easing equation **/
float CalculateClass::circular( float t, float b, float c, float d, boolean easeIn, boolean easeOut )
{
  if(easeIn && !easeOut)
  {
    t /= d;
    float calculation = -c * (sqrt(1 - t*t) - 1) + b;
    return calculation;
  }
  
  else if(!easeIn && easeOut)
  {
    t /= d;
    t--;
    float calculation = c * sqrt(1 - t*t) + b;
    return calculation;
  }
  
  else
  {
    t /= d/2;

    if(t < 1)
    {
      float calculation = -c/2 * (sqrt(1 - t*t) - 1) + b;
      return calculation;
    }
    else
    {
      t-=2;
      float calculation = c/2 * (sqrt(1 - t*t) + 1) + b;
      return calculation;
    }
  }
  
}

/** A sinus easing equation **/
float CalculateClass::sinus( float t, float b, float c, float d, boolean easeIn, boolean easeOut )
{
  if(easeIn && !easeOut)
  {
    float calculation = -c * cos(t/d * (PII/2)) + c + b;
    return calculation;
  }
  
  else if(!easeIn && easeOut)
  {
    t /= d;
    float calculation = c * sin(t/d * (PII/2)) + b;
    return calculation;
  }
  
  else
  {
    float calculation = -c/2 * (cos(PII * t/d) - 1) + b;
    return calculation;
  }
  
}

float CalculateClass::distance( float x1, float y1, float x2, float y2 )
{
	float x			=	sq( x1 - x2 );	//square the x-coordinates
	float y			=	sq( y1 - y2 );	//square the y-coordinates
	float distance	=	sqrt( x + y );	//square-root the sum of x and y
	return distance;
}

float CalculateClass::radian( float degrees )
{
	return (degrees/180) * PII;
}

float CalculateClass::degree( float radians )
{
	return (radians/PII) * 180;
}

CalculateClass Calculate;