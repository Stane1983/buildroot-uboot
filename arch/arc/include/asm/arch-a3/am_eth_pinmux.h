#ifndef ETH_PINMUX_HEADER_
#define ETH_PINMUX_HEADER_

/*
"RMII_MDIOREG2[8]"
"RMII_MDCREG2[9]"
"RMII_TX_DATA0REG2[10]"
"RMII_TX_DATA1REG2[11]"
"RMII_TX_ENREG2[12]"
"RMII_RX_DATA0REG2[13]"
"RMII_RX_DATA1REG2[14]"
"RMII_RX_CRS_DVREG2[15]"
"RMII_RX_ERRREG2[16]"
Bank0_GPIOC3-C11
*/
#define ETH_BANK0_GPIOC3_C11		0
#define ETH_BANK0_REG1			2
#define ETH_BANK0_REG1_VAL		(0x1ff<<8)
/*
"RMII_MDIOREG4[10]"
"RMII_MDCREG4[9]"
"RMII_TX_DATA0REG4[8]"
"RMII_TX_DATA1REG4[7]"
"RMII_TX_ENREG4[6]"
"RMII_RX_DATA0REG4[5]"
"RMII_RX_DATA1REG4[4]"
"RMII_RX_CRS_DVREG4[3]"
"RMII_RX_ERRREG4[2]"
Bank1_GPIOD0-D8
*/
#define ETH_BANK1_GPIOD0_D8		1
#define ETH_BANK1_REG1			4
#define ETH_BANK1_REG1_VAL		(0x1ff<<2)

#define ETH_CLK_IN_GPIOC2_REG2_18	0
#define ETH_CLK_IN_GPIOD9_REG4_0	1

#define ETH_CLK_OUT_GPIOC2_REG2_17	2
#define ETH_CLK_OUT_GPIOD9_REG4_1	3

#endif

