# external/idf_hals/CMakeLists.txt
idf_component_register(
    SRCS
        "src/hal_gpio.cpp"
        "src/hal_timer.cpp"
        "src/hal_sys_rom.cpp"
    INCLUDE_DIRS
        "include"
        "include/interfaces"
    REQUIRES
        esp_timer
        driver
)
