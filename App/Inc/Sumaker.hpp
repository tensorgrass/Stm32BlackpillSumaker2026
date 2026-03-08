#ifndef SUMAKER_HPP
#define SUMAKER_HPP

#define FLASH_DATA_VERSION 3
#define FLASH_DATA_NUM_VALUES 5

//#define F_D_ACTIVE_SENSOR_TILTING
//#define F_D_ACTIVE_LED_SENSOR_TILTING

#define F_D_ACTIVE_TRACKER_SENSOR_LEFT
#define F_D_ACTIVE_TRACKER_SENSOR_RIGHT
//#define F_D_ACTIVE_DISTANCE_SENSOR_LEFT
//#define F_D_ACTIVE_DISTANCE_SENSOR_RIGHT
//#define F_D_ACTIVE_DISTANCE_SENSOR_LATERAL_LEFT
//#define F_D_ACTIVE_DISTANCE_SENSOR_LATERAL_RIGHT
//#define F_D_ACTIVE_DISTANCE_SENSOR_CENTRAL

//#define F_D_ACTIVE_LED_TRACKER_SENSOR_LEFT
//#define F_D_ACTIVE_LED_TRACKER_SENSOR_RIGHT
//#define F_D_ACTIVE_LED_DISTANCE_SENSOR_LEFT
//#define F_D_ACTIVE_LED_DISTANCE_SENSOR_RIGHT
//#define F_D_ACTIVE_LED_DISTANCE_SENSOR_LATERAL_LEFT
//#define F_D_ACTIVE_LED_DISTANCE_SENSOR_LATERAL_RIGHT
//#define F_D_ACTIVE_LED_DISTANCE_SENSOR_CENTRAL

#define F_D_BUTTON_START_WAIT 3000//4890

#define F_D_DEFENSE_BACK_FAST 1400
#define F_D_DEFENSE_BACK_SLOW 1650
#define F_D_DEFENSE_SPIN_FRONT 2330
#define F_D_DEFENSE_SPIN_BACK 1400
#define F_D_DEFENSE_ATTACK 2450
#define F_D_DEFENSE_LEFT_OUT_MS 600
#define F_D_DEFENSE_RIGHT_OUT_MS 650
#define F_D_DEFENSE_SPIN_OUT_MS 550
#define F_D_DEFENSE_ATTACK_OUT_MS 650

#define F_D_SENSOR_TILTING_BACK_FAST 1400
#define F_D_SENSOR_TILTING_BACK_SLOW 1650
#define F_D_SENSOR_TILTING_IN_MS 1
#define F_D_SENSOR_TILTING_OUT_MS 1000

#define F_D_SPEED_RAMP_TIME_INCREMENT_MS 1
#define F_D_SPEED_RAMP_TIME_INCREMENT_FROM_BACK_MS 1
#define F_D_SPEED_RAMP_VALUE_INCREMENT 2
#define F_D_SPEED_RAMP_VALUE_INCREMENT_FROM_BACK 1
#define F_D_SPEED_REFRESH_MS 10

#define F_D_ESC_MID_STOP 0 // 1920  // 1830-2000
#define F_D_ESC_BASE_SPEED_RAMP_INI 10 //2100
#define F_D_ESC_BASE_SPEED_LEFT 30 //2200
#define F_D_ESC_BASE_SPEED_RIGHT 30 //2200
#define F_D_ESC_BASE_SLOW 30 //2200
#define F_D_ESC_BASE_FAST 80 // 2330
#define F_D_ESC_TRAKER_SLOW_SPEED -20 //2050
#define F_D_ESC_TRACKER_SPEED 60 //2450
#define F_D_ESC_TRAKER_BACK -60 //1560
#define F_D_ESC_TRAKER_ROTATE_SLOW -60 // 1700
#define F_D_ESC_TRAKER_ROTATE_FAST 60 //2330
#define F_D_ESC_TRACKER_BOTH_SPEED_FAST 70 //2500
#define F_D_ESC_TRACKER_BOTH_SPEED_SLOW -70 //1760

#define F_D_TRACKER_LEFT_IN_DETECT_LINE 3000
#define F_D_TRACKER_LEFT_OUT_DETECT_LINE 3300
#define F_D_TRACKER_RIGHT_IN_DETECT_LINE 3000
#define F_D_TRACKER_RIGHT_OUT_DETECT_LINE 3300
#define F_D_TRACKER_OUT_OF_LINE_MS 100
#define F_D_TRACKER_ROTATE_MS 600
#define F_D_TRACKER_OUT_OF_LINE_BOTH_MS 800

#define F_D_DISTANCE_SPEED_SLOW_LEFT 30// 2200
#define F_D_DISTANCE_SPEED_SLOW_RIGHT 30 //2200
#define F_D_DISTANCE_SPEED_LEFT 60 //2380
#define F_D_DISTANCE_SPEED_RIGHT 60 //2380
#define F_D_DISTANCE_LATERAL_SPEED_LEFT 80 //2500
#define F_D_DISTANCE_LATERAL_SPEED_RIGHT 80 //2500
#define F_D_DISTANCE_BOTH_SPEED 70 //2380
#define F_D_DISTANCE_BOTH_SPEED_BOOST 100 //2550

#define F_D_DISTANCE_LEFT_IN_DETECT_LINE 1900 //1900
#define F_D_DISTANCE_LEFT_OUT_DETECT_LINE 1600 //1800
#define F_D_DISTANCE_RIGHT_IN_DETECT_LINE 1900
#define F_D_DISTANCE_RIGHT_OUT_DETECT_LINE 1600
#define F_D_DISTANCE_LATERAL_LEFT_IN_DETECT_LINE 1900
#define F_D_DISTANCE_LATERAL_LEFT_OUT_DETECT_LINE 1600
#define F_D_DISTANCE_LATERAL_RIGHT_IN_DETECT_LINE 1900
#define F_D_DISTANCE_LATERAL_RIGHT_OUT_DETECT_LINE 1600
#define F_D_DISTANCE_CENTRAL_IN_DETECT_LINE 2480
#define F_D_DISTANCE_CENTRAL_OUT_DETECT_LINE 2390
#define F_D_DISTANCE_IN_MS 1
#define F_D_DISTANCE_OUT_MS 60
#define F_D_DISTANCE_BOTH_OUT_MS 100
#define F_D_DISTANCE_CENTRAL_BOOST_MS 20
#define F_D_DISTANCE_BOTH_BOOST_OUT_MS 1000

#define F_D_REMOTE2_ON 33456510
#define F_D_REMOTE2_OK 33474615
#define F_D_REMOTE2_BACK 33481755
#define F_D_REMOTE2_UP 33430755
#define F_D_REMOTE2_DOWN 33424125
#define F_D_REMOTE2_LEFT 33483795
#define F_D_REMOTE2_RIGHT 33463395

#define F_D_REMOTE2_HOME 33476145
#define F_D_REMOTE2_MENU 33472830
#define F_D_REMOTE2_VOLUME_UP 33480990
#define F_D_REMOTE2_VOLUME_DOWN 33460590
#define F_D_REMOTE2_MOUSE 33428205

#include <ControllerBase.hpp>

class Sumaker {
 public:
  Sumaker(ControllerBase* controllerBaseValue);

  void main();

 private:
  ControllerBase* controller;  // Puntero al controlador base

  enum enum_step_fura {
    STEP_WAIT_BUTTON_START_PRESSED,
    STEP_WAIT_TRACKER_CALIBRATE_WHITE,
    STEP_INIT_TRACKER_CALIBRATE_WHITE,
    STEP_WAIT_TRACKER_CALIBRATE_BLACK,
    STEP_INIT_TRACKER_CALIBRATE_BLACK,
    STEP_TEST_ALL_SENSORS,
    STEP_BUTTON_START_PRESSED,
    STEP_DEFENSE_LEFT,
    STEP_DEFENSE_RIGHT,
    STEP_DEFENSE_SPIN,
    STEP_DEFENSE__STEP2_ATTACK,
    STEP_MOTOR_START,
    STEP_SENSOR_TILTING_DETECTED,
    STEP_TRACKER_LEFT_DETECTED,
    STEP_TRACKER_LEFT_DETECTED__STEP2_ROTATE,
    STEP_TRACKER_LEFT_DETECTED__STEP2_RIGHT_DETECTED,
    STEP_TRACKER_RIGHT_DETECTED,
    STEP_TRACKER_RIGHT_DETECTED__STEP2_ROTATE,
    STEP_TRACKER_RIGHT_DETECTED__STEP2_LEFT_DETECTED,
    STEP_DISTANCE_LATERAL_LEFT_DETECTED,
    STEP_DISTANCE_LATERAL_LEFT_DETECTED__STEP2_LEFT_DETECTED,
    STEP_DISTANCE_LEFT_DETECTED,
    STEP_DISTANCE_LATERAL_RIGHT_DETECTED,
    STEP_DISTANCE_LATERAL_RIGHT_DETECTED__STEP2_RIGHT_DETECTED,
    STEP_DISTANCE_RIGHT_DETECTED,
    STEP_DISTANCE_BOTH_DETECTED,
    STEP_DISTANCE_CENTRAL_BOOST,
    STEP_END
  };

  enum enum_direction {
    DIR_CENTER,
    DIR_LEFT,
    DIR_RIGHT
  };

  enum_step_fura current_step, previous_step, step_after_button;
  bool current_step_init = true;
  void goNextStep(enum_step_fura next_step);

  uint32_t speed_left_ini = 0;
  uint32_t speed_left_end = 0;
  uint32_t speed_right_ini = 0;
  uint32_t speed_right_end = 0;
  uint32_t speed_ramp__time_tick_ini = 0;
  uint32_t speed_ramp__time_tick_current = 0;
  uint32_t speed_refresh__time_tick_ini = 0;
  uint32_t speed_refresh__time_tick_current = 0;

  uint8_t direction_base = enum_direction::DIR_CENTER;
  uint32_t esc_speed_base_left = F_D_ESC_BASE_SPEED_LEFT;
  uint32_t esc_speed_base_right = F_D_ESC_BASE_SPEED_RIGHT;

  uint32_t tracker_base_left_in_detect_line = F_D_TRACKER_LEFT_IN_DETECT_LINE;
  uint32_t tracker_base_right_in_detect_line = F_D_TRACKER_RIGHT_IN_DETECT_LINE;
  uint32_t tracker_base_left_out_detect_line = F_D_TRACKER_LEFT_OUT_DETECT_LINE;
  uint32_t tracker_base_right_out_detect_line = F_D_TRACKER_RIGHT_OUT_DETECT_LINE;
  uint32_t tracker_base_iteration = 0;
  uint32_t tracker_base_lap = 0;
  std::vector<uint16_t> tracker_base_left_values;
  std::vector<uint16_t> tracker_base_right_values;
  uint32_t tracker_base_time_tick_ini = 0;
  uint32_t tracker_base_time_tick_current = 0;

  uint32_t step_button_start_pressed__time_tick_ini = 0;
  uint32_t step_button_start_pressed__time_tick_current = 0;
  uint8_t button_stop__button_previous_state = 0;

  uint32_t time_out__time_tick_ini = 0;
  uint32_t time_out__time_tick_current = 0;

  bool sensor_tilting_in__button_pressed = false;
  uint32_t sensor_tilting_in__time_tick_ini = 0;
  uint32_t sensor_tilting_in__time_tick_current = 0;

  bool sensor_tilting_out__button_pressed = false;
  uint32_t sensor_tilting_out__time_tick_ini = 0;
  uint32_t sensor_tilting_out__time_tick_current = 0;

  uint32_t tracker_left_in__tracker_value = 0;
  uint32_t tracker_left_in__time_tick_ini = 0;
  uint32_t tracker_left_in__time_tick_current = 0;

  uint32_t tracker_left_out__tracker_value = 0;
  uint32_t tracker_left_out__time_tick_ini = 0;
  uint32_t tracker_left_out__time_tick_current = 0;

  uint32_t tracker_right_in__tracker_value = 0;
  uint32_t tracker_right_in__time_tick_ini = 0;
  uint32_t tracker_right_in__time_tick_current = 0;

  uint32_t tracker_right_out__tracker_value = 0;
  uint32_t tracker_right_out__time_tick_ini = 0;
  uint32_t tracker_right_out__time_tick_current = 0;

  uint32_t distance_lateral_left_in__distance_value = 0;
  uint32_t distance_lateral_left_in__time_tick_ini = 0;
  uint32_t distance_lateral_left_in__time_tick_current = 0;

  uint32_t distance_lateral_left_out__distance_value = 0;
  uint32_t distance_lateral_left_out__time_tick_ini = 0;
  uint32_t distance_lateral_left_out__time_tick_current = 0;

  uint32_t distance_left_in__distance_value = 0;
  uint32_t distance_left_in__time_tick_ini = 0;
  uint32_t distance_left_in__time_tick_current = 0;

  uint32_t distance_left_out__distance_value = 0;
  uint32_t distance_left_out__time_tick_ini = 0;
  uint32_t distance_left_out__time_tick_current = 0;

  uint32_t distance_lateral_right_in__distance_value = 0;
  uint32_t distance_lateral_right_in__time_tick_ini = 0;
  uint32_t distance_lateral_right_in__time_tick_current = 0;

  uint32_t distance_lateral_right_out__distance_value = 0;
  uint32_t distance_lateral_right_out__time_tick_ini = 0;
  uint32_t distance_lateral_right_out__time_tick_current = 0;

  uint32_t distance_right_in__distance_value = 0;
  uint32_t distance_right_in__time_tick_ini = 0;
  uint32_t distance_right_in__time_tick_current = 0;

  uint32_t distance_right_out__distance_value = 0;
  uint32_t distance_right_out__time_tick_ini = 0;
  uint32_t distance_right_out__time_tick_current = 0;

  uint32_t distance_central_in__distance_value = 0;
  uint32_t distance_central_in__time_tick_ini = 0;
  uint32_t distance_central_in__time_tick_current = 0;

  uint32_t distance_central_out__distance_value = 0;
  uint32_t distance_central_out__time_tick_ini = 0;
  uint32_t distance_central_out__time_tick_current = 0;

  void detectButtonStop();
  void detectTimeOut(enum_step_fura next_step, uint32_t time_out);
  void detectSensorTiltingIn(enum_step_fura next_step);
  void detectSensorTiltingOut(enum_step_fura next_step, uint32_t time_out_of_line);
  void detectTrakerLeftIn(enum_step_fura next_step);
  void detectTrakerLeftOut(enum_step_fura next_step, uint32_t time_out_of_line);
  void detectTrakerRightIn(enum_step_fura next_step);
  void detectTrakerRightOut(enum_step_fura next_step, uint32_t time_out_of_line);
  void detectDistanceLateralLeftIn(enum_step_fura next_step);
  void detectDistanceLateralLeftOut(enum_step_fura next_step, uint32_t time_out_detect);
  void detectDistanceLeftIn(enum_step_fura next_step);
  void detectDistanceLeftOut(enum_step_fura next_step, uint32_t time_out_detect);
  void detectDistanceLateralRightIn(enum_step_fura next_step);
  void detectDistanceLateralRightOut(enum_step_fura next_step, uint32_t time_out_detect);
  void detectDistanceRightIn(enum_step_fura next_step);
  void detectDistanceRightOut(enum_step_fura next_step, uint32_t time_out_detect);
  void detectDistanceCentralIn(enum_step_fura next_step);
  void detectDistanceCentralOut(enum_step_fura next_step, uint32_t time_out_detect);

  void setMotorSpeed(uint32_t speed_left, uint32_t speed_right);
  void setMotorSpeedRamp(uint32_t speed_left_ini, uint32_t speed_left_end, uint32_t speed_right_ini, uint32_t speed_right_end);
  void rampMotorSpeed(uint32_t speed_ramp_time_increment_ms, uint32_t speed_ramp_value_increment);

  void setDirectionCenter();
  void setDirectionLeft();   // deprecated
  void setDirectionRight();  // deprecated
};

#endif  // SUMAKER_HPP
