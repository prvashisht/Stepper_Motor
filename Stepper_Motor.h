#ifndef Stepper_Motor_h
#define Stepper_Motor_h

#include "Arduino.h"

class Stepper_Motor {
  public:
    Stepper_Motor(
        byte enable_pin,
        byte dir_pin,
        byte step_pin
    );
    Stepper_Motor(
        byte enable_pin,
        byte dir_pin,
        byte step_pin,
        byte sleep_pin,
        byte reset_pin,
        byte ms1_pin,
        byte ms2_pin,
        byte ms3_pin,
        int step_delay = DEFAULT_STEP_DELAY
    );
    void enable();
    void disable();
    void clockwise();
    void antiClockwise();
    void takeSteps();
    void takeSteps(int steps);
    void setStepDelay(int delay_time);
  private:
    const int DEFAULT_ENABLE = HIGH;   // disabled
    const int DEFAULT_DIRECTION = LOW; // clockwise
    const int DEFAULT_SLEEP = HIGH;    // not sleeping
    const int DEFAULT_RESET = HIGH;    // don't reset and accept step inputs
    const int DEFAULT_MS1 = LOW;       // TODO: Write microstepping hashmap
    const int DEFAULT_MS2 = LOW;       // no microstepping
    const int DEFAULT_MS3 = LOW;       // no microstepping
    const int MAX_STEP_DELAY = 2000;
    const int MIN_STEP_DELAY = 75;
    static const int DEFAULT_STEP_DELAY = 1200;
    bool _enabled = false;
    int _enable = DEFAULT_ENABLE;
    int _direction = DEFAULT_DIRECTION;
    int _sleep = DEFAULT_SLEEP;
    int _reset = DEFAULT_RESET;
    int _ms1 = DEFAULT_MS1;
    int _ms2 = DEFAULT_MS2;
    int _ms3 = DEFAULT_MS3;
    byte _enable_pin;
    byte _direction_pin;
    byte _step_pin;
    byte _sleep_pin;
    byte _reset_pin;
    byte _ms1_pin;
    byte _ms2_pin;
    byte _ms3_pin;
    int _step = LOW;
    int _step_delay = DEFAULT_STEP_DELAY;
    int _steps_taken = 0;
    int _steps_to_take = 0;
};

#endif