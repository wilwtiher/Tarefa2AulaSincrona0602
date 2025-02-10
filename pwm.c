#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_MOTOR 22 // pino do motor conectado a GPIO como PWM. para o LED, mudar o pino para 12.

int main()
{
    stdio_init_all();

    gpio_set_function(PWM_MOTOR, GPIO_FUNC_PWM);   // Habilitar o pino GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(PWM_MOTOR); // Obter o canal (slice) PWM da GPIO
    pwm_set_clkdiv(slice, 2.0);                    // Definir o divisor de clock do PWM
    pwm_set_wrap(slice, 1249999);                  // Definir o valor de wrap para 50 Hz
    pwm_set_gpio_level(PWM_MOTOR, 93750);          // Definir o ciclo de trabalho para 1,5 ms (90 graus)
    pwm_set_enabled(slice, true);                  // Habilitar o PWM no slice correspondente

    while (true)
    {
        pwm_set_gpio_level(PWM_MOTOR, 150000); // Definir o ciclo de trabalho para 2400 µs (180 graus)
        sleep_ms(5000);                   // Aguardar 5 segundos
        pwm_set_gpio_level(PWM_MOTOR, 91875);   // Definir o ciclo de trabalho para 1470 µs (90 graus)
        sleep_ms(5000);                    // Aguardar 5 segundos
        pwm_set_gpio_level(PWM_MOTOR, 31250);   // Definir o ciclo de trabalho para 500 µs (0 graus)
        sleep_ms(5000);                    // Aguardar 5 segundos
    }
}
