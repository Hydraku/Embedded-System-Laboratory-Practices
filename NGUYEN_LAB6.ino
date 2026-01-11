#include <Arduino_FreeRTOS.h>

    void setup() {
      Serial.begin(9600);
    }

    void loop() {
      // Empty – RTOS takes over
    }
/* 
TASK 1
    #include <Arduino_FreeRTOS.h>

    void setup() {
      Serial.begin(9600);
    }

    void loop() {
      // Empty – RTOS takes over
    }

TASK 2
    #include <Arduino_FreeRTOS.h>

    void Task1(void *pvParameters);
    void Task2(void *pvParameters);

    void setup() {
      Serial.begin(9600);

      // Lower priority
      xTaskCreate(Task1, "T1", 128, NULL, 2, NULL);

      // Higher priority
      xTaskCreate(Task2, "T2", 128, NULL, 5, NULL);

      vTaskStartScheduler();
    }

    void loop() {}

    void Task1(void *pvParameters) {
      int i = 0;
      while (1) {
        Serial.print("Task 1: ");
        Serial.println(i++);
        vTaskDelay(500 / portTICK_PERIOD_MS);
      }
    }

    void Task2(void *pvParameters) {
      int i = 0;
      while (1) {
        Serial.print("Task 2: ");
        Serial.println(i++);
        vTaskDelay(500 / portTICK_PERIOD_MS);
      }
    }


TASK 3

    #include <Arduino_FreeRTOS.h>

    void GreenLED(void *pvParameters);
    void YellowLED(void *pvParameters);

    void setup() {
      pinMode(8, OUTPUT);  // Green LED
      pinMode(9, OUTPUT);  // Yellow LED

      xTaskCreate(GreenLED, "Green", 128, NULL, 1, NULL);
      xTaskCreate(YellowLED, "Yellow", 128, NULL, 1, NULL);

      vTaskStartScheduler();
    }

    void loop() {}

    // Task for Green LED
    void GreenLED(void *pvParameters) {
      while (1) {
        digitalWrite(8, HIGH);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        digitalWrite(8, LOW);
        vTaskDelay(500 / portTICK_PERIOD_MS);
      }
    }

    // Task for Yellow LED
    void YellowLED(void *pvParameters) {
      while (1) {
        digitalWrite(9, HIGH);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        digitalWrite(9, LOW);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
      }
    }

TASK 4

    #include <Arduino_FreeRTOS.h>

    void GREEN(void *pvParameters);
    void YELLOW(void *pvParameters);

    void setup() {
      pinMode(8, OUTPUT); //GREEN LED 
      pinMode(9, OUTPUT); //YELLOW LED

      xTaskCreate(GREEN, "GREEN", 128, NULL, 2, NULL); // HIGH priority
      xTaskCreate(YELLOW, "YELLOW", 128, NULL, 1, NULL); // LOW priority

      vTaskStartScheduler();
    }

    void loop() {}

    void GREEN(void *pvParameters) {
      while (1) {
        digitalWrite(8, HIGH);
        vTaskDelay(300 / portTICK_PERIOD_MS);
        digitalWrite(8, LOW);
        vTaskDelay(300 / portTICK_PERIOD_MS);
      }
    }

    void YELLOW(void *pvParameters) {
      while (1) {
        digitalWrite(9, HIGH);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        digitalWrite(9, LOW);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
      }
    }

TASK 5

    #include <Arduino_FreeRTOS.h>

    void BlinkLED(void *pvParameters);

    int ledPins[] = {8, 9};
    int delays[] = {300, 2000};

    void setup() {
      pinMode(8, OUTPUT);
      pinMode(9, OUTPUT);

      xTaskCreate(BlinkLED, "LED1", 128, (void*)0, 1, NULL);
      xTaskCreate(BlinkLED, "LED2", 128, (void*)1, 1, NULL);

      vTaskStartScheduler();
    }

    void loop() {}

    void BlinkLED(void *pvParameters) {
      int id = (int)pvParameters;
      while (1) {
        digitalWrite(ledPins[id], HIGH);
        vTaskDelay(delays[id] / portTICK_PERIOD_MS);
        digitalWrite(ledPins[id], LOW);
        vTaskDelay(delays[id] / portTICK_PERIOD_MS);
      }
    }

TASK 6

    #include <Arduino_FreeRTOS.h>
    #include <semphr.h>

    SemaphoreHandle_t xSemaphore;

    void setup() {
      Serial.begin(9600);

      xSemaphore = xSemaphoreCreateBinary();

      if (xSemaphore != NULL)
        Serial.println("Semaphore Created!");
    }

    void loop() {}

TASK 7

    #include <Arduino_FreeRTOS.h>
    #include <semphr.h>

    SemaphoreHandle_t xSemaphore;
    int sharedCounter = 0;

    void TaskA(void *pvParameters);
    void TaskB(void *pvParameters);

    void setup() {
      Serial.begin(9600);

      xSemaphore = xSemaphoreCreateBinary();
      xSemaphoreGive(xSemaphore);

      xTaskCreate(TaskA, "A", 128, NULL, 1, NULL);
      xTaskCreate(TaskB, "B", 128, NULL, 1, NULL);

      vTaskStartScheduler();
    }

    void loop() {}

    void TaskA(void *pvParameters) {
      while (1) {
        if (xSemaphoreTake(xSemaphore, portMAX_DELAY)) {
          sharedCounter++;
          Serial.print("Task A: ");
          Serial.println(sharedCounter);
          xSemaphoreGive(xSemaphore);
        }
        vTaskDelay(800 / portTICK_PERIOD_MS);
      }
    }

    void TaskB(void *pvParameters) {
      while (1) {
        if (xSemaphoreTake(xSemaphore, portMAX_DELAY)) {
          sharedCounter++;
          Serial.print("Task B: ");
          Serial.println(sharedCounter);
          xSemaphoreGive(xSemaphore);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
      }
    }

TASK 8

    #include <Arduino_FreeRTOS.h>
    #include <semphr.h>

    SemaphoreHandle_t xSemaphore;

    void WaitingTask(void *pvParameters);

    void setup() {
      Serial.begin(9600);

      pinMode(9, OUTPUT);
      pinMode(2, INPUT_PULLUP);

      xSemaphore = xSemaphoreCreateBinary();

      xTaskCreate(WaitingTask, "Wait", 128, NULL, 1, NULL);

      attachInterrupt(digitalPinToInterrupt(2), ButtonISR, FALLING);

      vTaskStartScheduler();
    }

    void loop() {}

    void WaitingTask(void *pvParameters) {
      while (1) {
        Serial.println("Waiting for button...");
        if (xSemaphoreTake(xSemaphore, portMAX_DELAY)) {
          Serial.println("Button Pressed!");
          digitalWrite(9, HIGH);
          vTaskDelay(500 / portTICK_PERIOD_MS);
          digitalWrite(9, LOW);
        }
      }
    }

    void ButtonISR() {
      xSemaphoreGiveFromISR(xSemaphore, NULL);
    }
*/



