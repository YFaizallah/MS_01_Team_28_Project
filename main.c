#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include <stdio.h>

int main() {
    // Define the GPIO pins for the LEDs based on your setup
    const uint RED_LED_PIN = 25;   // GPIO 25 for Red LED
    const uint GREEN_LED_PIN = 15; // GPIO 15 for Green LED
    const uint BLUE_LED_PIN = 16;  // GPIO 16 for Blue LED (negative logic)

    // Initialize the LED pins
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);

    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

    // Infinite loop to blink the LEDs in sequence
    while (true) {
        // Step 1: All LEDs off for 5 seconds
        gpio_put(RED_LED_PIN, false);   // Turn off Red LED
        gpio_put(GREEN_LED_PIN, false); // Turn off Green LED
        gpio_put(BLUE_LED_PIN, true);   // Turn off Blue LED (negative logic)
        sleep_ms(5000);  // 5-second delay

        // Step 2: Turn on each LED in sequence for 1 second each
        gpio_put(RED_LED_PIN, true);    // Turn on Red LED
        sleep_ms(1000);                 // Wait 1 second
        gpio_put(RED_LED_PIN, false);   // Turn off Red LED

        gpio_put(GREEN_LED_PIN, true);  // Turn on Green LED
        sleep_ms(1000);                 // Wait 1 second
        gpio_put(GREEN_LED_PIN, false); // Turn off Green LED

        gpio_put(BLUE_LED_PIN, false);  // Turn on Blue LED (negative logic)
        sleep_ms(1000);                 // Wait 1 second
        gpio_put(BLUE_LED_PIN, true);   // Turn off Blue LED (negative logic)

        //This line is just added so that we see that the blue lamp is off
        sleep_ms(100);

        // Step 3: Turn on all LEDs together for 2 seconds
        gpio_put(RED_LED_PIN, true);    // Turn on Red LED
        gpio_put(GREEN_LED_PIN, true);  // Turn on Green LED
        gpio_put(BLUE_LED_PIN, false);  // Turn on Blue LED (negative logic)
        sleep_ms(2000);                 // Wait 2 seconds

        // Step 4: Turn off all LEDs
        gpio_put(RED_LED_PIN, false);   // Turn off Red LED
        gpio_put(GREEN_LED_PIN, false); // Turn off Green LED
        gpio_put(BLUE_LED_PIN, true);   // Turn off Blue LED (negative logic)


    
    }
}
