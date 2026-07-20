# ESP-IDF Hardware Abstraction Layer (HAL) Component

A robust, test-driven Hardware Abstraction Layer (HAL) for Espressif's ESP-IDF. This component decouples hardware-dependent APIs (such as GPIO, timers, sleep modes, and ADCs) from application logic, allowing for unified resource sharing and full host-based unit testing (using Google Test/Google Mock) without physical hardware.

---

## Features

This component provides clean C++ interfaces and concrete wrappers for:
- **GPIO**: Pin configuration, reading, and writing (`IGpioHAL`).
- **Timers**: Microsecond-accurate time counters (`ITimerHAL`).
- **ROM/Delays**: Busy-waiting microsecond delays (`ISysRomHAL`).
- **FreeRTOS**: Task delays and scheduling abstractions (`IHalFreertos`).
- **NVS (Non-Volatile Storage)**: Key-value persistence operations (`IHalNvs`).
- **Sleep Modes**: Deep sleep controls and unified cross-platform GPIO wakeup (`ISleepHAL`).
- **ADC Calibration & Oneshot**: Hardware-agnostic raw ADC readers and calibration schemes (`IHalAdcOneshot`, `IHalAdcCalibration`).

All abstractions come with corresponding **mock classes** in the `mocks/` directory for immediate integration in host-side tests.

---

## Adding to a Project as a Submodule

To add `idf_hals` to your ESP-IDF project as a git submodule, run the following command from the root of your project:

```bash
git submodule add https://github.com/aluiziotomazelli/idf_hals.git components/idf_hals
```

This will clone the HAL component directly into your project's `components/` directory.

---

## CMake Configuration

To integrate the HAL component into your ESP-IDF build system, update the following `CMakeLists.txt` files:

### 1. Root `CMakeLists.txt`
In your project's root `CMakeLists.txt`, ensure that the `components` directory (or the path where you placed the submodule) is included in the extra components directory scan. 

Usually, ESP-IDF automatically scans the `components` folder in the project root. If you have custom structures, you can append it explicitly:

```cmake
cmake_minimum_required(VERSION 3.16)

# Append component path if not automatically found
list(APPEND EXTRA_COMPONENT_DIRS "${CMAKE_CURRENT_LIST_DIR}/components")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(your_project_name)
```

### 2. Main or Component `CMakeLists.txt`
To use `idf_hals` inside your `main` application code or any custom component, you must declare it as a dependency in that component's `CMakeLists.txt`.

Add `idf_hals` to the `REQUIRES` list within the `idf_component_register` command:

```cmake
# main/CMakeLists.txt or components/your_component/CMakeLists.txt

idf_component_register(
    SRCS 
        "main.cpp"
        "your_source_file.cpp"
    INCLUDE_DIRS 
        "include"
    REQUIRES 
        idf_hals    # <-- Declare dependency on the HAL component
)
```

This guarantees that headers from `idf_hals` are included in the compilation paths, and the HAL static library is correctly linked to your target binary.
