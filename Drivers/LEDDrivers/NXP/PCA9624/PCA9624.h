/*
 * PCA9624.h
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#ifndef LEDDRIVERS_TI_PCA9624_PCA9624_H_
#define LEDDRIVERS_TI_PCA9624_PCA9624_H_

#include "../PCA96XX.h"

class PCA9624: public PCA96XX {
public:
	PCA9624();
	virtual ~PCA9624();

	void begin(uint8_t _pwm[16]);
	void begin();
	void dim(uint8_t _grppwm);
};

#define PCA9624_ALLCALL 		0x11
#define PCA9624_PWM0			0x02
#define PCA9624_PWM1			0x03
#define PCA9624_PWM2			0x04
#define PCA9624_PWM3			0x05
#define PCA9624_PWM4			0x06
#define PCA9624_PWM5			0x07
#define PCA9624_PWM6			0x08
#define PCA9624_PWM7			0x09
#define PCA9624_GRPPWM			0x0A


#endif /* LEDDRIVERS_TI_PCA9624_PCA9624_H_ */
