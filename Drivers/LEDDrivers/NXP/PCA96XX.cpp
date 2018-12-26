/*
 * PCA96XX.cpp
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#include "PCA96XX.h"

PCA96XX::PCA96XX() {
	// TODO Auto-generated constructor stub

}

PCA96XX::~PCA96XX() {
	// TODO Auto-generated destructor stub
}

void PCA96XX::init(int _bus, uint8_t _add){
	i2cAddress = _add;
	i2cBus = _bus;

	write_register(PCA96XX_MODE1, 0x81);
	write_register(PCA96XX_MODE2, 0x05);
}

void PCA96XX::write_register(uint8_t register_pointer, uint8_t register_value){
	uint8_t data[2];

	data[0] = register_pointer;
	data[1] = register_value;

	switch(i2cBus){
	case 1:
	  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 2, 20);
	   	break;
	case 2:
	   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 2, 20);
	   	break;
	}
}
