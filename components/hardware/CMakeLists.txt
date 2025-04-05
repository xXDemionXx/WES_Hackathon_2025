idf_component_register(SRCS "hardware.c" "hcsr04.c"
                       INCLUDE_DIRS "."
                       REQUIRES driver esp_timer)