/*
 * defines.h
 *
 *  Created on: Dec 27, 2018
 *      Author: MCT E560 Marc
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#ifndef STM32F4XX
#define STM32F4XX
#endif

#if !defined(SCU8D_002) && !defined(SCU8D_001)
#define SCU8D_001
#endif

#ifdef SCU8D_001
#define LCD_WIDTH	480
#define LCD_HEIGHT	272

#define HFP   16
#define HSYNC 96
#define HBP   48

#define VFP   10
#define VSYNC 2
#define VBP   33

#define LEDDRIVERADD 0xAA
#endif

#endif /* DEFINES_H_ */
