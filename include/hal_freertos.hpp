// include/hal_freertos.hpp
#pragma once

#include "interfaces/i_hal_freertos.hpp"

namespace idf_hals {

/**
 * @class HalFreertos
 * @brief Concrete implementation of FreeRTOS HAL interface.
 */
class HalFreertos : public IHalFreertos
{
public:
    // Task
    void task_delay(TickType_t xTicksToWait) override;

    TaskHandle_t get_task_handle() override;

    BaseType_t task_create(
        TaskFunction_t pvTaskCode,
        const char* const pcName,
        const configSTACK_DEPTH_TYPE usStackDepth,
        void* const pvParameters,
        UBaseType_t uxPriority,
        TaskHandle_t* const pxCreatedTask) override;

    void task_delete(TaskHandle_t task_handle) override;

    void task_suspend(TaskHandle_t task_handle) override;

    BaseType_t task_notify(TaskHandle_t task_handle, uint32_t bits, eNotifyAction action) override;

    BaseType_t
    task_notify_wait(uint32_t bits_clear_entry, uint32_t bits_clear_exit, uint32_t* value, TickType_t xTicksToWait) override;

    // Queue
    QueueHandle_t queue_create(UBaseType_t length, UBaseType_t item_size) override;

    void queue_delete(QueueHandle_t queue_handle) override;

    BaseType_t queue_send(QueueHandle_t queue_handle, const void* data, TickType_t xTicksToWait) override;

    BaseType_t queue_receive(QueueHandle_t queue_handle, void* data, TickType_t xTicksToWait) override;

    BaseType_t
    queue_send_from_isr(QueueHandle_t queue_handle, const void* data, BaseType_t* pxHigherPriorityTaskWoken) override;

    BaseType_t
    queue_receive_from_isr(QueueHandle_t queue_handle, void* data, BaseType_t* pxHigherPriorityTaskWoken) override;

    // Timer
    TimerHandle_t timer_create(
        const char* name,
        TickType_t xTimerPeriodInTicks,
        UBaseType_t auto_reload,
        void* id,
        TimerCallbackFunction_t callback) override;

    BaseType_t timer_start(TimerHandle_t timer_handle, TickType_t xTicksToWait) override;

    BaseType_t timer_stop(TimerHandle_t timer_handle, TickType_t xTicksToWait) override;

    BaseType_t timer_delete(TimerHandle_t timer_handle, TickType_t xTicksToWait) override;

    void* timer_get_id(TimerHandle_t timer_handle) override;

    // Mutex and Semaphore
    SemaphoreHandle_t mutex_create() override;

    SemaphoreHandle_t semaphore_create_binary() override;

    BaseType_t semaphore_take(SemaphoreHandle_t semaphore_handle, TickType_t xTicksToWait) override;

    BaseType_t semaphore_give(SemaphoreHandle_t semaphore_handle) override;

    BaseType_t semaphore_give_from_isr(SemaphoreHandle_t semaphore_handle, BaseType_t* pxHigherPriorityTaskWoken) override;

    BaseType_t semaphore_take_from_isr(SemaphoreHandle_t semaphore_handle, BaseType_t* pxHigherPriorityTaskWoken) override;

    void semaphore_delete(SemaphoreHandle_t semaphore_handle) override;
};

} // namespace idf_hals
