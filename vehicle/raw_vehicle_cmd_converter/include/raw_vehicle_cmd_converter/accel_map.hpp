// Copyright 2017-2019 Autoware Foundation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RAW_VEHICLE_CMD_CONVERTER__ACCEL_MAP_HPP_
#define RAW_VEHICLE_CMD_CONVERTER__ACCEL_MAP_HPP_

#include "raw_vehicle_cmd_converter/csv_loader.hpp"
#include "raw_vehicle_cmd_converter/interpolate.hpp"

#include <rclcpp/rclcpp.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace raw_vehicle_cmd_converter
{
class AccelMap
{
public:
  bool readAccelMapFromCSV(std::string csv_path);
  bool getThrottle(double acc, double vel, double & throttle);
  bool getAcceleration(double throttle, double vel, double & acc);
  std::vector<double> getVelIdx() { return vel_index_; }
  std::vector<double> getThrottleIdx() { return throttle_index_; }
  std::vector<std::vector<double>> getAccelMap() { return accel_map_; }

private:
  rclcpp::Logger logger_{rclcpp::get_logger("raw_vehicle_cmd_converter").get_child("accel_map")};
  rclcpp::Clock clock_{RCL_ROS_TIME};
  std::string vehicle_name_;
  std::vector<double> vel_index_;
  std::vector<double> throttle_index_;
  std::vector<std::vector<double>> accel_map_;
};
}  // namespace raw_vehicle_cmd_converter

#endif  // RAW_VEHICLE_CMD_CONVERTER__ACCEL_MAP_HPP_
