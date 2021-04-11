/******************************
 * Drawdio for Raspberry Pi Pico
 * April 2021 ~aml
 * ****************************/

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

const uint buzzer = 4;
const uint signal = 28;
const float conversion_factor = 3.3f / (1 << 12);
uint16_t result = 0;
float voltage;
float level;

int main(void)
{
    //Initialize everything needed
    stdio_init_all();

    adc_init();
    adc_gpio_init(signal);
    //GPIO28 uses ADC2
    adc_select_input(2);

    // Tell the buzzer pin that the PWM is in charge of its value.
    gpio_set_function(buzzer, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(buzzer);
    pwm_config config = pwm_get_default_config();
    // Load the configuration into our PWM slice, and set it running.
    pwm_init(slice_num, &config, true);
    
    while(true){
        result = adc_read();
        voltage = result * conversion_factor;

        if((result < 1862) || (result > 3223)){
            //Below 1.5V or greater than 3V, output is 0
            level = 0;
        }
        else{
            //Between 1.5 and 3V, the output is linear
            level = voltage*170 - 255; 
        }
        pwm_set_gpio_level(buzzer,level);
    }

}
