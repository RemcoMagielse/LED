#ifndef Calculate_h
#define Calculate_h
/**
 * Calculate.h - A library for calculations not available in the standard Arduino language.
 *
 * Copyright (c) 2011 Remco Magielse, Intelligent Lighting Institute (ILI), TU/e. 
 * All rights reserved.
 */

/* The following code makes the Library compatible with Arduino 1.0 */
#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


class CalculateClass
{
  public:
    uint16_t linear(uint32_t t, uint16_t b, int c, uint32_t d);
    float quadratic(float t, float b, float c, float d, boolean easeIn, boolean easeOut);
    float exponential(float t, float b, float c, float d, boolean easeIn, boolean easeOut);
    
    float sinus(float t, float b, float c, float d, boolean easeIn, boolean easeOut);
    
    float circular(float t, float b, float c, float d, boolean easeIn, boolean easeOut);
    float distance( float x1, float y1, float x2, float y2 );
    float radian( float degrees );
    float degree( float radians );
};

extern CalculateClass Calculate;

#endif

