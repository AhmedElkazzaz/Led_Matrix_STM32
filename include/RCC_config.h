

#ifndef RCC_CONFG_H_
#define RCC_CONFG_H_

/*******************************************************************/
/*                                                                 */
/*                       ClockType Maybe :                         */
/*                       1-RCC_HSI                                 */
/*                       2-RCC_HSE_CRYSTAL                         */
/*                       2-RCC_HSE_RC                        	   */
/*                       3-RCC_PLL                                 */
/*                          *PLL_Source                            */
/*                               3.1-RCC_PLL_HSI_DIVIDED_BY_2      */
/*                               3.2-RCC_PLL_HSE                   */
/*                               3.3-RCC_PLL_HSE_DIVIDED_BY_2      */
/*                                                                 */
/*******************************************************************/

#define RCC_CLOCK_TYPE       RCC_HSE_CRYSTAL

/* note :select only  RCC_PLL_SOURCE if you have selected RCC_CLOCK_TYPE =RCC_PLL*/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_SOURCE       RCC_PLL_HSE_DIVIDED_BY_2
#endif


/* Select a value from 2:16*/
/* note :select value only  if you have selected RCC_CLOCK_TYPE = RCC_PLL*/
#define RCC_PLL_MUL_VAL     4

#define CLOCK_FACTOR     PLL_CLOCK_MULTIPLE_BY_16



#endif /* RCC_CONFG_H_ */
