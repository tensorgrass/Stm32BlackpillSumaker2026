/*
 * maincpp.hpp
 *
 *  Created on: May 24, 2025
 *      Author: froilan
 */

#ifndef INC_MAINCPP_HPP_
#define INC_MAINCPP_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f4xx_hal.h>


void main_gym_mode(UART_HandleTypeDef *huart1, UART_HandleTypeDef *huart2,
                   TIM_HandleTypeDef *htim4, TIM_HandleTypeDef *htim11,
                   ADC_HandleTypeDef *hadc1, uint16_t* adc_values_value, uint16_t num_adc_channels_value);

void main_fura_mode(TIM_HandleTypeDef *htim2, TIM_HandleTypeDef *htim4,
                    ADC_HandleTypeDef *hadc1, uint16_t* adc_values_value, uint16_t num_adc_channels_value);

void HAL_UART_RxCpltCallback_cpp(UART_HandleTypeDef *huart);

void HAL_GPIO_EXTI_Callback_cpp(uint16_t GPIO_Pin);

void HAL_TIM_IC_CaptureCallback_cpp(TIM_HandleTypeDef *htim);


#ifdef __cplusplus
}
#endif

#endif /* INC_MAINCPP_HPP_ */
