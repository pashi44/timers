idf_component_register(
    SRCS "timers.cpp" "../headers/tim.cpp" "../gpio/gpio.cpp" # Source files for the main component
    INCLUDE_DIRS "../headers/include" "../gpio/include" "." # Path to the header files
)