// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from claw_machine_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__STRUCT_HPP_
#define CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__claw_machine_msgs__msg__Position __attribute__((deprecated))
#else
# define DEPRECATED__claw_machine_msgs__msg__Position __declspec(deprecated)
#endif

namespace claw_machine_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Position_
{
  using Type = Position_<ContainerAllocator>;

  explicit Position_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->speed = 0.0f;
    }
  }

  explicit Position_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->speed = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _speed_type =
    float;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__speed(
    const float & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    claw_machine_msgs::msg::Position_<ContainerAllocator> *;
  using ConstRawPtr =
    const claw_machine_msgs::msg::Position_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<claw_machine_msgs::msg::Position_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<claw_machine_msgs::msg::Position_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      claw_machine_msgs::msg::Position_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<claw_machine_msgs::msg::Position_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      claw_machine_msgs::msg::Position_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<claw_machine_msgs::msg::Position_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<claw_machine_msgs::msg::Position_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<claw_machine_msgs::msg::Position_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__claw_machine_msgs__msg__Position
    std::shared_ptr<claw_machine_msgs::msg::Position_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__claw_machine_msgs__msg__Position
    std::shared_ptr<claw_machine_msgs::msg::Position_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Position_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const Position_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Position_

// alias to use template instance with default allocator
using Position =
  claw_machine_msgs::msg::Position_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace claw_machine_msgs

#endif  // CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__STRUCT_HPP_
