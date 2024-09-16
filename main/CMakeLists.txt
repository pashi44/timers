idf_component_register(
    SRCS "timers.cpp" "../headers/tim.cpp" "../queues/queues.cpp" "../gpio/gpio.cpp" # Source files for the main component
    INCLUDE_DIRS "../headers/include" "../queues/include" "../gpio/include" "." # Path to the header files
)
