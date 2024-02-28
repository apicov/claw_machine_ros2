// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from claw_machine_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_
#define CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "claw_machine_msgs/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace claw_machine_msgs
{

namespace msg
{

namespace builder
{

class Init_Position_speed
{
public:
  explicit Init_Position_speed(::claw_machine_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  ::claw_machine_msgs::msg::Position speed(::claw_machine_msgs::msg::Position::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::claw_machine_msgs::msg::Position msg_;
};

class Init_Position_z
{
public:
  explicit Init_Position_z(::claw_machine_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_speed z(::claw_machine_msgs::msg::Position::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Position_speed(msg_);
  }

private:
  ::claw_machine_msgs::msg::Position msg_;
};

class Init_Position_y
{
public:
  explicit Init_Position_y(::claw_machine_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_z y(::claw_machine_msgs::msg::Position::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Position_z(msg_);
  }

private:
  ::claw_machine_msgs::msg::Position msg_;
};

class Init_Position_x
{
public:
  explicit Init_Position_x(::claw_machine_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_y x(::claw_machine_msgs::msg::Position::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Position_y(msg_);
  }

private:
  ::claw_machine_msgs::msg::Position msg_;
};

class Init_Position_header
{
public:
  Init_Position_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Position_x header(::claw_machine_msgs::msg::Position::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Position_x(msg_);
  }

private:
  ::claw_machine_msgs::msg::Position msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::claw_machine_msgs::msg::Position>()
{
  return claw_machine_msgs::msg::builder::Init_Position_header();
}

}  // namespace claw_machine_msgs

#endif  // CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_
