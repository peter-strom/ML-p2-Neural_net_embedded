#include "Input.hpp"
#include "definitions.hpp"

/**
 * @brief Construct a new Input object

 * @param[in] pin
 * @param[in] alias
 * @param[in] logic_level, sets input device to active HIG or active LOW
 */
Input::Input(const uint8_t pin, const char *alias, const logic_level logic_level)
{

    this->GPIO_init(pin, alias, gpio_direction::INPUT, logic_level);
    this->last_value = 0;
    return;
}
Input::~Input(void)
{
    this->line.release();
}
/**
 * @brief Flank detection for input.
 * @details
 *        Reads current value and compares to last value to get the flank
 *        of an input event.
 *
 * @param[in] event
 * @return bool
 */
bool Input::flank_detect(const gpio_event event)
{
    const uint8_t previous_value = this->last_value;
    const uint8_t current_value = this->active();
    bool ret_val = false;

    if (current_value == previous_value)
    {
        ret_val = false;
    }
    else
    {
        usleep(50 * 1000);

        if (event == gpio_event::RISING_EDGE)
        {
            if (current_value && !previous_value)
            {
                ret_val = true;
            }
        }
        else if (event == gpio_event::FALLING_EDGE)
        {
            if (!current_value && previous_value)
            {
                ret_val = true;
            }
        }
        else if (event == gpio_event::BOTH_EDGES)
        {
            if (current_value != previous_value)
            {
                ret_val = true;
            }
        }
    }
    this->last_value = current_value;

    return ret_val;
}