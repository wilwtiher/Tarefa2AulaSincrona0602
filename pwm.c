#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_MOTOR 22 // pino do motor conectado a GPIO como PWM. para o LED, mudar o pino para 12.

int main()
{
    stdio_init_all();

    gpio_set_function(PWM_MOTOR, GPIO_FUNC_PWM);   // Habilitar o pino GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(PWM_MOTOR); // Obter o canal (slice) PWM da GPIO
    pwm_set_clkdiv(slice, 125.0);                    // Definir o divisor de clock do PWM
    pwm_set_wrap(slice, 19999);                  // Definir o valor de wrap para 50 Hz
    pwm_set_gpio_level(PWM_MOTOR, 1500);          // Definir o ciclo de trabalho para 1,5 ms (90 graus)
    pwm_set_enabled(slice, true);                  // Habilitar o PWM no slice correspondente

    while (true)
    {
        pwm_set_gpio_level(PWM_MOTOR, 2400); // Definir o ciclo de trabalho para 2400 us (180 graus)
        sleep_ms(5000);                        // Aguardar 5 segundos
        pwm_set_gpio_level(PWM_MOTOR, 1470);  // Definir o ciclo de trabalho para 1470 us (90 graus)
        sleep_ms(5000);                        // Aguardar 5 segundos
        pwm_set_gpio_level(PWM_MOTOR, 500);  // Definir o ciclo de trabalho para 500 us (0 graus)
        sleep_ms(5000);                        // Aguardar 5 segundos
    }
}
