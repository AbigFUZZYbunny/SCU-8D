/*
 * PCA9624.cpp
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#include "PCA9624.h"


PCA9624::PCA9624() {
	// TODO Auto-generated constructor stub

}

PCA9624::~PCA9624() {
	// TODO Auto-generated destructor stub
}

void PCA9624::begin(uint8_t _pwm[8]){
	//this can set individual brightness control from pc software setup
	//The LED PWM addresses should be set with autoincrement which allows the following Transmit
	ports = 1;
	uint8_t data[9];
	data[0] = PCA9624_PWM0;

	for(int i = 1; i <= 8; i++){
		int x = (i - 1);
		data[i] = _pwm[x];
	}

	switch(i2cBus){
	case 1:
	  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 9, 250);
	   	break;
	/*case 2:
	   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 9, 250);
	   	break;*/
	}

	dim(0xFF);
}

void PCA9624::begin(){
	ports = 1;
	uint8_t data[9];
	data[0] = PCA9624_PWM0;

	for(int i = 1; i <= 8; i++){
		data[i] = 0xFF;
	}

	switch(i2cBus){
	case 1:
	  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 9, 250);
	   	break;
	/*case 2:
	   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 9, 250);
	   	break;*/
	}

	dim(0xFF);
}

void PCA9624::dim(uint8_t _grppwm){
	//this can dim all leds based on a light sensor input
	write_register(PCA9624_GRPPWM, _grppwm);
}
