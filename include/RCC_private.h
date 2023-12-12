

#ifndef RCC_REG_H_
#define RCC_REG_H_

/*******************************************************************/
/*                                                                 */
/*                       ClockType Maybe :                         */
/*                       1-HSI                                     */
/*                       2-HSE                                     */
/*                       3-PLL                                     */
/*                           3.1-PLL_HSI_DIVIDED_BY_2              */
/*                           3.2-PLL_HSE                           */
/*                           3.3-PLL_HSE_DIVIDED_BY_2              */
/*                       4-HSE_BYPASS                              */
/*                                                                 */
/*******************************************************************/

#define RCC_HSI                         1
#define RCC_HSE_CRYSTAL                 2
#define RCC_HSE_RC                 		3
#define RCC_PLL                         4
#define RCC_PLL_HSI_DIVIDED_BY_2        5
#define RCC_PLL_HSE_CRYSTAL             6
#define RCC_PLL_HSE_DIVIDED_BY_2        7


typedef struct{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC;

// M is Refer To MCal

#define MRCC ((volatile RCC *)0x40021000)

#endif /* RCC_REG_H_ */
