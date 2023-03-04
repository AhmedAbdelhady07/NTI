#ifndef		DIO_INTERFACE_H
#define		DIO_INTERFACE_H

#define		DIO_LOW			0
#define		DIO_HIGH		1

#define		DIO_A			2
#define		DIO_B			3
#define		DIO_C			4

#define		PORTA			0
#define		PORTB			1
#define		PORTC			2

#define		PIN0			0
#define		PIN1			1
#define		PIN2			2
#define		PIN3			3
#define		PIN4			4
#define		PIN5			5
#define		PIN6			6
#define		PIN7			7
#define		PIN8			8
#define		PIN9			9
#define		PIN10			10
#define		PIN11			11
#define		PIN12			12
#define		PIN13			13
#define		PIN14			14
#define		PIN15			15

void	M_DIO_void_setPinDir(u8 PortId, u8 PinId, u8 Direction);
void	M_DIO_void_setPinVal(u8 PortId, u8 PinId, u8 Value);
void	M_DIO_void_getPinVal(u8 PortId, u8 PinId, u8 * Value);

#define		IN_ANALOG					0b0000
#define		IN_FLOATING					0b0100
#define		IN_PULL_UP_DOWN				0b1000

#define		OUT_10MHZ_PP				0b0001
#define		OUT_10MHZ_OD				0b0101
#define		OUT_10MHZ_AF_PP				0b1001
#define		OUT_10MHZ_AF_OD				0b1101

#define		OUT_2MHZ_PP					0b0010
#define		OUT_2MHZ_OD					0b0110
#define		OUT_2MHZ_AF_PP				0b1010
#define		OUT_2MHZ_AF_OD				0b1110

#define		OUT_50MHZ_PP				0b0011
#define		OUT_50MHZ_OD				0b0111
#define		OUT_50MHZ_AF_PP				0b1011
#define		OUT_50MHZ_AF_OD				0b1111


#endif
