idf_component_register(SRCS "tim.cpp"
    INCLUDE_DIRS "include"
    PRIV_INCLUDE_DIRS "${IDF_PATH}/components/freertos/include"

    REQUIRES freertos)
