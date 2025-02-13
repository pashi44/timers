idf_component_register(
    SRCS "channe.cpp" 
    INCLUDE_DIRS "." "include" 
    REQUIRES freertos driver    # Declares dependency on ledpwm
)
