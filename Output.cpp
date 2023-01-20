#include "Output.hpp"

/**
 * @brief Construct a new Output object
 *
 * @param[in] pin - gpio pin number
 * @param[in] alias
 */
Output::Output(const uint8_t pin,
               const char *alias)
{
    this->GPIO_init(pin, alias);
}

/**
 * @brief Construct a new Output bulk object
 *
 * @param[in] pin - a vector with gpio pin numbers
 * @param[in] alias
 */
Output::Output(const std::vector<unsigned int> &pin, const char *alias)
{
    this->GPIO_init_bulk_output(pin, alias);
}

Output::~Output(void)
{
    this->bulk_off();
    this->lines.release();
}

/**
 * @brief Set output value to 1 (HIGH)
 *
 */
void Output::on(void)
{
    this->line.set_value(1);
}

/**
 * @brief Set output value to 0 (LOW)
 *
 */
void Output::off(void)
{
    this->line.set_value(0);
}

/**
 * @brief Toggle output value between HIGH/LOW
 *
 */
void Output::toggle(void)
{
    if (this->active() == 1)
    {
        this->off();
    }
    else
    {
        this->on();
    }
}


/**
 * @brief Set output values to 1 (HIGH)
 * 
 */
void Output::bulk_on(void)
{
    auto values = this->lines.get_values();

    for (size_t i = 0; i < values.size(); i++)
    {
        values[i] = 1;
    }
    this->lines.set_values(values);
}

/**
 * @brief Set output values to 0 (LOW)
 *
 */
void Output::bulk_off(void)
{
    auto values = this->lines.get_values();

    for (size_t i = 0; i < values.size(); i++)
    {
        values[i] = 0;
    }
    this->lines.set_values(values);
}

/**
 * @brief Toggle output values between HIGH/LOW
 *
 */
void Output::bulk_toggle(void)
{
    auto values = this->lines.get_values();

    for (size_t i = 0; i < values.size(); i++)
    {
        values[i] = !values[i];
    }
    this->lines.set_values(values);
}

/**
 * @brief Blink output device with chosen delay time.
 *
 * @param[in] delay_time, delaytime in ms
 */
void Output::blink(std::size_t delay_time)
{
    this->on();
    usleep(delay_time * 1000);
    this->off();
    usleep(delay_time * 1000);
}

/**
 * @brief Blink output device with chosen delay time.
 *
 * @param[in] delay_time, delaytime in ms
 */
void Output::bulk_blink(std::size_t delay_time)
{
    this->bulk_toggle();
    usleep(delay_time * 1000);
}

/**
 * @brief Blink output device with chosen delay time.
 *
 * @param[in] delay_time, delaytime in ms
 */
void Output::bulk_blink2(std::size_t delay_time)
{
    this->bulk_off();
    auto values = this->lines.get_values();
    for (size_t i = 0; i < values.size(); i++)
    {
        values[i] = 1;
        this->lines.set_values(values);
        usleep(delay_time * 1000);
        values[i] = 0;
        this->lines.set_values(values);
    }
}