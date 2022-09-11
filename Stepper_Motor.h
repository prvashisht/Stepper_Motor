#ifndef Stepper_Motor_h
#define Stepper_Motor_h

#include "Arduino.h"
#define DEFAULT_ENABLE HIGH; // disabled
#define DEFAULT_DIRECTION LOW; // clockwise
#define DEFAULT_SLEEP HIGH; // not sleeping
#define DEFAULT_RESET HIGH; // don't reset and accept step inputs
#define DEFAULT_MS1 LOW; // TODO: Write microstepping hashmap
#define DEFAULT_MS2 LOW; // no microstepping
#define DEFAULT_MS3 LOW; // no microstepping
#define MAX_STEP_DELAY 2000;
#define MIN_STEP_DELAY 75;
#define DEFAULT_STEP_DELAY 1000;

class Stepper_Motor {
  public:
    Stepper_Motor(
        int enable_pin,
        int dir_pin,
        int step_pin
    );
    Stepper_Motor(
        int enable_pin,
        int dir_pin,
        int step_pin,
        int sleep_pin,
        int reset_pin,
        int ms1_pin,
        int ms2_pin,
        int ms3_pin
    );
    Stepper_Motor(
        int enable_pin,
        int dir_pin,
        int step_pin,
        int sleep_pin,
        int reset_pin,
        int ms1_pin,
        int ms2_pin,
        int ms3_pin,
        int step_delay
    );
    void enable();
    void disable();
    void clockwise();
    void antiClockwise();
    void takeSteps();
    void takeSteps(int steps);
    void setStepDelay(int delay_time);
  private:
    int _enabled = false;
    int _enable = DEFAULT_ENABLE;
    int _direction = DEFAULT_DIRECTION;
    int _sleep = DEFAULT_SLEEP;
    int _reset = DEFAULT_RESET;
    int _ms1 = DEFAULT_MS1;
    int _ms2 = DEFAULT_MS2;
    int _ms3 = DEFAULT_MS3;
    int _step = LOW;
    int _step_delay = DEFAULT_STEP_DELAY;
    int _enable_pin;
    int _direction_pin;
    int _step_pin;
    int _sleep_pin;
    int _reset_pin;
    int _ms1_pin;
    int _ms2_pin;
    int _ms3_pin;
};

#endif