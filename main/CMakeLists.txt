idf_component_register(
    SRCS "." "../hardwaretimers/channe.cpp"  # Source files for the main component
    INCLUDE_DIRS "../hardwaretimers/include" "."
    
    
    # Path to the header files

REQUIRES freertos driver task
    )