/*
 * PCA9622.cpp
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#include "PCA9622.h"


PCA9622::PCA9622() {
	// TODO Auto-generated constructor stub

}

PCA9622::~PCA9622() {
	// TODO Auto-generated destructor stub
}

void PCA9622::begin(uint8_t _pwm[16]){
	//this can set individual brightness control from pc software setup
	//The LED PWM addresses should be set with autoincrement which allows the following Transmit
	ports = 2;
	uint8_t data[17];
	data[0] = PCA9622_PWM0;

	for(int i = 1; i <= 16; i++){
		int x = (i - 1);
		data[i] = _pwm[x];
	}

	switch(i2cBus){
	case 1:
	  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 17, 250);
	   	break;
	case 2:
	   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 17, 250);
	   	break;
	}

	dim(0xFF);
}

void PCA9622::begin(){
	ports = 2;
	uint8_t data[17];
	data[0] = PCA9622_PWM0;

	for(int i = 1; i <= 16; i++){
		data[i] = 0xFF;
	}

	switch(i2cBus){
	case 1:
	  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 17, 250);
	   	break;
	case 2:
	   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 17, 250);
	   	break;
	}

	dim(0xFF);
}

void PCA9622::dim(uint8_t _grppwm){
	//this can dim all leds based on a light sensor input
	write_register(PCA9622_GRPPWM, _grppwm);
}
