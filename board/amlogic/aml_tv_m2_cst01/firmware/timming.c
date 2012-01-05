#include <asm/arch/firm/regs.h>
#include <asm/arch/firm/reg_addr.h>

#include <asm/arch/firm/timing.h>
#include <asm/arch/firm/uart.h>
#include <memtest.h>
#include <config.h>
#include <ddr_types.h>
#ifndef FIRMWARE_IN_ONE_FILE
#define STATIC_PREFIX_DATA
#else
#define STATIC_PREFIX_DATA static
#endif
/**
    DDR default setting ,
    To compitable withe the old styles 
*/
#if !((defined DDR_CTRL))
#if PHYS_MEMORY_SIZE==0x8000000//128MB
#define DDR_CTRL 0xff22d6       //16bits mode with 
#endif
#if PHYS_MEMORY_SIZE==0x10000000//256MB 32bit mode
//#define DDR_CTRL 0xff2256       //32bits mode with 
#define DDR_CTRL 0xff22ca       //16bits mode with 
#endif

#if PHYS_MEMORY_SIZE==0x20000000//512MB 32bit mode
#define DDR_CTRL 0xff225a       //32bits mode with 
#endif
#ifndef DDR_CTRL
#error
#endif
#endif
#ifndef CONFIG_DDR_TYPE
#define CONFIG_DDR_TYPE DDR_W972GG6JB
#endif
#if CONFIG_DDR_TYPE==DDR_K4T1G164QE
STATIC_PREFIX_DATA struct ddr_set __ddr_setting __attribute__((section(".setting")))
={
                    .cl             =   6,
                    .t_faw          =  20,
                    .t_mrd          =   2,
                    .t_1us_pck      = 312,
                    .t_100ns_pck    =  32,
                    .t_init_us      = 511,
                    .t_ras          =  16,
                    .t_rc           =  23,
                    .t_rcd          =   6,
                    .t_refi_100ns   =  78,
                    .t_rfc          =  80,
                    .t_rp           =   6,
                    .t_rrd          =   4,
                    .t_rtp          =   3,
                    .t_wr           =   6,
                    .t_wtr          =   4,
                    .t_xp           =   2,
                    .t_xsrd         =   0,   // init to 0 so that if only one of them is defined, this is chosen
                    .t_xsnr         =   0,
                    .t_exsr         = 200,
                    .t_al           =   0,   // Additive Latency
                    .t_clr          =   6,   // cas_latency for DDR2 (nclk cycles)
                    .t_dqs          =   2,   // distance between data phases to different ranks
                    .pad            =   0,
                    .ddr_ctrl       =   DDR_CTRL,
                    .ddr_pll_cntl   =   0x120234,//312
}
;
#endif
#if DDR_W972GG6JB==CONFIG_DDR_TYPE
STATIC_PREFIX_DATA struct ddr_set __ddr_setting __attribute__((section(".setting")))
={
                    .cl             =   6,
                    .t_faw          =  20,
                    .t_mrd          =   2,
                    .t_1us_pck      = 312, //(288) (312) (360) (384)
                    .t_100ns_pck    =  32, //(29) (32) (36) (39)
                    .t_init_us      = 511,
                    .t_ras          =  18,//16->18 for windond 
                    .t_rc           =  23,
                    .t_rcd          =   6,
                    .t_refi_100ns   =  78,
                    .t_rfc          =  80,
                    .t_rp           =   6,
                    .t_rrd          =   4,
                    .t_rtp          =   3,
                    .t_wr           =   6,
                    .t_wtr          =   4,
                    .t_xp           =   2,
                    .t_xsrd         =   0,   // init to 0 so that if only one of them is defined, this is chosen
                    .t_xsnr         =   0,
                    .t_exsr         = 200,
                    .t_al           =   0,   // Additive Latency
                    .t_clr          =   6,   // cas_latency for DDR2 (nclk cycles)
                    .t_dqs          =   2,   // distance between data phases to different ranks
                    .pad            =   0,
                    .ddr_ctrl       =   DDR_CTRL,
                    .ddr_pll_cntl   =   0x120234, //384 (0x120230, //288) (0x120234, //312) (0x11021e, //360) (0x110220, //384)
}
;
#endif  //DDR_W972GG6JB
#if DDR_V59C1G02168QBP25A==CONFIG_DDR_TYPE
#if 1
//V59C1G02168QBP25A
//150M
STATIC_PREFIX_DATA struct ddr_set __ddr_setting __attribute__((section(".setting")))
={
                    .cl             =   5,
                    .t_faw          =  6,
                    .t_mrd          =   2,
                    .t_1us_pck      = 150, //(288) (312) (360) (384)
                    .t_100ns_pck    =  15, //(29) (32) (36) (39)
                    .t_init_us      = 511,
                    .t_ras          =  6,//16->18 for windond 
                    .t_rc           =  8,
                    .t_rcd          =   5,
                    .t_refi_100ns   =  78,
                    .t_rfc          =  16,
                    .t_rp           =   5,
                    .t_rrd          =   2,
                    .t_rtp          =   1,
                    .t_wr           =   2,
                    .t_wtr          =   1,
                    .t_xp           =   2,
                    .t_xsrd         =   200,   // init to 0 so that if only one of them is defined, this is chosen
                    .t_xsnr         =   0,
                    .t_exsr         = 200,
                    .t_al           =   0,   // Additive Latency
                    .t_clr          =   2,   // cas_latency for DDR2 (nclk cycles)
                    .t_dqs          =   3,   // distance between data phases to different ranks
                    .pad            =   0,
                    .ddr_ctrl       =   DDR_CTRL,
//                    .ddr_pll_cntl   =   0x120234, //384 (0x120230, //288) (0x120234, //312) (0x11021e, //360) (0x110220, //384)
                    .ddr_pll_cntl   =   0x220232, //150
}
;
#endif  //if 0

#if 0
//312M
STATIC_PREFIX_DATA struct ddr_set __ddr_setting __attribute__((section(".setting")))
={
                    .cl             =   5,
                    .t_faw          =  20,
                    .t_mrd          =   2,
                    .t_1us_pck      = 230, //(288) (312) (360) (384)
                    .t_100ns_pck    =  23, //(29) (32) (36) (39)
                    .t_init_us      = 511,
                    .t_ras          =  15,//16->18 for windond 
                    .t_rc           =  20,
                    .t_rcd          =   5,
                    .t_refi_100ns   =  78,
                    .t_rfc          =  43,
                    .t_rp           =   5,
                    .t_rrd          =   4,
                    .t_rtp          =   3,
                    .t_wr           =   5,
                    .t_wtr          =   3,
                    .t_xp           =   2,
                    .t_xsrd         =   200,   // init to 0 so that if only one of them is defined, this is chosen
                    .t_xsnr         =   0,
                    .t_exsr         = 200,
                    .t_al           =   0,   // Additive Latency
                    .t_clr          =   2,   // cas_latency for DDR2 (nclk cycles)
                    .t_dqs          =   3,   // distance between data phases to different ranks
                    .pad            =   0,
                    .ddr_ctrl       =   DDR_CTRL,
//                    .ddr_pll_cntl   =   0x120234, //384 (0x120230, //288) (0x120234, //312) (0x11021e, //360) (0x110220, //384)
//                    .ddr_pll_cntl   =   0x120234, //312
                    .ddr_pll_cntl   =   0x120673, //230
}
;
#endif  //if 0
#endif //DDR_V59C1G02168QBP25A

STATIC_PREFIX_DATA struct pll_clk_settings __plls __attribute__((section(".setting")))
={
    .sys_pll_cntl=0x232,//1200M
    .other_pll_cntl=0x00000219,//0x19*24/1=600M
//    .other_pll_cntl=0x0000042d,//0x2d*24/2=540M
    .mpeg_clk_cntl= (1 << 12) |                     // select other PLL
                   ((3- 1) << 0 ) |    // div1
//                    ((4- 1) << 0 ) |    // div1
                    (1 << 7 ) |                     // cntl_hi_mpeg_div_en, enable gating
                    (1 << 8 ) |(1<<15),                    // Connect clk81 to the PLL divider output
    .demod_pll400m_cntl=(1<<9)  | //n 1200=xtal*m/n 
            (50<<0),    //m 50*24
    .clk81=200000000,   //750/4=180M
    .a9_clk=1200000000/2,
    .spi_setting=0xea949,

    .nfc_cfg=(((0)&0xf)<<10) | (0<<9) | (0<<5) | 5,
    .sdio_cmd_clk_divide=5,
    .sdio_time_short=(250*180000)/(2*(12)),
    .uart=
        (200000000/(CONFIG_BAUDRATE*4) -1)
        | UART_STP_BIT 
        | UART_PRTY_BIT
        | UART_CHAR_LEN 
        //please do not remove these setting , jerry.yu
        | UART_CNTL_MASK_TX_EN
        | UART_CNTL_MASK_RX_EN
        | UART_CNTL_MASK_RST_TX
        | UART_CNTL_MASK_RST_RX
        | UART_CNTL_MASK_CLR_ERR,
};
#define DEBUGROM_CMD_BUF_SIZE ((0x1b0-0xc0-sizeof(__ddr_setting)-sizeof(__plls))&~0x1f)

STATIC_PREFIX_DATA char init_script[DEBUGROM_CMD_BUF_SIZE] __attribute__((section(".setting")))
="r c1107d54";
