/*
 * PCA9622.h
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#ifndef LEDDRIVERS_TI_PCA9622_PCA9622_H_
#define LEDDRIVERS_TI_PCA9622_PCA9622_H_

#include "../PCA96XX.h"

class PCA9622: public PCA96XX {
public:
	PCA9622();
	virtual ~PCA9622();

	void begin(uint8_t _pwm[24]);
	void begin();
	void dim(uint8_t _grppwm);
};

#define PCA9622_ALLCALL 		0x1B
#define PCA9622_PWM0			0x02
#define PCA9622_PWM1			0x03
#define PCA9622_PWM2			0x04
#define PCA9622_PWM3			0x05
#define PCA9622_PWM4			0x06
#define PCA9622_PWM5			0x07
#define PCA9622_PWM6			0x08
#define PCA9622_PWM7			0x09
#define PCA9622_PWM8			0x0A
#define PCA9622_PWM9			0x0B
#define PCA9622_PWM10			0x0C
#define PCA9622_PWM11			0x0D
#define PCA9622_PWM12			0x0E
#define PCA9622_PWM13			0x0F
#define PCA9622_PWM14			0x10
#define PCA9622_PWM15			0x11
#define PCA9622_GRPPWM			0x12


#endif /* LEDDRIVERS_TI_PCA9622_PCA9622_H_ */
