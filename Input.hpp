#ifndef INPUT_HPP_
#define INPUT_HPP_
#include "GPIO.hpp"

/**
 * @brief Input vesion of the GPIO class
 *
 */
class Input : public GPIO
{
protected:
public:
    uint8_t last_value = 0x00;
    Input(void) {}
    Input(const uint8_t pin, const char *alias, const logic_level logic_level = logic_level::ACTIVE_HIGH);
    ~Input(void);
    bool flank_detect(const gpio_event event);
};
#endif