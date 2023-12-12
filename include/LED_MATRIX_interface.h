
#ifndef LED_MATRIX_INTERFACE_H_
#define LED_MATRIX_INTERFACE_H_


void LEDMRX_voidInit(void) ;

/* Row values */
void LEDMRX_voidDisplay(u8 *Copy_u8Data);

void LEDMRX_voidDisplayChar(u8 ch );

#endif //  __LEDMRX_INTERFACE_H__


