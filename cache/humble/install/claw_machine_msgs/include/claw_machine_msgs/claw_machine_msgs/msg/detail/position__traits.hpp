// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from claw_machine_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__TRAITS_HPP_
#define CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "claw_machine_msgs/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace claw_machine_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Position & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Position & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Position & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace claw_machine_msgs

namespace rosidl_generator_traits
{

[[deprecated("use claw_machine_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const claw_machine_msgs::msg::Position & msg,
  std::ostream & out, size_t indentation = 0)
{
  claw_machine_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use claw_machine_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const claw_machine_msgs::msg::Position & msg)
{
  return claw_machine_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<claw_machine_msgs::msg::Position>()
{
  return "claw_machine_msgs::msg::Position";
}

template<>
inline const char * name<claw_machine_msgs::msg::Position>()
{
  return "claw_machine_msgs/msg/Position";
}

template<>
struct has_fixed_size<claw_machine_msgs::msg::Position>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<claw_machine_msgs::msg::Position>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<claw_machine_msgs::msg::Position>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CLAW_MACHINE_MSGS__MSG__DETAIL__POSITION__TRAITS_HPP_
