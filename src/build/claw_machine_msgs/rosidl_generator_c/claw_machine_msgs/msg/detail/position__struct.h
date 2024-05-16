// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from claw_machine_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__STRUCT_H_
#define CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/Position in the package claw_machine_msgs.
typedef struct claw_machine_msgs__msg__Position
{
  std_msgs__msg__Header header;
  float x;
  float y;
  float z;
  float speed;
} claw_machine_msgs__msg__Position;

// Struct for a sequence of claw_machine_msgs__msg__Position.
typedef struct claw_machine_msgs__msg__Position__Sequence
{
  claw_machine_msgs__msg__Position * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} claw_machine_msgs__msg__Position__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__STRUCT_H_
