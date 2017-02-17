/**
 * @file system/include/flash/slcnand/mx30lf1ge8ab.h
 *
 * History:
 *    2015/07/30 - [Ken He] created file
 *
 * Copyright (C) 2014-2018, Ambarella, Inc.
 *
 * All rights reserved. No Part of this file may be reproduced, stored
 * in a retrieval system, or transmitted, in any form, or by any means,
 * electronic, mechanical, photocopying, recording, or otherwise,
 * without the prior consent of Ambarella, Inc.
 */

#ifndef __MX30LF1GE8AB_H__
#define __MX30LF1GE8AB_H__

/**
 * nand control register initial setting
 */
#define __NAND_CONTROL						  \
	(NAND_CTR_C2		|				  \
	 NAND_CTR_I4		|				  \
	 NAND_CTR_RC		|				  \
	 NAND_CTR_CC		|				  \
	 NAND_CTR_IE		|				  \
	 NAND_CTR_SZ_1G		|				  \
	 NAND_CTR_WD_8BIT)

#define NAND_MANID		0xC2
#define NAND_DEVID		0xF1
#define NAND_ID3		0x80
#define NAND_ID4		0x95
#define NAND_ID5		0x82
/**
 * define for device info
 */
#define NAND_MAIN_SIZE		2048
#define NAND_SPARE_SIZE		64
#define NAND_PAGE_SIZE		2112
#define NAND_PAGES_PER_BLOCK	64
#define NAND_BLOCKS_PER_PLANE	1024
#define NAND_BLOCKS_PER_ZONE	1024
#define NAND_BLOCKS_PER_BANK	1024
#define NAND_PLANES_PER_BANK	(NAND_BLOCKS_PER_BANK / NAND_BLOCKS_PER_PLANE)
#define NAND_BANKS_PER_DEVICE	1
#define NAND_TOTAL_BLOCKS	(NAND_BLOCKS_PER_BANK * NAND_BANKS_PER_DEVICE)
#define NAND_TOTAL_ZONES	(NAND_TOTAL_BLOCKS / NAND_BLOCKS_PER_ZONE)
#define NAND_TOTAL_PLANES	(NAND_TOTAL_BLOCKS / NAND_BLOCKS_PER_PLANE)

/* Copyback must be in the same plane, so we have to know the plane address */
#define NAND_BLOCK_ADDR_BIT	18
#define NAND_PLANE_ADDR_BIT	28 /* A28 must be the same for copyback */
#define NAND_PLANE_MASK		0x1
/* Used to mask the plane address according to block address in the same bank */
#define NAND_PLANE_ADDR_MASK	(NAND_PLANE_MASK << (NAND_PLANE_ADDR_BIT - \
						     NAND_BLOCK_ADDR_BIT))

#define NAND_PLANE_MAP		NAND_PLANE_MAP_2
#define NAND_COLUMN_CYCLES	2
#define NAND_PAGE_CYCLES	3
#define NAND_ID_CYCLES		5
#define NAND_CHIP_WIDTH		8
#define NAND_CHIP_SIZE_MB	128
#define NAND_BUS_WIDTH		8

#define NAND_NAME	"Macronix MX30LF1GE8AB_128MB_PG2K"

#if defined(CONFIG_NAND_1DEVICE)
#define NAND_DEVICES		1
#elif defined(CONFIG_NAND_2DEVICE)
#define NAND_DEVICES		2
#elif defined(CONFIG_NAND_4DEVICE)
#define NAND_DEVICES		4
#endif

#define NAND_TOTAL_BANKS	(NAND_DEVICES * NAND_BANKS_PER_DEVICE)

#if (NAND_TOTAL_BANKS == 1)
#define NAND_CONTROL		(__NAND_CONTROL | NAND_CTR_1BANK)
#elif (NAND_TOTAL_BANKS == 2)
#define NAND_CONTROL		(__NAND_CONTROL | NAND_CTR_2BANK)
#elif (NAND_TOTAL_BANKS == 4)
#define NAND_CONTROL		(__NAND_CONTROL | NAND_CTR_4BANK)
#elif (NAND_TOTAL_BANKS > 4)
#error Unsupport nand flash banks
#endif

#define NAND_BB_MARKER_OFFSET	0	/* bad block information */

/**
 * define for partition info
 */
#define NAND_RSV_BLKS_PER_ZONE	24

/**
 * timing parameter in ns
 */
#define NAND_TCLS		15
#define NAND_TALS		15
#define NAND_TCS		20
#define NAND_TDS		10
#define NAND_TCLH		5
#define NAND_TALH		5
#define NAND_TCH		5
#define NAND_TDH		5
#define NAND_TWP		15
#define NAND_TWH		10
#define NAND_TWB		100
#define NAND_TRR		20
#define NAND_TRP		15
#define NAND_TREH		10
#define NAND_TRB		100 /* not define in spec, use the same twb */
#define NAND_TCEH		0  /* trhz - tchz = 50 - 50 = 0 */
#define NAND_TRDELAY		25  /* trea */
#define NAND_TCLR		15
#define NAND_TWHR		60
#define NAND_TIR		0
#define NAND_TWW		100  /* not defined in datasheet */
#define NAND_TRHZ		50
#define NAND_TAR		15
#endif