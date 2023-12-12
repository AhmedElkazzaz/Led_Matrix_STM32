#include"BIT_MATH.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <LED_MATRIX_config.h>
#include <LED_MATRIX_interface.h>


#include "GPIO_INTERFACE.h"
#include "DELAY_interface.h"

static void LEDMRX_voidDisableAllCol(void) ;
static void LEDMRX_voidSetRowData(u8) ;
void LEDMRX_voidInit(void)
{
	MGPIO_VidSetPinDirection(LEDMRX_ROW_0_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW_1_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW_2_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW_3_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW_4_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW_5_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW_6_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_ROW_7_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL_0_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL_1_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL_2_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL_3_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL_4_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL_5_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL_6_PIN , OUTPUT_SPEED_2MHZ_PP ) ;
	MGPIO_VidSetPinDirection(LEDMRX_COL_7_PIN , OUTPUT_SPEED_2MHZ_PP  ) ;
}
void LEDMRX_voidDisplay(u8 *Copy_u8Data)
{
    /*        0           */
    /* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 0 */
	MGPIO_VidSetPinValue(LEDMRX_COL_0_PIN , LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[0]);
	/* Delay 2ms */
    _delay_ms(2) ;

	/*        1           */
    /* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 1 */
	MGPIO_VidSetPinValue(LEDMRX_COL_1_PIN , LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[1]);
	/* Delay 2ms */
    _delay_ms(2) ;

	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 2 */
	MGPIO_VidSetPinValue(LEDMRX_COL_2_PIN , LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[2]);
	/* Delay 2ms */
    _delay_ms(2) ;

	/*        3           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 3 */
	MGPIO_VidSetPinValue(LEDMRX_COL_3_PIN , LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[3]);
	/* Delay 2ms */
    _delay_ms(2) ;

	/*        4           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 4 */
	MGPIO_VidSetPinValue(LEDMRX_COL_4_PIN , LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[4]);
	/* Delay 2ms */
    _delay_ms(2) ;

	/*        5           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 0 */
	MGPIO_VidSetPinValue(LEDMRX_COL_5_PIN , LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[5]);
	/* Delay 2ms */
    _delay_ms(2) ;

	/*        6           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 6 */
	MGPIO_VidSetPinValue(LEDMRX_COL_6_PIN , LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[6]);
	/* Delay 2ms */
	_delay_ms(2) ;

	/*        7           */
	/* disable all columns */
    LEDMRX_voidDisableAllCol() ;
	/* Enalbe Column 7 */
	MGPIO_VidSetPinValue(LEDMRX_COL_7_PIN , LOW) ;
	/* Set Row Data */
    LEDMRX_voidSetRowData(Copy_u8Data[7]);
	/* Delay 2ms */
	_delay_ms(2) ;
}
static void LEDMRX_voidDisableAllCol(void)
{
		/* disable all columns */
	MGPIO_VidSetPinValue(LEDMRX_COL_0_PIN , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL_1_PIN , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL_2_PIN , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL_3_PIN , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL_4_PIN , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL_5_PIN , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL_6_PIN , HIGH) ;
	MGPIO_VidSetPinValue(LEDMRX_COL_7_PIN , HIGH) ;
}
static void LEDMRX_voidSetRowData(u8 Copy_u8Data)
{
	MGPIO_VidSetPinValue(LEDMRX_ROW_0_PIN , GET_BIT(Copy_u8Data,0)) ;
    MGPIO_VidSetPinValue(LEDMRX_ROW_1_PIN , GET_BIT(Copy_u8Data,1)) ;
    MGPIO_VidSetPinValue(LEDMRX_ROW_2_PIN , GET_BIT(Copy_u8Data,2)) ;
    MGPIO_VidSetPinValue(LEDMRX_ROW_3_PIN , GET_BIT(Copy_u8Data,3)) ;
    MGPIO_VidSetPinValue(LEDMRX_ROW_4_PIN , GET_BIT(Copy_u8Data,4)) ;
    MGPIO_VidSetPinValue(LEDMRX_ROW_5_PIN , GET_BIT(Copy_u8Data,5)) ;
    MGPIO_VidSetPinValue(LEDMRX_ROW_6_PIN , GET_BIT(Copy_u8Data,6)) ;
    MGPIO_VidSetPinValue(LEDMRX_ROW_7_PIN , GET_BIT(Copy_u8Data,7)) ;
}
