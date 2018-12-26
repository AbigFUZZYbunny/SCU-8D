/*
 * PCA9626.h
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#ifndef LEDDRIVERS_TI_PCA9626_PCA9626_H_
#define LEDDRIVERS_TI_PCA9626_PCA9626_H_

#include "../PCA96XX.h"

class PCA9626: public PCA96XX {
public:
	PCA9626();
	virtual ~PCA9626();

	void begin(uint8_t _pwm[24]);
	void begin();
	void dim(uint8_t _grppwm);
	void set_output();
	void adjust_output(uint8_t _out[3]);
};

#define PCA9626_ALLCALL 		0x26
#define PCA9626_LEDOUT0			0x1D
#define PCA9626_LEDOUT1			0x1E
#define PCA9626_LEDOUT2			0x1F
#define PCA9626_LEDOUT3			0x20
#define PCA9626_LEDOUT4			0x21
#define PCA9626_LEDOUT5			0x22
#define PCA9626_PWM0			0x02
#define PCA9626_PWM1			0x03
#define PCA9626_PWM2			0x04
#define PCA9626_PWM3			0x05
#define PCA9626_PWM4			0x06
#define PCA9626_PWM5			0x07
#define PCA9626_PWM6			0x08
#define PCA9626_PWM7			0x09
#define PCA9626_PWM8			0x0A
#define PCA9626_PWM9			0x0B
#define PCA9626_PWM10			0x0C
#define PCA9626_PWM11			0x0D
#define PCA9626_PWM12			0x0E
#define PCA9626_PWM13			0x0F
#define PCA9626_PWM14			0x10
#define PCA9626_PWM15			0x11
#define PCA9626_PWM16			0x12
#define PCA9626_PWM17			0x13
#define PCA9626_PWM18			0x14
#define PCA9626_PWM19			0x15
#define PCA9626_PWM20			0x16
#define PCA9626_PWM21			0x17
#define PCA9626_PWM22			0x18
#define PCA9626_PWM23			0x19
#define PCA9626_GRPPWM			0x1A


#endif /* LEDDRIVERS_TI_PCA9626_PCA9626_H_ */
