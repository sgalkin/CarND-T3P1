#pragma once

#include <chrono>

inline constexpr float mph_to_ms(float mph) {
  constexpr float c = 0.44704;
  return mph*c;
}

using Timestamp = std::chrono::duration<float>;

namespace limits {
//  constexpr float acceleration = 10; // m/s^2
//  constexpr float jerk = 10; // m/s^3
  constexpr float speed_limit = mph_to_ms(50);  // m/s
  constexpr float max_speed = 0.99f * speed_limit;    // m/s 
  
  constexpr auto tick{
    std::chrono::duration_cast<Timestamp>(std::chrono::milliseconds{20})
  }; // s

  constexpr auto lane_change_time{
    std::chrono::duration_cast<Timestamp>(std::chrono::seconds{3})
  }; // s

  constexpr auto horizon{
    std::chrono::duration_cast<Timestamp>(std::chrono::seconds{1})
  }; // s

  const size_t path_size = std::ceil(horizon/tick);
}
