/*************************************************************************/
/***************      Name 		:  Ahmed Abdelhady  	******************/
/***************      Date 		:  14 / 12 / 2022  		******************/
/***************      SWC 		:  DIO          		******************/
/***************      Version 	:  1.0          		******************/
/*************************************************************************/
/* LIB Layer */

#include "../Includes/LIB/STD_Types.h"
#include "../Includes/LIB/BIT_Math.h"

/* MCAL Layer */
#include "../Includes/MCAL/DIO/DIO_Config.h"
#include "../Includes/MCAL/DIO/DIO_Interface.h"
#include "../Includes/MCAL/DIO/DIO_Private.h"

/***************************************************************/
/***************************************************************/

/******************************************************************************/
/* Function: DIO_voidInit                        				 			  */
/* I/P Parameters: void		  												  */
/* Returns: void			                                				      */
/* Desc:This Function Sets the direction of a All pins before start			  */
/******************************************************************************/
/* Options																	  */
/******************************************************************************/
/* A_u8Port     : DIO_u8_PORTA  - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD  */
/* A_u8Pin      : PIN0 ... PIN7       			                          	  */
/* A_u8Direction: DIO_u8_INPUT - DIO_u8_OUTPUT                                */
/* A_u8Value	: I/P--> DIO_u8_INPUT_FLOATING - DIO_u8_INPUT_PULLUP 		  */
/*           	  O/P--> DIO_u8_OUTPUT_HIGH    - DIO_u8_OUTPUT_LOW            */
/******************************************************************************/

void 	DIO_voidInit 						(void)
{
	/* Set PORTA Pins Dierection */
	DIO_u8_DDRA_REG = Conc(	DIO_u8_PA7_INTIAL_DIERCTION , DIO_u8_PA6_INTIAL_DIERCTION , DIO_u8_PA5_INTIAL_DIERCTION , DIO_u8_PA4_INTIAL_DIERCTION ,
			DIO_u8_PA3_INTIAL_DIERCTION , DIO_u8_PA2_INTIAL_DIERCTION , DIO_u8_PA1_INTIAL_DIERCTION , DIO_u8_PA0_INTIAL_DIERCTION) ;

	/* Set PORTB Pins Dierection */
	DIO_u8_DDRB_REG = Conc(	DIO_u8_PB7_INTIAL_DIERCTION , DIO_u8_PB6_INTIAL_DIERCTION , DIO_u8_PB5_INTIAL_DIERCTION , DIO_u8_PB4_INTIAL_DIERCTION ,
			DIO_u8_PB3_INTIAL_DIERCTION , DIO_u8_PB2_INTIAL_DIERCTION , DIO_u8_PB1_INTIAL_DIERCTION , DIO_u8_PB0_INTIAL_DIERCTION) ;

	/* Set PORTC Pins Dierection */
	DIO_u8_DDRC_REG = Conc(	DIO_u8_PC7_INTIAL_DIERCTION , DIO_u8_PC6_INTIAL_DIERCTION , DIO_u8_PC5_INTIAL_DIERCTION , DIO_u8_PC4_INTIAL_DIERCTION ,
			DIO_u8_PC3_INTIAL_DIERCTION , DIO_u8_PC2_INTIAL_DIERCTION , DIO_u8_PC1_INTIAL_DIERCTION , DIO_u8_PC0_INTIAL_DIERCTION) ;

	/* Set PORTD Pins Dierection */
	DIO_u8_DDRD_REG = Conc(	DIO_u8_PD7_INTIAL_DIERCTION , DIO_u8_PD6_INTIAL_DIERCTION , DIO_u8_PD5_INTIAL_DIERCTION , DIO_u8_PD4_INTIAL_DIERCTION ,
			DIO_u8_PD3_INTIAL_DIERCTION , DIO_u8_PD2_INTIAL_DIERCTION , DIO_u8_PD1_INTIAL_DIERCTION , DIO_u8_PD0_INTIAL_DIERCTION) ;

	/* Set PORTA Pins Value */
	DIO_u8_PORTA_REG = Conc(DIO_u8_PA7_INTIAL_VALUE , DIO_u8_PA6_INTIAL_VALUE , DIO_u8_PA5_INTIAL_VALUE , DIO_u8_PA4_INTIAL_VALUE , 
			DIO_u8_PA3_INTIAL_VALUE , DIO_u8_PA2_INTIAL_VALUE , DIO_u8_PA1_INTIAL_VALUE ,DIO_u8_PA0_INTIAL_VALUE ) ;

	/* Set PORTB Pins Value */
	DIO_u8_PORTB_REG = Conc(DIO_u8_PB7_INTIAL_VALUE , DIO_u8_PB6_INTIAL_VALUE , DIO_u8_PB5_INTIAL_VALUE , DIO_u8_PB4_INTIAL_VALUE , 
			DIO_u8_PB3_INTIAL_VALUE , DIO_u8_PB2_INTIAL_VALUE , DIO_u8_PB1_INTIAL_VALUE , DIO_u8_PB0_INTIAL_VALUE ) ;

	/* Set PORTC Pins Value */
	DIO_u8_PORTC_REG = Conc(DIO_u8_PC7_INTIAL_VALUE , DIO_u8_PC6_INTIAL_VALUE , DIO_u8_PC5_INTIAL_VALUE , DIO_u8_PC4_INTIAL_VALUE , 
			DIO_u8_PC3_INTIAL_VALUE , DIO_u8_PC2_INTIAL_VALUE , DIO_u8_PC1_INTIAL_VALUE , DIO_u8_PC0_INTIAL_VALUE ) ;

	/* Set PORTD Pins Value */
	DIO_u8_PORTD_REG = Conc(DIO_u8_PD7_INTIAL_VALUE , DIO_u8_PD6_INTIAL_VALUE , DIO_u8_PD5_INTIAL_VALUE , DIO_u8_PD4_INTIAL_VALUE , 											
			DIO_u8_PD3_INTIAL_VALUE , DIO_u8_PD2_INTIAL_VALUE , DIO_u8_PD1_INTIAL_VALUE , DIO_u8_PD0_INTIAL_VALUE ) ;
}


/***************************************************************/
/***************************************************************/

/******************************************************************************/
/* Function: DIO_voidSetPinDirection                        				  */
/* I/P Parameters: Copy_u8PortId,  Copy_u8PinId, Copy_u8PinDirection		  */
/* Returns: u8			                                				      */
/* Desc:This Function Sets the direction of a given pin				       	  */
/******************************************************************************/
/* Options																	  */
/******************************************************************************/
/* A_u8Port     : DIO_u8_PORTA  - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD  */
/* A_u8Pin      : PIN0 ... PIN7       			                          	  */
/* A_u8Direction: DIO_u8_INPUT - DIO_u8_OUTPUT                        		  */
/******************************************************************************/

u8 DIO_u8SetPinDierection  (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Check Input Validation */
	if(Copy_u8PinId<=DIO_u8_PIN7)
	{
		switch(Copy_u8PortId)
		{

		case DIO_u8_PORTA :
		{
			switch(Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT 	: 	SET_BIT(DIO_u8_DDRA_REG , Copy_u8PinId); 	break;
			case DIO_u8_INPUT 	:  	CLR_BIT(DIO_u8_DDRA_REG , Copy_u8PinId); 	break;
			default 			:   Local_u8ErrorState = STD_TYPES_NOK;			break;
			}

			break ;

		}

		{
		case DIO_u8_PORTB :

			switch(Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT 	: 	SET_BIT(DIO_u8_DDRB_REG , Copy_u8PinId); 	break;
			case DIO_u8_INPUT 	:  	CLR_BIT(DIO_u8_DDRB_REG , Copy_u8PinId); 	break;
			default 			:   Local_u8ErrorState = STD_TYPES_NOK;			break;
			}

			break ;

		}

		{
		case DIO_u8_PORTC :

			switch(Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT 	: 	SET_BIT(DIO_u8_DDRC_REG , Copy_u8PinId); 	break;
			case DIO_u8_INPUT 	:  	CLR_BIT(DIO_u8_DDRC_REG , Copy_u8PinId); 	break;
			default 			:   Local_u8ErrorState = STD_TYPES_NOK;			break;
			}

			break;

		}

		{
		case DIO_u8_PORTD :

			switch(Copy_u8PinDirection)
			{
			case DIO_u8_OUTPUT 	: 	SET_BIT(DIO_u8_DDRD_REG , Copy_u8PinId); 	break;
			case DIO_u8_INPUT 	:  	CLR_BIT(DIO_u8_DDRD_REG , Copy_u8PinId); 	break;
			default 			:   Local_u8ErrorState = STD_TYPES_NOK ;		break;
			}

			break;

		}

		{
		default :
			Local_u8ErrorState = STD_TYPES_NOK;

			break;

		}

		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}


	return Local_u8ErrorState ;

}

/***************************************************************/
/***************************************************************/

/******************************************************************************/
/* Function: DIO_u8SetPinValue                        				  		  */
/* I/P Parameters: Copy_u8PortId,  Copy_u8PinId, Copy_u8PinValue		  	  */
/* Returns: u8			                                				      */
/* Desc:This Function Sets the value of a given pin in case of O/P			  */
/* 		This Function Sets PULLUP state in case of I/P					      */
/******************************************************************************/
/* Options																	  */
/******************************************************************************/
/* A_u8Port     : DIO_u8_PORTA  - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD  */
/* A_u8Pin      : PIN0 ... PIN7       			                          	  */
/* A_u8Value:I/P--> DIO_u8_INPUT_FLOATING - DIO_u8_INPUT_PULLUP 			  */
/*           O/P--> DIO_u8_OUTPUT_HIGH    - DIO_u8_OUTPUT_LOW             	  */
/******************************************************************************/

u8 DIO_u8SetPinValue         (u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Check Input Validation */
	if(Copy_u8PinId<=DIO_u8_PIN7)
	{
		switch(Copy_u8PortId)
		{

		case DIO_u8_PORTA :
		{
			switch(Copy_u8PinValue)
			{
			case DIO_u8_HIGH 	: 	SET_BIT(DIO_u8_PORTA_REG , Copy_u8PinId); 	break;
			case DIO_u8_LOW 	:  	CLR_BIT(DIO_u8_PORTA_REG , Copy_u8PinId); 	break;
			default 			:   Local_u8ErrorState = STD_TYPES_NOK;			break;
			}

			break ;

		}

		{
		case DIO_u8_PORTB :

			switch(Copy_u8PinValue)
			{
			case DIO_u8_HIGH 	: 	SET_BIT(DIO_u8_PORTB_REG , Copy_u8PinId); 	break;
			case DIO_u8_LOW 	:  	CLR_BIT(DIO_u8_PORTB_REG , Copy_u8PinId); 	break;
			default 			:   Local_u8ErrorState = STD_TYPES_NOK;			break;
			}

			break ;

		}

		{
		case DIO_u8_PORTC :

			switch(Copy_u8PinValue)
			{
			case DIO_u8_OUTPUT 	: 	SET_BIT(DIO_u8_PORTC_REG , Copy_u8PinId); 	break;
			case DIO_u8_INPUT 	:  	CLR_BIT(DIO_u8_PORTC_REG , Copy_u8PinId); 	break;
			default 			:   Local_u8ErrorState = STD_TYPES_NOK;			break;
			}

			break;

		}

		{
		case DIO_u8_PORTD :

			switch(Copy_u8PinValue)
			{
			case DIO_u8_OUTPUT 	: 	SET_BIT(DIO_u8_PORTD_REG , Copy_u8PinId); 	break;
			case DIO_u8_INPUT 	:  	CLR_BIT(DIO_u8_PORTD_REG , Copy_u8PinId); 	break;
			default 			:   Local_u8ErrorState = STD_TYPES_NOK;			break;
			}

			break;

		}

		{
		default :
			Local_u8ErrorState = STD_TYPES_NOK ;

			break;

		}

		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState;

}

/***************************************************************/	
/***************************************************************/

/******************************************************************************/
/* Function: DIO_u8GetPinValue                        				  		  */
/* I/P Parameters: Copy_u8PortId,  Copy_u8PinId, Copy_Pu8ReturnedPinValue	  */
/* Returns: u8			                                				      */
/* Desc:This Function Gets the value of a given pin 			              */
/******************************************************************************/
/* Options																	  */
/******************************************************************************/
/* A_u8Port     : DIO_u8_PORTA  - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD  */
/* A_u8Pin      : PIN0 ... PIN7       			                          	  */
/* A_u8Value	: DIO_u8_HIGH    - DIO_u8_LOW             	  				  */
/******************************************************************************/

u8 DIO_u8GetPinValue         (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 * Copy_Pu8ReturnedPinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8PinValue = DIO_u8_LOW;
	/* Check Input Validation */
	if((Copy_u8PortId<=DIO_u8_PORTD) && (Copy_u8PinId<=DIO_u8_PIN7) && (Copy_Pu8ReturnedPinValue != NULL))
	{
		switch(Copy_u8PortId)
		{
		{
		case DIO_u8_PORTA 	:	Local_u8PinValue = GET_BIT(DIO_u8_PINA_REG , Copy_u8PinId);

		if(Local_u8PinValue == 0)
		{
			* Copy_Pu8ReturnedPinValue = DIO_u8_LOW;
		}
		else
		{
			* Copy_Pu8ReturnedPinValue = DIO_u8_HIGH;
		}

		break;

		}

		{
		case DIO_u8_PORTB 	:	Local_u8PinValue = GET_BIT(DIO_u8_PINB_REG , Copy_u8PinId);

		if(Local_u8PinValue == 0)
		{
			* Copy_Pu8ReturnedPinValue = DIO_u8_LOW;
		}
		else
		{
			* Copy_Pu8ReturnedPinValue = DIO_u8_HIGH;
		}

		break;

		}

		{
		case DIO_u8_PORTC 	:	Local_u8PinValue = GET_BIT(DIO_u8_PINC_REG , Copy_u8PinId);

		if(Local_u8PinValue == 0)
		{
			* Copy_Pu8ReturnedPinValue = DIO_u8_LOW;
		}
		else
		{
			* Copy_Pu8ReturnedPinValue = DIO_u8_HIGH;
		}

		break;

		}

		{
		case DIO_u8_PORTD 	:	Local_u8PinValue = GET_BIT(DIO_u8_PIND_REG , Copy_u8PinId);

		if(Local_u8PinValue == 0)
		{
			* Copy_Pu8ReturnedPinValue = DIO_u8_LOW;
		}
		else
		{
			* Copy_Pu8ReturnedPinValue = DIO_u8_HIGH;
		}

		break;

		}

		{
		default :

			Local_u8ErrorState = STD_TYPES_NOK ;

			break;

		}

		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}

	return Local_u8ErrorState;

}

/***************************************************************/
/***************************************************************/

/******************************************************************************/
/* Function: DIO_u8SetPortDierection                        				  */
/* I/P Parameters: Copy_u8PortId , Copy_u8PortDirection		  				  */
/* Returns: u8			                                				      */
/* Desc:This Function Sets the direction of a PORT				       	  	  */
/******************************************************************************/
/* Options																	  */
/******************************************************************************/
/* A_u8Port     : DIO_u8_PORTA  - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD  */
/* A_u8Pin      : PIN0 ... PIN7       			                          	  */
/* A_u8Direction: DIO_u8_INPUT - DIO_u8_OUTPUT                        		  */
/******************************************************************************/

u8 DIO_u8SetAllPortDierection  (u8 Copy_u8PortId,u8 Copy_u8PortDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	switch(Copy_u8PortId)
	{
	{
	case DIO_u8_PORTA :
		switch(Copy_u8PortDirection)
		{
		case DIO_u8_OUTPUT 	: SET_REG(DIO_u8_DDRA_REG);	 			break;
		case DIO_u8_INPUT 	: CLR_REG(DIO_u8_DDRA_REG);				break;
		default 			: Local_u8ErrorState = STD_TYPES_NOK;	break;
		}

		break ;

	}

	{
	case DIO_u8_PORTB :

		switch(Copy_u8PortDirection)
		{
		case DIO_u8_OUTPUT 	: SET_REG(DIO_u8_DDRB_REG);	 			break;
		case DIO_u8_INPUT 	: CLR_REG(DIO_u8_DDRB_REG);				break;
		default 			: Local_u8ErrorState = STD_TYPES_NOK;	break;
		}

		break ;

	}

	{
	case DIO_u8_PORTC :

		switch(Copy_u8PortDirection)
		{
		case DIO_u8_OUTPUT 	: SET_REG(DIO_u8_DDRC_REG);	 			break;
		case DIO_u8_INPUT 	: CLR_REG(DIO_u8_DDRC_REG);				break;
		default 			: Local_u8ErrorState = STD_TYPES_NOK;	break;
		}

		break;

	}

	{
	case DIO_u8_PORTD :

		switch(Copy_u8PortDirection)
		{
		case DIO_u8_OUTPUT 	: SET_REG(DIO_u8_DDRD_REG);	 			break;
		case DIO_u8_INPUT 	: CLR_REG(DIO_u8_DDRD_REG);				break;
		default 			: Local_u8ErrorState = STD_TYPES_NOK;	break;
		}

		break;

	}

	{
	default : 
		Local_u8ErrorState = STD_TYPES_NOK;

		break;

	}

	}


	return Local_u8ErrorState ;

}

/***************************************************************/
/***************************************************************/
u8  DIO_u8SetPortDirection		(u8 Copy_u8PortId , u8 Copy_u8PortDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	switch(Copy_u8PortId)
	{
	case DIO_u8_PORTA : DIO_u8_DDRA_REG = Copy_u8PortDirection ; break;

	case DIO_u8_PORTB : DIO_u8_DDRB_REG = Copy_u8PortDirection ; break;

	case DIO_u8_PORTC : DIO_u8_DDRC_REG = Copy_u8PortDirection ; break;

	case DIO_u8_PORTD : DIO_u8_DDRD_REG = Copy_u8PortDirection ; break;

	default			  : Local_u8ErrorState = STD_TYPES_NOK;      break;

	}
	return Local_u8ErrorState ;
}
/***************************************************************/
/***************************************************************/

/******************************************************************************/
/* Function: DIO_u8SetPortValue                        				  		  */
/* I/P Parameters: Copy_u8PortId , Copy_u8PortValue		  	  				  */
/* Returns: u8			                                				      */
/* Desc:This Function Sets the value of a given PORT in case of O/P			  */
/* 		This Function Sets PULLUP state in case of I/P					      */
/******************************************************************************/
/* Options																	  */
/******************************************************************************/
/* A_u8Port     : DIO_u8_PORTA  - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD  */
/* A_u8Pin      : PIN0 ... PIN7       			                          	  */
/* A_u8Value:I/P--> DIO_u8_INPUT_FLOATING - DIO_u8_INPUT_PULLUP 			  */
/*           O/P--> DIO_u8_OUTPUT_HIGH    - DIO_u8_OUTPUT_LOW             	  */
/******************************************************************************/

u8 DIO_u8SetPortValue  (u8 Copy_u8PortId,u8 Copy_u8PortValue)
{
	u8 	Local_u8ErrorState 	= STD_TYPES_OK;

	switch(Copy_u8PortId)
	{

	case DIO_u8_PORTA :  DIO_u8_PORTA_REG 	= 	Copy_u8PortValue; break;

	case DIO_u8_PORTB :  DIO_u8_PORTB_REG 	= 	Copy_u8PortValue; break;

	case DIO_u8_PORTC :	 DIO_u8_PORTC_REG 	= 	Copy_u8PortValue; break;

	case DIO_u8_PORTD :	 DIO_u8_PORTD_REG 	= 	Copy_u8PortValue; break;

	default           :	 Local_u8ErrorState =  STD_TYPES_NOK ;	  break;

	}

	return Local_u8ErrorState;

}

/***************************************************************/
/***************************************************************/

/******************************************************************************/
/* Function: DIO_u8GetPortValue                        				  		  */
/* I/P Parameters: Copy_u8PortId , Copy_Pu8ReturnedPortValue	  			  */
/* Returns: u8			                                				      */
/* Desc:This Function Gets the value of a given PORT 			              */
/******************************************************************************/
/* Options																	  */
/******************************************************************************/
/* A_u8Port     : DIO_u8_PORTA  - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD  */
/* A_u8Pin      : PIN0 ... PIN7       			                          	  */
/* A_u8Value	: DIO_u8_HIGH    - DIO_u8_LOW             	  				  */
/******************************************************************************/

u8 DIO_u8GetPortValue         (u8 Copy_u8PortId,u8 * Copy_Pu8ReturnedPortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Check Input Validation */
	if(Copy_Pu8ReturnedPortValue != NULL)
	{
		switch(Copy_u8PortId)
		{

		case DIO_u8_PORTA :	* Copy_Pu8ReturnedPortValue = DIO_u8_PINA_REG ; break ;

		case DIO_u8_PORTB :	* Copy_Pu8ReturnedPortValue = DIO_u8_PINB_REG ; break ;

		case DIO_u8_PORTC :	* Copy_Pu8ReturnedPortValue = DIO_u8_PINC_REG ; break ;

		case DIO_u8_PORTD :	* Copy_Pu8ReturnedPortValue = DIO_u8_PIND_REG ; break ;

		default : Local_u8ErrorState = STD_TYPES_NOK;												break;

		}	
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}


/***************************************************************/
/***************************************************************/

/******************************************************************************/
/* Function: DIO_u8TogglePin                        				  		  */
/* I/P Parameters: Copy_u8PortId , Copy_u8PinId	  			  				  */
/* Returns: u8			                                				      */
/* Desc:This Function Toggle the value of a given Pin 			              */
/******************************************************************************/
/* Options																	  */
/******************************************************************************/
/* A_u8Port     : DIO_u8_PORTA  - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD  */
/* A_u8Pin      : PIN0 ... PIN7       			                          	  */
/* A_u8Value	: DIO_u8_HIGH    - DIO_u8_LOW             	  				  */
/******************************************************************************/

u8  DIO_u8TogglePinValue				(u8 Copy_u8PortId , u8 Copy_u8PinId )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_u8PinId <= DIO_u8_PIN7)
	{
		switch(Copy_u8PortId)
		{
		case DIO_u8_PORTA :TOG_BIT(DIO_u8_PORTA_REG , Copy_u8PinId);    break ;

		case DIO_u8_PORTB :TOG_BIT(DIO_u8_PORTB_REG , Copy_u8PinId);    break ;

		case DIO_u8_PORTC :TOG_BIT(DIO_u8_PORTC_REG , Copy_u8PinId);    break ;

		case DIO_u8_PORTD :TOG_BIT(DIO_u8_PORTD_REG , Copy_u8PinId);    break ;

		default : Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}










