// src/hal_freertos.cpp
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "freertos/timers.h"

#include "hal_freertos.hpp"

namespace idf_hals {

void HalFreertos::task_delay(TickType_t xTicksToWait)
{
    vTaskDelay(xTicksToWait);
}

TaskHandle_t HalFreertos::get_task_handle()
{
    return xTaskGetCurrentTaskHandle();
}

BaseType_t HalFreertos::task_create(
    TaskFunction_t pvTaskCode,
    const char* const pcName,
    const configSTACK_DEPTH_TYPE usStackDepth,
    void* const pvParameters,
    UBaseType_t uxPriority,
    TaskHandle_t* const pxCreatedTask)
{
    return xTaskCreate(pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask);
}

void HalFreertos::task_delete(TaskHandle_t task_handle)
{
    vTaskDelete(task_handle);
}

void HalFreertos::task_suspend(TaskHandle_t task_handle)
{
    vTaskSuspend(task_handle);
}

BaseType_t HalFreertos::task_notify(TaskHandle_t task_handle, uint32_t bits, eNotifyAction action)
{
    return xTaskNotify(task_handle, bits, action);
}

BaseType_t HalFreertos::task_notify_wait(
    uint32_t bits_clear_entry,
    uint32_t bits_clear_exit,
    uint32_t* value,
    TickType_t xTicksToWait)
{
    return xTaskNotifyWait(bits_clear_entry, bits_clear_exit, value, xTicksToWait);
}

QueueHandle_t HalFreertos::queue_create(UBaseType_t length, UBaseType_t item_size)
{
    return xQueueCreate(length, item_size);
}

void HalFreertos::queue_delete(QueueHandle_t queue_handle)
{
    vQueueDelete(queue_handle);
}

BaseType_t HalFreertos::queue_send(QueueHandle_t queue_handle, const void* data, TickType_t xTicksToWait)
{
    return xQueueSend(queue_handle, data, xTicksToWait);
}

BaseType_t HalFreertos::queue_receive(QueueHandle_t queue_handle, void* data, TickType_t xTicksToWait)
{
    return xQueueReceive(queue_handle, data, xTicksToWait);
}

BaseType_t HalFreertos::queue_send_from_isr(
    QueueHandle_t queue_handle,
    const void* data,
    BaseType_t* pxHigherPriorityTaskWoken)
{
    return xQueueSendFromISR(queue_handle, data, pxHigherPriorityTaskWoken);
}

BaseType_t HalFreertos::queue_receive_from_isr(
    QueueHandle_t queue_handle,
    void* data,
    BaseType_t* pxHigherPriorityTaskWoken)
{
    return xQueueReceiveFromISR(queue_handle, data, pxHigherPriorityTaskWoken);
}

TimerHandle_t HalFreertos::timer_create(
    const char* name,
    TickType_t xTimerPeriodInTicks,
    UBaseType_t auto_reload,
    void* id,
    TimerCallbackFunction_t callback)
{
    return xTimerCreate(name, xTimerPeriodInTicks, auto_reload, id, callback);
}

BaseType_t HalFreertos::timer_start(TimerHandle_t timer_handle, TickType_t xTicksToWait)
{
    return xTimerStart(timer_handle, xTicksToWait);
}

BaseType_t HalFreertos::timer_stop(TimerHandle_t timer_handle, TickType_t xTicksToWait)
{
    return xTimerStop(timer_handle, xTicksToWait);
}

BaseType_t HalFreertos::timer_delete(TimerHandle_t timer_handle, TickType_t xTicksToWait)
{
    return xTimerDelete(timer_handle, xTicksToWait);
}

void* HalFreertos::timer_get_id(TimerHandle_t timer_handle)
{
    return pvTimerGetTimerID(timer_handle);
}

SemaphoreHandle_t HalFreertos::mutex_create()
{
    return xSemaphoreCreateMutex();
}

SemaphoreHandle_t HalFreertos::semaphore_create_binary()
{
    return xSemaphoreCreateBinary();
}

BaseType_t HalFreertos::semaphore_take(SemaphoreHandle_t semaphore_handle, TickType_t xTicksToWait)
{
    return xSemaphoreTake(semaphore_handle, xTicksToWait);
}

BaseType_t HalFreertos::semaphore_give(SemaphoreHandle_t semaphore_handle)
{
    return xSemaphoreGive(semaphore_handle);
}

BaseType_t HalFreertos::semaphore_give_from_isr(
    SemaphoreHandle_t semaphore_handle,
    BaseType_t* pxHigherPriorityTaskWoken)
{
    return xSemaphoreGiveFromISR(semaphore_handle, pxHigherPriorityTaskWoken);
}

BaseType_t HalFreertos::semaphore_take_from_isr(
    SemaphoreHandle_t semaphore_handle,
    BaseType_t* pxHigherPriorityTaskWoken)
{
    return xSemaphoreTakeFromISR(semaphore_handle, pxHigherPriorityTaskWoken);
}

void HalFreertos::semaphore_delete(SemaphoreHandle_t semaphore_handle)
{
    vSemaphoreDelete(semaphore_handle);
}

} // namespace idf_hals
