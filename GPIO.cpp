#include "GPIO.hpp"

/**
 * https://www.lane-fu.com/linuxmirror/libgpiod/doc/html/classgpiod_1_1line.html
 */

/**
 * @brief initiates a GPIO-line
 *
 * @param[in] pin, GPIO-pin number
 * @param[in] alias
 * @param[in] direction, INPUT/OUTPUT
 * @param[in] logic_level, ACTIVE_HIGH/ ACTIVE_LOW
 */
void GPIO::GPIO_init(const uint8_t pin,
                     const char *alias,
                     const gpio_direction direction,
                     const logic_level logic_level)
{
     gpiod::chip chip("gpiochip0");
     this->line = chip.get_line(pin);

     if (direction == gpio_direction::INPUT)
     {
          this->line.request({alias, gpiod::line_request::DIRECTION_INPUT, logic_level});
     }
     else
     {
          this->line.request({alias, gpiod::line_request::DIRECTION_OUTPUT, logic_level}, 1);
     }
     if (line.active_state() == gpiod::line::ACTIVE_HIGH)
     {
          std::cout << alias << " set to active high\n";
     }
     else if (line.active_state() == gpiod::line::ACTIVE_LOW)
     {
          std::cout << alias << " set to active low\n";
     }
}

/**
 * @brief initiates a GPIO-line_bulk with multiple of output pins
 *
 * @param[in] pin, std::vector<unsigned int>
 * @param[in] alias
 */
void GPIO::GPIO_init_bulk_output(const ::std::vector<unsigned int> &pin, const char *alias)
{
     gpiod::chip chip("gpiochip0");
     this->lines = chip.get_lines(pin);
     this->lines.request({alias, gpiod::line_request::DIRECTION_OUTPUT, logic_level::ACTIVE_HIGH});
}

/**
 * @brief checks if input signal is active
 *
 * @return bool
 */
bool GPIO::active(void)
{
     return this->line.get_value();
}
