/*
 * include/configs/amlogic/m1_8726m_ref.h
 *
 * (C) Copyright 2006-2010
 * Amlogic .
 * Author :
 *	Jerry Yu <jerry.yu@amlogic.com>
 */

#ifndef __CONFIG_H
#define __CONFIG_H
//#define DEBUG 1
/*
 * High Level Configuration Options
 */
#define CONFIG_ARMCORTEXA9	   1	 /* This is an ARM V7 CPU core */
#define CONFIG_MESON		   1	 /* in a Amlogic Meson core */
#define CONFIG_MESON1		   1	 /* which is meson */

#define CONFIG_AMLROM_U_BOOT	   1    /**
										Meson support Romboot mode
								    */
#define CONFIG_BOARD_8726M_ARM    1
#define CONFIG_AML_DEF_UART         1  // UART B
//#define CONFIG_AML_DEF_UART         0 // UART A

#define CONFIG_MEMSIZE  512     //unit is MB
//#define CONFIG_MEMSIZE  256     //unit is MB
#define CONFIG_SYS_NAND_QUIET_TEST	/* don't warn upon unknown NAND flash	*/

#define CONFIG_SWITCH_BOOT_MODE
#define CONFIG_EFUSE
#define CONFIG_SARADC   1
//#define CONFIG_UPGRADE  1

//#define CONFIG_AML_NANDBCH16
#define CONFIG_UCL		1

#define CONFIG_STV // add configs for steven configs.
//#define CONFIG_M3V11 // add config for m3 v1.1 PCBA card difference.
#define CONFIG_RECOVERY //for recovery .
//#define CONFIG_RESCUE //for rescue mode.

#define BOOTFAILD2RECOVERY

/**
 * NAND define
 *
 */

#include <asm/arch/cpu.h>	/* get chip and board defs */

/*
 * Display CPU and Board information
 */

/* Clock Defines */
#define CONFIG_SYS_CLK      600 /*600Mhz  a9 clk@todo redefine it later
                                 */
#define CONFIG_CRYSTAL_MHZ		24
#undef CONFIG_USE_IRQ			   /* no support for IRQs */
#define CONFIG_MISC_INIT_R

#define CONFIG_CMDLINE_TAG		1	/* enable passing of ATAGs */
#define CONFIG_CMDLINE_EDITING	1	/* Command-line editing */
#define CONFIG_SETUP_MEMORY_TAGS	1
#define CONFIG_INITRD_TAG		1
#define CONFIG_REVISION_TAG		1
#define CONFIG_CMD_KGDB			1
//#define CONFIG_SERIAL_TAG       1
//#define CONFIG_CMD_NET			1
#define CONFIG_NET_MULTI        1
#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP

/*
 * Size of malloc() pool
 */
						/* Sector */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (1 << 19))
#define CONFIG_SYS_GBL_DATA_SIZE	128	/* bytes reserved for */
						/* initial data */
/*
 * Hardware drivers
 */

/*osd*/
#if 0
#define CONFIG_AMLOSD
#define CONFIG_AMLVIDEO
#define CONFIG_CMD_BMP
#define CONFIG_CMD_TV
#define CONFIG_CMD_OSD
#define CONFIG_AMLHDMI
#define CONFIG_LOGDISPLAY
#define FB_ADDR 0x84808000
#define OSD_WIDTH      640
#define OSD_HEIGHT     480
#endif

/*
 * select serial console configuration
 */
//#define CONFIG_CONS_INDEX		0
#undef CONFIG_CONS_INDEX

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{4800, 9600, 19200, 38400, 57600,\
					115200}
#define CONFIG_MMC			   1
//#define CONFIG_OMAP3_MMC		1
#define CONFIG_DOS_PARTITION		1
#define SCAN_MMC_PARTITION		2

/* USB
 * Enable CONFIG_MUSB_HCD for Host functionalities MSC, keyboard
 * Enable CONFIG_MUSB_UDD for Device functionalities.
 */
/* #define CONFIG_MUSB_UDC		1 */
#define CONFIG_M1_USBPORT_BASE	0xC90C0000
#define CONFIG_USB_STORAGE
#define CONFIG_USB_DWC_OTG_HCD


/* commands to include */
#include <config_cmd_default.h>

#define CONFIG_CMD_EXT2		/* EXT2 Support			*/
//#define CONFIG_CMD_FAT		/* FAT support			*/
//#define CONFIG_CMD_JFFS2	/* JFFS2 Support		*/
//
//#define CONFIG_CMD_I2C		/* I2C serial bus support	*/
//#define CONFIG_CMD_MMC		/* MMC support			*/
//#define CONFIG_CMD_ONENAND	/* ONENAND support		*/
#define CONFIG_CMD_USB
#define CONFIG_CMD_FAT

//
#undef CONFIG_CMD_ONENAND
#undef CONFIG_CMD_FLASH		/* flinfo, erase, protect	*/
#undef CONFIG_CMD_FPGA		/* FPGA configuration Support	*/
#undef CONFIG_CMD_IMI		/* iminfo			*/
#undef CONFIG_CMD_IMLS		/* List all found images	*/

#define CONFIG_SYS_NO_FLASH 1

/*
 * TWL4030
 */
//#define CONFIG_TWL4030_POWER		1


							/* NAND devices */
#define CONFIG_JFFS2_NAND
/* nand device jffs2 lives on */
#define CONFIG_JFFS2_DEV		"nand0"
/* start of jffs2 partition */
#define CONFIG_JFFS2_PART_OFFSET	0x680000
#define CONFIG_JFFS2_PART_SIZE		0xf980000	/* sz of jffs2 part */

/* Environment information */
#define CONFIG_BOOTDELAY	1

#define CONFIG_BOOTFILE		uImage

#if defined(CONFIG_RESCUE)
#define CONFIG_EXTRA_ENV_SETTINGS \
	"boardname=stv_mbx_ref\0" \
	"hostname=stv_mbx_ref\0" \
	"chipname=8726M\0" \
	"machid=2957\0" \
	"loadaddr=0x82000000\0" \
	"console=ttyS0,115200n8\0" \
	"memsize=512M\0" \
	"cpuclock=800M\0" \
	"gpuclock=200000k\0" \
	"recoverymode=0\0" \
	"nandargs=setenv bootargs console=${console} mem=${memsize} a9_clk=${cpuclock} clk81=${gpuclock} mac=${ethaddr} decopt=0 \0" \
	"nandboot=echo Booting from nand ...; run nandargs; nand read ${loadaddr} 800000 400000; bootm ${loadaddr}\0" \
	"mmcargs=setenv bootargs console=${console} root=/dev/mtdblock2 rw init=/init a9_clk=${cpuclock} clk81=${gpuclock}\0" \
	"mmcboot=echo Booting from mmc ...; mmcinfo; run mmcargs; mmcinfo 0; fatload mmc 0 ${loadaddr} uImage.android; bootm ${loadaddr}\0" \
	"recoveryargs=setenv bootargs console=${console} mem=${memsize} recoverymode=${recoverymode}\0" \
	"recoveryboot=run recoveryargs; sf probe 2; sf read ${loadaddr} 40000 1c0000; bootm ${loadaddr}\0" \
	"rescue=mmcinfo;fatload mmc 0:1 82000000 spi_mbx_ref.bin;sf probe 0;sf erase 0 200000;sf write 82000000 0 200000;nand rom_protect off;nand erase whole;reset\0" \
	"burnspi=mmcinfo;fatload mmc 0:1 82000000 spi_mbx_ref.bin;sf probe 2;sf erase 0 200000;sf write 82000000 0 200000\0" \
	"bootcmd=run rescue\0" \
		
#elif defined(CONFIG_RECOVERY)
#define CONFIG_EXTRA_ENV_SETTINGS \
	"boardname=stv_mbx_ref\0" \
	"hostname=stv_mbx_ref\0" \
	"chipname=8726M\0" \
	"machid=2957\0" \
	"loadaddr=0x82000000\0" \
	"console=ttyS0,115200n8\0" \
	"memsize=512M\0" \
	"cpuclock=800M\0" \
	"gpuclock=200000k\0" \
	"recoverymode=0\0" \
	"nandargs=setenv bootargs console=${console} mem=${memsize} a9_clk=${cpuclock} clk81=${gpuclock} mac=${ethaddr} decopt=0 \0" \
	"nandboot=echo Booting from nand ...; run nandargs; nand read ${loadaddr} 800000 400000; bootm ${loadaddr}\0" \
	"mmcargs=setenv bootargs console=${console} root=/dev/mtdblock2 rw init=/init a9_clk=${cpuclock} clk81=${gpuclock}\0" \
	"mmcboot=echo Booting from mmc ...; mmcinfo; run mmcargs; mmcinfo 0; fatload mmc 0 ${loadaddr} uImage.android; bootm ${loadaddr}\0" \
	"recoveryargs=setenv bootargs console=${console} mem=${memsize} recoverymode=${recoverymode}\0" \
	"recoveryboot=run recoveryargs; sf probe 2; sf read ${loadaddr} 40000 1c0000; bootm ${loadaddr}\0" \
	"rescue=mmcinfo;fatload mmc 0:1 82000000 spi_mbx_ref.bin;sf probe 0;sf erase 0 200000;sf write 82000000 0 200000;nand rom_protect off;nand erase whole;reset\0" \
	"burnspi=mmcinfo;fatload mmc 0:1 82000000 spi_mbx_ref.bin;sf probe 2;sf erase 0 200000;sf write 82000000 0 200000\0" \
	"bootcmd=run nandboot\0" \

#else
#define CONFIG_EXTRA_ENV_SETTINGS \
	"loadaddr=0x82000000\0" \
	"console=ttyS0,115200n8\0" \
	"mmcargs=setenv bootargs console=${console} a9_clock=800M init=/init " \
		"root=/dev/mmcblk0p2 rw " \
		"rootfstype=ext3 rootwait\0" \
	"nandargs=setenv bootargs console=${console} a9_clock=800M init=/init " \
		"root=/dev/mtdblock2 rw\0" \
	"loadbootscript=fatload mmc 0 ${loadaddr} boot.scr\0" \
	"bootscript=echo Running bootscript from mmc ...; " \
		"source ${loadaddr}\0" \
	"loaduimage=fatload mmc 0 ${loadaddr} uImage\0" \
	"mmcboot=echo Booting from mmc ...; " \
		"run mmcargs; " \
		"bootm ${loadaddr}\0" \
	"nandboot=echo Booting from nand ...; " \
		"run nandargs; " \
		"nand read ${loadaddr} ${p0start} ${p0size}; " \
		"bootm ${loadaddr}\0" \
	"boardname=stv_mbx_ref\0" \
	"chipname=8726M\0" \
	"machid=2956\0" \
	"bootargs=init=/init console=ttyS0 a9_clock=800M root=/dev/mtdblock2 rw \0" \
	"partnum=2\0" \
	"p0start=200000\0" \
	"p0size=400000\0" \
	"p0path=uImage\0" \
	"p1start=600000\0" \
	"p1size=8000000\0" \
	"p1path=android.rootfs\0" \
	"bootstart=0\0" \
	"bootsize=60000\0" \
	"bootpath=uboot-mbx-ref.bin\0" \
	"normalstart=200000\0" \
	"normalsize=400000\0" \
//	"tag=3\0" \
	
#define CONFIG_BOOTCOMMAND  "nand read ${loadaddr} ${normalstart} ${normalsize};bootm"

#endif

#define CONFIG_AUTO_COMPLETE	1
/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_HUSH_PARSER		/* use "hush" command parser */
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_PROMPT		"STV # "
#define CONFIG_SYS_CBSIZE		256	/* Console I/O Buffer Size */
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		16	/* max number of command */
						/* args */
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		(CONFIG_SYS_CBSIZE)

#define CONFIG_SYS_LOAD_ADDR    0
/*
 * clk , timer setting 
 */
#define CONFIG_SYS_HZ			1000
#define CONFIG_HARDWARE_FIN     24000000 // 24Mhz crystal .
/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */

#define CONFIG_STACKSIZE	(128 << 10)	/* regular stack 128 KiB */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4 << 10)	/* IRQ stack 4 KiB */
#define CONFIG_STACKSIZE_FIQ	(4 << 10)	/* FIQ stack 4 KiB */
#endif

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1	/* CS1 may or may not be populated */
#define PHYS_MEMORY_START    0x80000000 // from 500000
#if(CONFIG_MEMSIZE == 128)
#define PHYS_MEMORY_SIZE      0x8000000 // 128M
#elif(CONFIG_MEMSIZE == 256)
#define CONFIG_DDR_TYPE DDR_K4T1G164QE //128M/PCS DDR
#define PHYS_MEMORY_SIZE     0x10000000 // 256M
#elif(CONFIG_MEMSIZE == 512)
#define CONFIG_DDR_TYPE DDR_W972GG6JB   //256M/PCS DDR
#define PHYS_MEMORY_SIZE     0x20000000 // 512M
#else
#ERROR: Must config CONFIG_MEMSIZE
#endif
#define CONFIG_SYS_MEMTEST_START	0x80000000	/* memtest works on	*/      
#define CONFIG_SYS_MEMTEST_END		0x07000000	/* 0 ... 120 MB in DRAM	*/  

/* SDRAM Bank Allocation method */
#define SDRC_R_B_C		1

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */

/* **** PISMO SUPPORT *** */

/* Configure the PISMO */
#define PISMO1_NAND_SIZE		GPMC_SIZE_128M
#define PISMO1_ONEN_SIZE		GPMC_SIZE_128M

#define CONFIG_SYS_MAX_FLASH_SECT	520	/* max number of sectors */
						/* on one chip */
#define CONFIG_SYS_MAX_FLASH_BANKS	2	/* max number of flash banks */
#define CONFIG_SYS_MONITOR_LEN		(256 << 10)	/* Reserve 2 sectors */

#define CONFIG_SYS_FLASH_BASE		boot_flash_base

/* Monitor at start of flash */
#ifdef CONFIG_RESCUE
    #define CONFIG_ENV_IS_NOWHERE 1
#endif
//#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_FLASH_BASE
//#define CONFIG_SYS_ONENAND_BASE		ONENAND_MAP
//
//#define CONFIG_ENV_IS_IN_ONENAND	1
//#define ONENAND_ENV_OFFSET		0x260000 /* environment starts here */
//#define SMNAND_ENV_OFFSET		0x260000 /* environment starts here */
//
//#define CONFIG_SYS_ENV_SECT_SIZE	boot_flash_sec
//#define CONFIG_ENV_OFFSET		boot_flash_off
//#define CONFIG_ENV_ADDR			boot_flash_env_addr

#define CONFIG_SPI_BOOT 1
//#define CONFIG_NAND_BOOT 1

#ifdef CONFIG_NAND_BOOT
#define CONFIG_AMLROM_NANDBOOT 1
#endif

#ifdef CONFIG_SPI_BOOT
	#define CONFIG_ENV_OVERWRITE
	#define CONFIG_ENV_IS_IN_SPI_FLASH
	#define CONFIG_CMD_SAVEENV
	#define CONFIG_ENV_SIZE             0x2000
	#define CONFIG_ENV_SECT_SIZE        0x1000
#ifdef CONFIG_UCL
	#define CONFIG_ENV_OFFSET           0x3e000
#else
	#define CONFIG_ENV_OFFSET           0x1f0000
#endif
#elif defined CONFIG_NAND_BOOT
	#define CONFIG_ENV_IS_IN_AML_NAND
	#define CONFIG_CMD_SAVEENV
	#define CONFIG_ENV_OVERWRITE
	#define CONFIG_ENV_SIZE         0x2000
	#define CONFIG_ENV_OFFSET       0x400000
	#define CONFIG_ENV_BLOCK_NUM    2
#else
#ERROR: Must config CONFIG_SPI_BOOT or CONFIG_NAND_BOOT
#endif
/* Monitor at start of flash */

#if	PHYS_MEMORY_SIZE == 0x20000000
	#define UBOOTPATH		"uboot-mbx-ref.bin"
#else
	#define UBOOTPATH		"u-boot-aml.bin"
#endif

/*-----------------------------------------------------------------------
 * CFI FLASH driver setup
 */
/* timeout values are in ticks */
#define CONFIG_SYS_FLASH_ERASE_TOUT	(100 * CONFIG_SYS_HZ)
#define CONFIG_SYS_FLASH_WRITE_TOUT	(100 * CONFIG_SYS_HZ)

/* Flash banks JFFS2 should use */
#define CONFIG_SYS_MAX_MTD_BANKS	(CONFIG_SYS_MAX_FLASH_BANKS + \
					CONFIG_SYS_MAX_NAND_DEVICE)
#define CONFIG_SYS_JFFS2_MEM_NAND
/* use flash_info[2] */
#define CONFIG_SYS_JFFS2_FIRST_BANK	CONFIG_SYS_MAX_FLASH_BANKS
#define CONFIG_SYS_JFFS2_NUM_BANKS	1

#ifndef __ASSEMBLY__
extern unsigned int boot_flash_base;
extern volatile unsigned int boot_flash_env_addr;
extern unsigned int boot_flash_off;
extern unsigned int boot_flash_sec;
extern unsigned int boot_flash_type;
#endif

/*----------------------------------------------------------------------------
 * SMSC9115 Ethernet from SMSC9118 family
 *----------------------------------------------------------------------------
 */
#if defined(CONFIG_CMD_NET)


#define CONFIG_AML_ETHERNET
#define CONFIG_HOSTNAME  			arm_m1
#define CONFIG_ETHADDR          	00:01:02:65:04:75	/* Ethernet address */
#define CONFIG_IPADDR				192.168.1.2				/* Our ip address */
#define CONFIG_GATEWAYIP			192.168.1.1			/* Our getway ip address */
#define CONFIG_SERVERIP				192.168.1.6		/* Tftp server ip address */
#define CONFIG_NETMASK				255.255.255.0
#endif /* (CONFIG_CMD_NET) */

/*
 * BOOTP fields
 */

#define CONFIG_BOOTP_SUBNETMASK		0x00000001
#define CONFIG_BOOTP_GATEWAY		0x00000002
#define CONFIG_BOOTP_HOSTNAME		0x00000004
#define CONFIG_BOOTP_BOOTPATH		0x00000010


#define CONFIG_LZO	 1
#define CONFIG_LZMA  1
//#define CONFIG_SYS_L2X0 1
//#define CONFIG_SYS_NO_DCACHE 1
//#define CONFIG_SYS_NO_ICACHE 1
//#define CONFIG_MTD_DEBUG 1
//#define CONFIG_MTD_DEBUG_VERBOSE 0
#endif /* __CONFIG_H */