idf_component_register(

    SRCS
    "timers.cpp"
    "../headers/tim.cpp"
    "../queues/queues.cpp"
    "../gpio/gpio.cpp"
    "../AlertLed/AlertLed.cpp"

    INCLUDE_DIRS

    "../headers/include"
    "../queues/include"
    "../gpio/include"
    "../AlertLed/include"

    "."
    REQUIRES driver
)
