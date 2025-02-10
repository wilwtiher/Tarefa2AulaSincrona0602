#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_MOTOR 22 // pino do motor conectado a GPIO como PWM

int main()
{
    stdio_init_all();

    gpio_set_function(PWM_MOTOR, GPIO_FUNC_PWM);   // habilitar o pino GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(PWM_MOTOR); // obter o canal (slice) PWM da GPIO
    pwm_set_clkdiv(slice, 2.0);                    // define o divisor de clock do PWM
    pwm_set_wrap(slice, 2000);                     // definir o valor de wrap – valor máximo do contador PWM
    pwm_set_gpio_level(PWM_MOTOR, 1500);           // definir o ciclo de trabalho (duty cycle) do pwm
    pwm_set_enabled(slice, true);                  // habilitar o pwm no slice correspondente

    while (true)
    {
        printf("slice:%d\n", slice);
        sleep_ms(1000);
    }
}
