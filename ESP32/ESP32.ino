#include <stdio.h>
#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/string.h>


rcl_publisher_t publisher;
std_msgs__msg__String msg;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;


#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

void setup() {
  
  // set_microros_wifi_transports("SSID", "password", "xxx.xxx.xxx.xxx", 8888); // microros over wifi
  set_microros_transports(); // microros over serial
  allocator = rcl_get_default_allocator();
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  RCCHECK(rclc_node_init_default(&node, "micro_ros_esp32_node", "", &support));
  RCCHECK(rclc_publisher_init_best_effort(&publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String), "/ultrasonic"));

  // Initialize the String message
  msg.data.data = (char *)malloc(50 * sizeof(char)); // Allocate memory for the string
  msg.data.size = 0;
  msg.data.capacity = 50;

}

float cal_ultrasonic(int us_pin){

  pinMode(us_pin, OUTPUT); // US SIG pin output

  // Sends 10 µs pulse to SIG-pin
  digitalWrite(us_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(us_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(us_pin, LOW);

  // change SIG pin to input
  pinMode(us_pin, INPUT);

  // Measures duration of the pulse from the sig pin
  float duration_us = pulseIn(us_pin, HIGH);
  float distance_cm = 0.017 * duration_us;

  return distance_cm;
}

void loop() {
  float distance = cal_ultrasonic(2);

  snprintf(msg.data.data, msg.data.capacity, "Message: %f", distance);
  msg.data.size = strlen(msg.data.data);
  RCSOFTCHECK(rcl_publish(&publisher, &msg, NULL));

  delay(50); // Delay 0,5 second

}

