/*
 * PCA96XX.h
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#ifndef LEDDRIVERS_TI_PCA96XX_H_
#define LEDDRIVERS_TI_PCA96XX_H_

#include <stdint.h>
#include "i2c.h"

class PCA96XX {
public:
	uint8_t i2cAddress;
	int i2cBus;

	PCA96XX();
	void init(int _bus, uint8_t _add);
	virtual ~PCA96XX();

	int ports; //9626 = 3; 9624 = 2; 9622 = 1;
	void write_register(uint8_t register_pointer, uint8_t register_value);

	uint8_t portList[6] = {0x00,0x00,0x00,0x00,0x00,0x00};

	void set_output();
	void adjust_output(uint8_t _out[3]);
};

#define PCA96XX_MODE1		0x00
#define PCA96XX_MODE2		0x01
#define PCA9626_LEDOUT0		0x1D
#define PCA9624_LEDOUT0		0x0C
#define PCA9622_LEDOUT0		0x14


#endif /* LEDDRIVERS_TI_PCA96XX_H_ */
