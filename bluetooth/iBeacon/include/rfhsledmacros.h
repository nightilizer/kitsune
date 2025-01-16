#include <FastLED.h>

#define NUM_LEDS 1

#if defined(ARDUINO_M5Stack_ATOM)
#define FANCY_BOARD_ADDRESSABLE_LED
#define DATA_PIN 27
#elif defined(ARDUINO_M5Stack_ATOMS3)
#define FANCY_BOARD_ADDRESSABLE_LED
#define DATA_PIN 35
#elif defined(ARDUINO_M5Stick_C)
#define FANCY_BOARD_ADDRESSABLE_LED
#define DATA_PIN 19
#elif defined(ARDUINO_M5Stack_StampS3)
#define FANCY_BOARD_ADDRESSABLE_LED
#define DATA_PIN 21
#elif defined(ARDUINO_M5Stack_StampS3)
#define CHEAP_BOARD_NON_ADDRESSABLE_LED
#else
#define CHEAP_BOARD_NO_LED
#endif

CRGB leds[NUM_LEDS];

void ledcolor(uint32_t colorcode) {
#ifdef FANCY_BOARD_ADDRESSABLE_LED
  /*
   * What if we had more than 1 led?
   * for(int num=0; num<NUM_LEDS; num++) {
   *  leds[num] = CRGB(colorcode);
   * }
   */

  leds[0] = CRGB(colorcode);
  FastLED.show();
  // We are supposed to wait this long but I don't want to.
  // delay(50)
#endif
}


void rfhsledinit() {
#ifdef FANCY_BOARD_ADDRESSABLE_LED
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  // M5Stack recommends not setting this value greater than 20
  // to avoid melting the screen/cover over the LEDs
  FastLED.setBrightness(20);
#endif
}
