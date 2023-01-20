#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_
#include "GPIO.hpp"
#include "definitions.hpp"
/**
 * @brief Output version version of the GPIO class.
 * 
 */
class Output : public GPIO
{
protected:
public:
    Output(void) {}
    Output(const uint8_t pin, const char *alias);
    Output(const std::vector<unsigned int> &pin, const char *alias);
    ~Output(void);
    void on(void);
    void off(void);
    void toggle(void);
    void blink(std::size_t delay_time);
    void bulk_on(void);
    void bulk_off(void);
    void bulk_toggle(void);
    void bulk_blink(std::size_t delay_time);
    void bulk_blink2(std::size_t delay_time);
};

#endif