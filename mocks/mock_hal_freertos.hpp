// mocks/mock_hal_freertos.hpp
#pragma once

#include "gmock/gmock.h"
#include "interfaces/i_hal_freertos.hpp"

namespace idf_hals {

class MockHalFreertos : public IHalFreertos
{
public:
    MOCK_METHOD(void, task_delay, (TickType_t xTicksToWait), (override));
    MOCK_METHOD(TaskHandle_t, get_task_handle, (), (override));
    MOCK_METHOD(BaseType_t, task_create, (TaskFunction_t pvTaskCode, const char* const pcName, const configSTACK_DEPTH_TYPE usStackDepth, void* const pvParameters, UBaseType_t uxPriority, TaskHandle_t* const pxCreatedTask), (override));
    MOCK_METHOD(void, task_delete, (TaskHandle_t task_handle), (override));
    MOCK_METHOD(void, task_suspend, (TaskHandle_t task_handle), (override));
    MOCK_METHOD(BaseType_t, task_notify, (TaskHandle_t task_handle, uint32_t bits, eNotifyAction action), (override));
    MOCK_METHOD(BaseType_t, task_notify_wait, (uint32_t bits_clear_entry, uint32_t bits_clear_exit, uint32_t* value, TickType_t xTicksToWait), (override));

    MOCK_METHOD(QueueHandle_t, queue_create, (UBaseType_t length, UBaseType_t item_size), (override));
    MOCK_METHOD(void, queue_delete, (QueueHandle_t queue_handle), (override));
    MOCK_METHOD(BaseType_t, queue_send, (QueueHandle_t queue_handle, const void* data, TickType_t xTicksToWait), (override));
    MOCK_METHOD(BaseType_t, queue_receive, (QueueHandle_t queue_handle, void* data, TickType_t xTicksToWait), (override));
    MOCK_METHOD(BaseType_t, queue_send_from_isr, (QueueHandle_t queue_handle, const void* data, BaseType_t* pxHigherPriorityTaskWoken), (override));
    MOCK_METHOD(BaseType_t, queue_receive_from_isr, (QueueHandle_t queue_handle, void* data, BaseType_t* pxHigherPriorityTaskWoken), (override));

    MOCK_METHOD(TimerHandle_t, timer_create, (const char* name, TickType_t xTimerPeriodInTicks, UBaseType_t auto_reload, void* id, TimerCallbackFunction_t callback), (override));
    MOCK_METHOD(BaseType_t, timer_start, (TimerHandle_t timer_handle, TickType_t xTicksToWait), (override));
    MOCK_METHOD(BaseType_t, timer_stop, (TimerHandle_t timer_handle, TickType_t xTicksToWait), (override));
    MOCK_METHOD(BaseType_t, timer_delete, (TimerHandle_t timer_handle, TickType_t xTicksToWait), (override));
    MOCK_METHOD(void*, timer_get_id, (TimerHandle_t timer_handle), (override));

    MOCK_METHOD(SemaphoreHandle_t, mutex_create, (), (override));
    MOCK_METHOD(SemaphoreHandle_t, semaphore_create_binary, (), (override));
    MOCK_METHOD(BaseType_t, semaphore_take, (SemaphoreHandle_t semaphore_handle, TickType_t xTicksToWait), (override));
    MOCK_METHOD(BaseType_t, semaphore_give, (SemaphoreHandle_t semaphore_handle), (override));
    MOCK_METHOD(BaseType_t, semaphore_give_from_isr, (SemaphoreHandle_t semaphore_handle, BaseType_t* pxHigherPriorityTaskWoken), (override));
    MOCK_METHOD(BaseType_t, semaphore_take_from_isr, (SemaphoreHandle_t semaphore_handle, BaseType_t* pxHigherPriorityTaskWoken), (override));
    MOCK_METHOD(void, semaphore_delete, (SemaphoreHandle_t semaphore_handle), (override));
};

} // namespace idf_hals
