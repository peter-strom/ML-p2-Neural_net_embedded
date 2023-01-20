#include "header.hpp"
/** @todo
   * Kunna välja lärhastighet samt epoker. OK
   * kunna välja antalet noder i in och utgångslagret. OK
   * Kunna välja antalet dolda lager och antalet noder i de dolda lagren. OK

   * Träningsdatan ska kunna läsas in från en textfil via en array. OK
   * träning ska ske direkt vid uppstart och knapptryckning ska inte
     medföra en prediktion förens träningen är slutförd. OK
   *
**/

Output LED(17, "LED");
Input Button1(16, "Button1", logic_level::ACTIVE_HIGH);
Input Button2(20, "Button2", logic_level::ACTIVE_HIGH);
Input Button3(21, "Button3", logic_level::ACTIVE_HIGH);
Input Button4(26, "Button4", logic_level::ACTIVE_HIGH);

double led_on = 0;

int main(void)
{
    LED.off();
    /**
     * @brief training data
     * when odd number of buttons is pressed the led will be on
     * @details
     * |      in      | out |
     *  x1  x2  x3  x4  yref
     *  0   0   0   0 	0
     *  0   0   0   1   1
     *  0   0 	1   0   1
     *  0   0   1   1   0
     *  0   1   0   0   1
     *  0   1   0   1   0
     *  0   1   1   0   0
     *  0   1   1   1   1
     *  1   0   0   0   1
     *  1   0   0   1   0
     *  1   0   1   0   0
     *  1   0   1   1   1
     *  1   1   0   0   0
     *  1   1   0   1   1
     *  1   1   1   0   1
     *  1   1   1   1   0
     */

    std::vector<std::vector<double>> train_yref_out;
    std::vector<std::vector<double>> train_x_in;
    char filename[] = "training_data.txt";
    read_file(train_x_in, train_yref_out, filename);

    Neural_network numbrONE(4, 0, 0, 1, activation_option::TANH);
    numbrONE.print_network();
    //numbrONE.add_hidden_layers(2, 2, activation_option::TANH);
    numbrONE.print_network();
    numbrONE.set_training_data(train_x_in, train_yref_out);
    numbrONE.train(6000, 0.03);
    numbrONE.print_result();
    numbrONE.print_network(print_option::FULL);
    while (1)
    {
        std::vector<double> buttons = {(double)Button1.active(),
                                       (double)Button2.active(),
                                       (double)Button3.active(),
                                       (double)Button4.active()};
        led_on = numbrONE.predict(buttons)[0];
        if (led_on > 0.5)
        {
            LED.on();
        }
        else
        {
            LED.off();
        }

        usleep(1000 * 20); // to prevent 100% cpu usage
    }

    return 0;
}