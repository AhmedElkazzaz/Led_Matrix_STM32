/*************************************************************************/
/* Author        : Ahmed Elkazzaz                                        */
/* File          : RCC_program.c                                         */
/* Date          :                                                       */
/* Version       : V01                                                   */
/*************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"  




void MRCC_VidInit( void ){

	u32 LOC_u32TimeOut = 0;

	#if   RCC_CLOCK_TYPE == RCC_HSI

		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* HSI Selected As A System Clock */
		MRCC->CFGR=0x00000000;
		/* Bit 0 -> Enable The HSI Clock */
		SET_BIT( MRCC->CR   , 0  );

		/* Bit 1 -> Checking While The HSI Clock Is Stable */
		while( ( ( GET_BIT( MRCC->CR , 1 ) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
		if( LOC_u32TimeOut >= 100000 ){ /*TimeOut*/ }

	#elif RCC_CLOCK_TYPE == RCC_HSE_RC

		/* The HSEBYP Can Be Written Only When HSE Oscilator Is Disabled */
		/* HSE Clock Disabled */
		CLR_BIT( MRCC->CR   , 16 );

		/* BIT 18 -> To Select HSE BYPASS */
		/* HSEBYPASS Clock Enable */
		SET_BIT( MRCC->CR , 18 );

		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* HSE Selected As A System Clock */
		MRCC->CFGR=0x00000001;

		/* Bit 16 -> Enable The HSE Clock */
		SET_BIT( MRCC->CR   , 16 );

		/* Bit 17 -> Checking While The HSE Clock Is Stable */
		while( ( ( GET_BIT( MRCC->CR , 17 ) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
		if( LOC_u32TimeOut >= 100000 ){ /*TimeOut*/ }

	#elif RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL


		/* Bit 16 -> Enable The HSE Clock */
		SET_BIT( MRCC->CR   , 16 );
		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
				/* HSE Selected As A System Clock */
				MRCC->CFGR=0x00000001;
		/* Bit 17 -> Checking While The HSE Clock Is Stable */
		while( ( ( GET_BIT( MRCC->CR , 17 ) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
		if( LOC_u32TimeOut >= 100000 ){ /*TimeOut*/ }

	#elif RCC_CLOCK_TYPE == RCC_PLL

		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* PLL Selected As A System Clock */



		/*The Start Of Nested #IF*/
		#if RCC_PLL_SOURCE == PLL_HSI_DIVIDED_BY_2

			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSI Divided By 2 */
			CLR_BIT( MRCC->CFGR , 16 );

		#elif RCC_PLL_SOURCE == PLL_HSE

			/* Bit 16 -> Enable The HSE Clock */
			SET_BIT( MRCC->CR   , 16 );

			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT( MRCC->CFGR , 16 );

			/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Not Divided */
			CLR_BIT( MRCC->CFGR , 17 );

		#elif RCC_PLL_SOURCE == PLL_HSE_DIVIDED_BY_2

			/* Bit 16 -> Enable The HSE Clock */
			SET_BIT( MRCC->CR   , 16 );

			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT( MRCC->CFGR , 16 );

			/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Divided By Two */
			SET_BIT( MRCC->CFGR , 17 );

			/*The End Of Nested IF*/
		#endif

		/* PLL Clock Enable */
		SET_BIT( MRCC->CR , 24 );

		/* Wait Until PLL Ready Flag Set */
		while( ( ( GET_BIT( MRCC->CR , 25 ) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
		if( LOC_u32TimeOut >= 100000 ){ /*TimeOut*/ }



	#else

		#error " Wrong Clock System Type Configuration "

	/* The Close Of Big If */
	#endif

	/* For Clock Security System */
	#if CLOCK_SECURITY_SYSTEM == ENABLE_CLOCK_SECURITY_SYSTEM

		SET_BIT( MRCC->CR , 19 );

	#elif CLOCK_SECURITY_SYSTEM == DISABLE_CLOCK_SECURITY_SYSTEM

		CLR_BIT( MRCC->CR , 19 );

	#else

		#warning " Wrong Clock Security System Configuration Choice "

	#endif

}

void MRCC_VidEnablePeripheralClock( u8 Copy_u8PeripheralBus , u8 Copy_u8Peripheral ){


		switch( Copy_u8PeripheralBus ){

			case RCC_AHB_BUS  : SET_BIT( MRCC->AHBENR  , Copy_u8Peripheral ); break;
			case RCC_APB1_BUS :	SET_BIT( MRCC->APB1ENR , Copy_u8Peripheral ); break;
			case RCC_APB2_BUS : SET_BIT( MRCC->APB2ENR , Copy_u8Peripheral ); break;

		}


}

void MRCC_VidDisablePeripheralClock( u8 Copy_u8PeripheralBus , u8 Copy_u8Peripheral ){

		switch( Copy_u8PeripheralBus ){

			case RCC_AHB_BUS  : CLR_BIT( MRCC->AHBENR  , Copy_u8Peripheral ); break;
			case RCC_APB1_BUS :	CLR_BIT( MRCC->APB1ENR , Copy_u8Peripheral ); break;
			case RCC_APB2_BUS : CLR_BIT( MRCC->APB2ENR , Copy_u8Peripheral ); break;

		}
}
