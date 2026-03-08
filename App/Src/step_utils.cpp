#include <step_utils.hpp>

void step_wait(ControllerBase* controller) {
  HAL_Delay(1);
}

void step_wait_init(ControllerBase* controller) {
  controller->setRxStep(enum_step::STEP_INIT);
}

void step_wait_finish(ControllerBase* controller) {
  controller->setRxStep(enum_step::STEP_FINISH);
}

void step_init__ini(ControllerBase* controller){
  controller->getUartSerial()->bufferln("Fura: STEP_INIT");
}

void step_init__end(ControllerBase* controller, enum_step next_step, enum_step send_step){
  controller->setRxStep(next_step);
  controller->setTxGroup(controller->getRxGroup());
  controller->setTxSubgroup(controller->getRxSubgroup());
  controller->setTxStep(send_step); // Cambia el paso para evitar reentradas
  controller->commSendData();
}

void step_init__motor(ControllerBase* controller, uint32_t* motor_value){
  controller->getMotorLeft()->setSpeed(*motor_value);
  controller->getMotorRight()->setSpeed(*motor_value);
  controller->getUartSerial()->bufferln(std::to_string(*motor_value));

  HAL_Delay(3000); // Espera 100 milisegundos
}


void step_finish__ini(ControllerBase* controller){
  controller->getUartSerial()->bufferln("Fura: STEP_FINISH");
}

void step_finish__motor(ControllerBase* controller){
  controller->getMotorLeft()->disable();
  controller->getMotorRight()->disable();
}

void step_finish__end(ControllerBase* controller){
  controller->getUartSerial()->printBuffer();
  controller->endRxTransaction(); // Finaliza la transacción de envío
}


void step_accelerate__ini(ControllerBase* controller){
  controller->getUartSerial()->buffer("Fura: STEP_ACCELERATE\r\n");
}

void step_accelerate__end(ControllerBase* controller, enum_step next_step, enum_step send_step){
  controller->setRxStep(next_step);
  controller->setTxStep(send_step);
  controller->commSendData(); // Enviar el mensaje a través de UART
}

void step_accelerate__motor(ControllerBase* controller, uint32_t* motor_value, uint32_t end_speed, int ramp_ms){
  while(1) {
    *motor_value += ESC_INC;
    if (*motor_value < ESC_FORWARD && *motor_value > ESC_BACKWARD) {
      *motor_value = ESC_FORWARD;
    }

    controller->getMotorLeft()->setSpeed(*motor_value);
    controller->getMotorRight()->setSpeed(*motor_value);
    controller->getUartSerial()->bufferln(std::to_string(*motor_value));

    HAL_Delay(ramp_ms); // Espera 100 milisegundos

    if (*motor_value >= end_speed) {
      break;
    }
  }
}


void step_decelerate__ini(ControllerBase* controller){
  controller->getUartSerial()->buffer("Fura: STEP_DECELERATE\r\n");
}

void step_decelerate__end(ControllerBase* controller, enum_step next_step, enum_step send_step){
  controller->setRxStep(next_step);
  controller->setTxStep(send_step); // Cambia el paso para evitar reentradas
  controller->commSendData();
}

void step_decelerate__motor(ControllerBase* controller, uint32_t* motor_value, uint32_t end_speed, int ramp_ms){
  while(1) {
    *motor_value -= ESC_INC;
    if (*motor_value < ESC_FORWARD && *motor_value > ESC_BACKWARD) {
      *motor_value = ESC_MID;
    }

    controller->getMotorLeft()->setSpeed(*motor_value);
    controller->getMotorRight()->setSpeed(*motor_value);
    controller->getUartSerial()->bufferln(std::to_string(*motor_value));

    if (*motor_value < ESC_FORWARD && *motor_value > ESC_BACKWARD) {
      controller->getUartSerial()->bufferln("Fura: MOTOR STOP");
      break;
    }

    HAL_Delay(ramp_ms); // Espera 100 milisegundos
  }
}

void step_decelerate_separate__motor(ControllerBase* controller, uint32_t* motor_left, uint32_t* motor_right, uint32_t end_speed, int ramp_ms){
  uint8_t motor_left_end = 0;
  uint8_t motor_right_end = 0;
  while(1) {
    if (motor_left_end == 0) {
      *motor_left -= ESC_INC;
      if (*motor_left < ESC_FORWARD && *motor_left > ESC_BACKWARD) {
        *motor_left = ESC_MID;
      }
      controller->getMotorLeft()->setSpeed(*motor_left);
      if (*motor_left < ESC_FORWARD && *motor_left > ESC_BACKWARD) {
        controller->getUartSerial()->bufferln("Fura: MOTOR STOP");
        motor_left_end = 1;
      }
    }

    if (motor_right_end == 0) {
      *motor_right -= ESC_INC;
      if (*motor_right < ESC_FORWARD && *motor_right > ESC_BACKWARD) {
        *motor_right = ESC_MID;
      }
      controller->getMotorRight()->setSpeed(*motor_right);
      if (*motor_right < ESC_FORWARD && *motor_right > ESC_BACKWARD) {
        controller->getUartSerial()->bufferln("Fura: MOTOR STOP");
        motor_right_end = 1;
      }
    }


    if (motor_left_end == 1 && motor_right_end == 1) {
      break;
    }

    HAL_Delay(ramp_ms); // Espera 100 milisegundos
  }
}

////////////////////////////////////
// STEP_TRACKER_BOTH
////////////////////////////////////
void step_tracker_both_start__ini(ControllerBase* controller){
  controller->getUartSerial()->bufferln("Fura: STEP_TRACKER_BOTH_START");
}

void step_tracker_both_start__end(ControllerBase* controller, enum_step next_step, enum_step send_step){
  controller->setRxStep(next_step);
  controller->setTxStep(send_step); // Cambia el paso para evitar reentradas
  controller->commSendData();
}

void step_tracker_both_detected__ini(ControllerBase* controller){
  controller->getUartSerial()->bufferln("Fura: STEP_TRACKER_BOTH_DETECTED");
}

void step_tracker_both_detected__end(ControllerBase* controller, enum_step next_step, enum_step send_step){
  controller->setRxStep(next_step);
  controller->setTxStep(send_step); // Cambia el paso para evitar reentradas
  controller->commSendData();
}

void step_tracker_both_return__ini(ControllerBase* controller){
  controller->getUartSerial()->bufferln("Fura: STEP_TRACKER_BOTH_RETURN");
}

void step_tracker_both_return__end(ControllerBase* controller, enum_step next_step, enum_step send_step){
  controller->setRxStep(next_step);
  controller->setTxStep(send_step); // Cambia el paso para evitar reentradas
  controller->commSendData();
}


void step_button_start__ini(ControllerBase* controller){
  controller->getUartSerial()->buffer("Fura: STEP_BUTTON_START\r\n");
}

void step_button_start__end(ControllerBase* controller, enum_step next_step, enum_step send_step){
  controller->setRxStep(next_step);
  controller->setTxStep(send_step);
  controller->commSendData(); // Enviar el mensaje a través de UART
}
