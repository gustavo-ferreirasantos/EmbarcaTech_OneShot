#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#define BLUE_LED_PIN 11
#define RED_LED_PIN 12
#define GREEN_LED_PIN 13
#define BUTTON 5

static volatile uint32_t last_time = 0; 
int event = 0;

void init(){
    // Inicializar os pinos
    gpio_init(BLUE_LED_PIN);
    gpio_init(RED_LED_PIN);
    gpio_init(GREEN_LED_PIN);
    gpio_init(BUTTON);

    // Definir direção como saída
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    gpio_set_dir(BUTTON, GPIO_IN);

    // Ativar pull-up no botão
    gpio_pull_up(BUTTON); 
}


// Função de callback que será chamada pelo alarme
int64_t alarm_callback(alarm_id_t id, void *user_data) {
    if(event == 1){
        event++;
        gpio_put(BLUE_LED_PIN, false);
        add_alarm_in_ms(3000, alarm_callback, NULL, false);     
    }else if(event == 2){
        event++;
        gpio_put(RED_LED_PIN, false);
        add_alarm_in_ms(3000, alarm_callback, NULL, false);
    }else{
        event = 0;
        gpio_put(GREEN_LED_PIN, false);
    }
    return 0;
}


// Função de interrupção do botão
void gpio_irq_handler(uint gpio, uint32_t events) {
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    // 300 ms de debouncing
    if (event == 0 && current_time - last_time > 300000){ 
        last_time = current_time;

        // Liga todos os LEDs
        gpio_put(BLUE_LED_PIN, true);
        gpio_put(RED_LED_PIN, true);
        gpio_put(GREEN_LED_PIN, true);
        
        // Inicia temporização para desligamento progressivo
        add_alarm_in_ms(3000, alarm_callback, NULL, false);
        event = 1;
    }
}


int main() {
    stdio_init_all();
    init();
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    while(1){
        tight_loop_contents();
    }
}