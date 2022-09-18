#include "Stepper_Motor.h";

Stepper_Motor::Stepper_Motor(
    byte enable_pin,
    byte direction_pin,
    byte step_pin) {
    _enable_pin = enable_pin;
    _direction_pin = direction_pin;
    _step_pin = step_pin;

    pinMode(_enable_pin, OUTPUT);
    pinMode(_direction_pin, OUTPUT);
    pinMode(_step_pin, OUTPUT);

    digitalWrite(_enable_pin, _enable);
    digitalWrite(_direction_pin, _direction);
    digitalWrite(_step_pin, _step);
}

Stepper_Motor::Stepper_Motor(
    byte enable_pin,
    byte direction_pin,
    byte step_pin,
    byte sleep_pin,
    byte reset_pin,
    byte ms1_pin,
    byte ms2_pin,
    byte ms3_pin,
    int step_delay) {
    _enable_pin = enable_pin;
    _direction_pin = direction_pin;
    _step_pin = step_pin;
    _sleep_pin = sleep_pin;
    _reset_pin = reset_pin;
    _ms1_pin = ms1_pin;
    _ms2_pin = ms2_pin;
    _ms3_pin = ms3_pin;
    _step_delay = step_delay;

    pinMode(_enable_pin, OUTPUT);
    pinMode(_direction_pin, OUTPUT);
    pinMode(_step_pin, OUTPUT);
    pinMode(_sleep_pin, OUTPUT);
    pinMode(_reset_pin, OUTPUT);
    pinMode(_ms1_pin, OUTPUT);
    pinMode(_ms2_pin, OUTPUT);
    pinMode(_ms3_pin, OUTPUT);

    digitalWrite(_enable_pin, _enable);
    digitalWrite(_direction_pin, _direction);
    digitalWrite(sleep_pin, _sleep);
    digitalWrite(reset_pin, _reset);
    digitalWrite(ms1_pin, _ms1);
    digitalWrite(ms2_pin, _ms2);
    digitalWrite(ms3_pin, _ms3);
}

void Stepper_Motor::enable() {
    _enable = LOW;
    _enabled = true;
    digitalWrite(_enable_pin, _enable);
}

void Stepper_Motor::disable() {
    _enable = HIGH;
    _enabled = false;
    digitalWrite(_enable_pin, _enable);
}

void Stepper_Motor::clockwise() {
    _direction = HIGH;
    digitalWrite(_direction_pin, _direction);
}

void Stepper_Motor::antiClockwise() {
    _direction = LOW;
    digitalWrite(_direction_pin, _direction);
}

void Stepper_Motor::takeSteps() {
    digitalWrite(_step_pin, HIGH);
    digitalWrite(_step_pin, LOW);
    delayMicroseconds(_step_delay);
}

void Stepper_Motor::takeSteps(int steps) {
    // TODO: Use millis() or micros() to avoid using loop while the motor is turning.
    // unsigned long long int prevTime;
    for (int i = 0; i < steps; i++) {
        takeSteps();
    }
}
