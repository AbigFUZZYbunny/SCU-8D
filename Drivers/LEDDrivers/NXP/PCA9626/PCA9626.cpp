/*
 * PCA9626.cpp
 *
 *  Created on: Dec 26, 2018
 *      Author: MCT E560 Marc
 */

#include "PCA9626.h"

PCA9626::PCA9626() {
	// TODO Auto-generated constructor stub

}

PCA9626::~PCA9626() {
	// TODO Auto-generated destructor stub
}

void PCA9626::begin(uint8_t _pwm[24]){
	//this can set individual brightness control from pc software setup
	//The LED PWM addresses should be set with autoincrement which allows the following Transmit
	ports = 3;
	uint8_t data[25];
	data[0] = PCA9626_PWM0;

	for(int i = 1; i <= 24; i++){
		int x = (i - 1);
		data[i] = _pwm[x];
	}

	switch(i2cBus){
	case 1:
	  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 25, 250);
	   	break;
	case 2:
	   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 25, 250);
	   	break;
	}

	dim(0xFF);

	/*write_register(PCA9626_PWM0, _pwm[0]);
	write_register(PCA9626_PWM1, _pwm[1]);
	write_register(PCA9626_PWM2, _pwm[2]);
	write_register(PCA9626_PWM3, _pwm[3]);
	write_register(PCA9626_PWM4, _pwm[4]);
	write_register(PCA9626_PWM5, _pwm[5]);
	write_register(PCA9626_PWM6, _pwm[6]);
	write_register(PCA9626_PWM7, _pwm[7]);
	write_register(PCA9626_PWM8, _pwm[8]);
	write_register(PCA9626_PWM9, _pwm[9]);
	write_register(PCA9626_PWM10, _pwm[10]);
	write_register(PCA9626_PWM11, _pwm[11]);
	write_register(PCA9626_PWM12, _pwm[12]);
	write_register(PCA9626_PWM13, _pwm[13]);
	write_register(PCA9626_PWM14, _pwm[14]);
	write_register(PCA9626_PWM15, _pwm[15]);
	write_register(PCA9626_PWM16, _pwm[16]);
	write_register(PCA9626_PWM17, _pwm[17]);
	write_register(PCA9626_PWM18, _pwm[18]);
	write_register(PCA9626_PWM19, _pwm[19]);
	write_register(PCA9626_PWM20, _pwm[20]);
	write_register(PCA9626_PWM21, _pwm[21]);
	write_register(PCA9626_PWM22, _pwm[22]);
	write_register(PCA9626_PWM23, _pwm[23]);*/
}

void PCA9626::begin(){
	ports = 3;
	uint8_t data[25];
	data[0] = PCA9626_PWM0;

	for(int i = 1; i <= 24; i++){
		data[i] = 0xFF;
	}

	switch(i2cBus){
	case 1:
	  	HAL_I2C_Master_Transmit(&hi2c1, i2cAddress<<1, data, 25, 250);
	   	break;
	case 2:
	   	HAL_I2C_Master_Transmit(&hi2c2, i2cAddress<<1, data, 25, 250);
	   	break;
	}

	dim(0xFF);
}

void PCA9626::dim(uint8_t _grppwm){
	//this can dim all leds based on a light sensor input
	write_register(PCA9626_GRPPWM, _grppwm);
}

void PCA9626::set_output(){

	for(int i = 0; i < ports * 2; i++){
		switch(i){
		case 0:

			break;
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		}

		curState[i] = _out[i];
	}
}

void PCA9626::adjust_output(uint8_t _out[ports]){
	/*for(int y = 0; y < 8; y++){
				switch((_out[i] >> y)  & 0x01){
				case 1:
					switch(i){
					case 1:
						switch(y){
						case 0:
							if(i == 0){
								port0 |= (option0 | option1);
							}else if(i == 1){
								port2 |= (option0 | option1);
							}else{
								port4 |= (option0 | option1);
							}
							break;
						case 1:
							port0 |= (option2 | option3);
							break;
						case 2:
							port0 |= (option4 | option5);
							break;
						case 3:
							port0 |= (option6 | option7);
							break;
						case 4:
							port1 |= (option0 | option1);
							break;
						case 5:
							port1 |= (option2 | option3);
							break;
						case 6:
							port1 |= (option4 | option5);
							break;
						case 7:
							port1 |= (option6 | option7);
							break;
						}


						break;
					case 2:
						if(y < 4){
							port2 |= (option4 | option5);
						}else{
							port3 |= (option4 | option5);
						}
						break;
					case 3:
						if(y < 4){
							port4 |= (option4 | option5);
						}else{
							port5 |= (option4 | option5);
						}
						break;
					}
					break;
				case 0:

					break;
				}
			}*/
}
