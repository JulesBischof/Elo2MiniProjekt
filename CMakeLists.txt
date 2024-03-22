cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(fullstand_project)

pico_sdk_init()

add_executable(fullstand main.c)

pico_enable_stdio_usb(fullstand 1)
pico_enable_stdio_uart(fullstand 0)

pico_add_extra_outputs(fullstand)

target_link_libraries(fullstand pico_stdlib)

