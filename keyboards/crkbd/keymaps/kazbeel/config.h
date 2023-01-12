#pragma once


#ifdef TAPPING_TERM
	#undef TAPPING_TERM
#endif // TAPPING_TERM
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#ifdef RGB_MATRIX_ENABLE
#  define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP
// #  define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_ALPHAS_MODS

#  define RGB_MATRIX_FRAMEBUFFER_EFFECTS      // For the heatmap effect
#  define RGB_MATRIX_KEYPRESSES               // Reacts to keypresses

#  undef ENABLE_RGB_MATRIX_SOLID_COLOR             // Static single hue, no speed support
#  define ENABLE_RGB_MATRIX_ALPHAS_MODS              // Static dual hue, speed is hue for secondary hue
#  undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN         // Static gradient top to bottom, speed controls how much gradient changes
#  undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT      // Static gradient left to right, speed controls how much gradient changes
#  undef ENABLE_RGB_MATRIX_BREATHING                // Single hue brightness cycling animation
#  undef ENABLE_RGB_MATRIX_BAND_SAT                 // Single hue band fading saturation scrolling left to right
#  undef ENABLE_RGB_MATRIX_BAND_VAL                 // Single hue band fading brightness scrolling left to right
#  undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT        // Single hue 3 blade spinning pinwheel fades saturation
#  undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL        // Single hue 3 blade spinning pinwheel fades brightness
#  undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT          // Single hue spinning spiral fades saturation
#  undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL          // Single hue spinning spiral fades brightness
#  undef ENABLE_RGB_MATRIX_CYCLE_ALL                // Full keyboard solid hue cycling through full gradient
#  undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT         // Full gradient scrolling left to right
#  undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN            // Full gradient scrolling top to bottom
#  undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON   // Full gradient Chevron shaped scrolling left to right
#  undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN             // Full gradient scrolling out to in
#  undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL        // Full dual gradients scrolling out to in
#  undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL           // Full gradient spinning pinwheel around center of keyboard
#  undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL             // Full gradient spinning spiral around center of keyboard
#  undef ENABLE_RGB_MATRIX_DUAL_BEACON              // Full gradient spinning around center of keyboard
#  undef ENABLE_RGB_MATRIX_RAINBOW_BEACON           // Full tighter gradient spinning around center of keyboard
#  undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS        // Full dual gradients spinning two halfs of keyboard
#  undef ENABLE_RGB_MATRIX_RAINDROPS                // Randomly changes a single key's hue
#  undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS      // Randomly changes a single key's hue and saturation
#  undef ENABLE_RGB_MATRIX_HUE_BREATHING            // Hue shifts up a slight amount at the same time, then shifts back
#  undef ENABLE_RGB_MATRIX_HUE_PENDULUM             // Hue shifts up a slight amount in a wave to the right, then back to the left
#  undef ENABLE_RGB_MATRIX_HUE_WAVE                 // Hue shifts up a slight amount and then back down in a wave to the right
#  undef ENABLE_RGB_MATRIX_PIXEL_RAIN               // Randomly light keys with random hues
#  undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#  undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL            // Single hue fractal filled keys pulsing horizontally out to edges

#  if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP // How hot is your WPM!
#    undef ENABLE_RGB_MATRIX_DIGITAL_RAIN   // That famous computer simulation
#  endif  // RGB_MATRIX_FRAMEBUFFER_EFFECTS

#  if defined(RGB_MATRIX_KEYPRESSES) || defined(RGB_MATRIX_KEYRELEASES)
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE     // Pulses keys hit to hue & value then fades value out
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE            // Static single hue, pulses keys hit to shifted hue then fades to current hue
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#    undef ENABLE_RGB_MATRIX_SPLASH                    // Full gradient & value pulse away from a single key hit then fades value out
#    undef ENABLE_RGB_MATRIX_MULTISPLASH               // Full gradient & value pulse away from multiple key hits then fades value out
#    undef ENABLE_RGB_MATRIX_SOLID_SPLASH              // Hue & value pulse away from a single key hit then fades value out
#    undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH         // Hue & value pulse away from multiple key hits then fades value out
#  endif // RGB_MATRIX_KEYPRESSES || RGB_MATRIX_KEYRELEASES
#endif // RGB_MATRIX_ENABLE

/**
 * OLED configuration.
 */
#define OLED_TIMEOUT 30000
#define OLED_BRIGHTNESS 128
#define OLED_UPDATE_INTERVAL 5

/**
 * Disable unused features to save ROM space
 * See: https://docs.qmk.fm/#/faq_keymap?id=mechanical-lock-switch-support
 */
#ifdef LOCKING_SUPPORT_ENABLE
#  undef LOCKING_SUPPORT_ENABLE
#endif

#ifdef LOCKING_RESYNC_ENABLE
#  undef LOCKING_RESYNC_ENABLE
#endif
