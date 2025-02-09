idf_component_register(
    SRCS "pwmc.cpp" 
    INCLUDE_DIRS "." 
    REQUIRES driver     ledpwm  hardwaretimers
)
