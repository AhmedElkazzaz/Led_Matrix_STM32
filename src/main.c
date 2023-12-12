/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <STD_TYPES.h>

#include <RCC_interface.h>
#include <SYSTICK_interface.h>
#include <LED_MATRIX_interface.h>
#include "diag/Trace.h"

void shiftArrayLeft(u8 *array)
{

	        u8 i, first;
	        //Stores the first element of the array
	        first = array[0];

	        for(i = 0; i <29; i++)
	        {
	            //Shift element of array by one
	        	array[i] = array[i+1];
	        }
	        //First element of array will be added to the end
	        array[i] = first;

}

// display my name "Ahmed"
u8 nameArray[30]= { 0, 124, 18, 18, 124, 0, 0, 126,
				   8, 8, 126, 0, 0, 126, 4, 8,
				   4,126, 0, 0, 126, 74, 74, 0,
				   0, 126, 66, 36, 24, 0};

void main (void)
{
	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock(RCC_APB2_BUS,2);
	MRCC_VidEnablePeripheralClock(RCC_APB2_BUS,3);
	MSTK_VidInit();
	LEDMRX_voidInit();
	 u8 dataDisplay[8];
  while (1)
    {

		  for(int j=0;j<8;j++)
		  {
			 dataDisplay[j]=nameArray[j];
		  }
		  shiftArrayLeft(nameArray);
		  //display every character for around one second then shift
	  	  for(int c=0;c<62;c++)
	 		LEDMRX_voidDisplay(dataDisplay);
	  }
    }



// ----------------------------------------------------------------------------
