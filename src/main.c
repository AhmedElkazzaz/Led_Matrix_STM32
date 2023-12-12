#include <stdio.h>
#include <STD_TYPES.h>

#include <RCC_interface.h>
#include <SYSTICK_interface.h>
#include <LED_MATRIX_interface.h>
#include "diag/Trace.h"

void shiftArrayLeft(u8 *array,u8 size)
{

	        u8 i, first;
	        //Stores the first element of the array
	        first = array[0];

	        for(i = 0; i <size-1; i++)
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
		  shiftArrayLeft(nameArray,30);
		  //display every character for around one second then shift
	  	  for(int c=0;c<62;c++)
	 		LEDMRX_voidDisplay(dataDisplay);
	  }
    }



// ----------------------------------------------------------------------------
