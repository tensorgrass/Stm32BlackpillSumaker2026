/*
 * maincpp.cpp
 *
 *  Created on: May 24, 2025
 *      Author: froilan
 */

// #include <main.h>
#include <ADCBase.hpp>
#include <ButtonPullup.hpp>
#include <ControllerBase.hpp>
#include <FlashMemory.hpp>
#include <Sumaker.hpp>
#include <IRReceiver.hpp>
#include <LedBase.hpp>
#include <MotorOneShot125.hpp>
#include <TestBase.hpp>
#include <TestVoid.hpp>
#include <Timer11Delay.hpp>
#include <TrackerBase.hpp>
#include <UartComm.hpp>
#include <UartSerial.hpp>
#include <maincpp.hpp>
#include <message_types.hpp>
#include <Sumaker.hpp>

ControllerBase controller;
TestBase *current_test = nullptr;
Sumaker fura_run(&controller);

// Variable para contar los mensajes enviados/recibidos
volatile int message_counter = 0;


void main_fura_mode(TIM_HandleTypeDef *htim2, TIM_HandleTypeDef *htim4,
                    ADC_HandleTypeDef *hadc1, uint16_t* adc_values_value, uint16_t num_adc_channels_value) {
  ADCBase adc(hadc1, adc_values_value, num_adc_channels_value);
  TrackerBase tracker_left(&adc, 0, true); // PA1
  TrackerBase tracker_right(&adc, 1, true); // PA2
//  TrackerBase distance_left(&adc, 2); //PA0
//  TrackerBase distance_right(&adc, 3); //PA4

  MotorTB6612FNG motor_driver_left(htim4, TIM_CHANNEL_1, GPIOB, GPIO_PIN_15, GPIOB, GPIO_PIN_14);
  MotorTB6612FNG motor_driver_right(htim4, TIM_CHANNEL_2, GPIOB, GPIO_PIN_1, GPIOB, GPIO_PIN_0);

  ButtonPullup button_start(GPIOB, GPIO_PIN_13, false);
  IRReceiver ir_receiver(htim2, TIM_CHANNEL_3);
  LedBase led_start(GPIOC, GPIO_PIN_13, false);

  controller.init_fura_mode_sumaker(&adc,
                                    &tracker_left, &tracker_right,
                                    &motor_driver_left, &motor_driver_right,
                                    &button_start, &ir_receiver, &led_start);

  while( 1 ) {
    fura_run.main();
  }
}


void HAL_GPIO_EXTI_Callback_cpp(uint16_t GPIO_Pin) {
  if (GPIO_Pin == GPIO_PIN_13) {
	  controller.getButtonStart()->actualizaEstado();
  }
}

void HAL_TIM_IC_CaptureCallback_cpp(TIM_HandleTypeDef *htim) {
  if (htim->Instance == TIM2 && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3) {
    controller.getIRReceiver()->adquireData();
  }
}
