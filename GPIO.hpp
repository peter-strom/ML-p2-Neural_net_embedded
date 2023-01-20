#ifndef GPIO_HPP_
#define GPIO_HPP_
#include "definitions.hpp"

enum class gpio_direction
{
    INPUT,
    OUTPUT
};
enum class gpio_event
{
    RISING_EDGE,
    FALLING_EDGE,
    BOTH_EDGES
};

enum logic_level
{
    ACTIVE_HIGH,
    ACTIVE_LOW
};

/**
 * @brief Generic class for all IO-pins
 *
 */
class GPIO
{
protected:
public:
    gpiod::line line;
    gpiod::line_bulk lines;
    GPIO(void) {}
    ~GPIO(void) { std::cout << "GPIO destructor called\n"; }
    void GPIO_init(const uint8_t pin,
                   const char *alias,
                   const gpio_direction direction  = gpio_direction::OUTPUT,
                   const logic_level logic_level = logic_level::ACTIVE_HIGH);
    void GPIO_init_bulk_output(const ::std::vector<unsigned int> &pin, const char *alias);
    bool active(void);
};

#endif