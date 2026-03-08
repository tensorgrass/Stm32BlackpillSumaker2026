#include <enum_step.hpp>
#include <ControllerBase.hpp>

void step_wait(ControllerBase* controller);
void step_wait_init(ControllerBase* controller);
void step_wait_finish(ControllerBase* controller);

void step_init__ini(ControllerBase* controller);
void step_init__end(ControllerBase* controller, enum_step next_step, enum_step send_step);
void step_init__motor(ControllerBase* controller, uint32_t* motor_value);

void step_finish__ini(ControllerBase* controller);
void step_finish__motor(ControllerBase* controller);
void step_finish__end(ControllerBase* controller);

void step_accelerate__ini(ControllerBase* controller);
void step_accelerate__end(ControllerBase* controller, enum_step next_step, enum_step send_step);
void step_accelerate__motor(ControllerBase* controller, uint32_t* motor_value, uint32_t end_speed, int ramp_ms);

void step_decelerate__ini(ControllerBase* controller);
void step_decelerate__end(ControllerBase* controller, enum_step next_step, enum_step send_step);
void step_decelerate__motor(ControllerBase* controller, uint32_t* motor_value, uint32_t end_speed, int ramp_ms);
void step_decelerate_separate__motor(ControllerBase* controller, uint32_t* motor_left, uint32_t* motor_right, uint32_t end_speed, int ramp_ms);

////////////////////////////////////
// STEP_TRACKER_BOTH
////////////////////////////////////
void step_tracker_both_start__ini(ControllerBase* controller);
void step_tracker_both_start__end(ControllerBase* controller, enum_step next_step, enum_step send_step);
void step_tracker_both_detected__ini(ControllerBase* controller);
void step_tracker_both_detected__end(ControllerBase* controller, enum_step next_step, enum_step send_step);
void step_tracker_both_return__ini(ControllerBase* controller);
void step_tracker_both_return__end(ControllerBase* controller, enum_step next_step, enum_step send_step);

void step_button_start__ini(ControllerBase* controller);
void step_button_start__end(ControllerBase* controller, enum_step next_step, enum_step send_step);
