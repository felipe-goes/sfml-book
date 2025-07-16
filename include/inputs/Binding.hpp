#pragma once

#include <string>
#include <unordered_map>

#include "EventDetails.hpp"  // NOLINT
#include "EventTypes.hpp"    // NOLINT

struct Binding {
  explicit Binding(const std::string& l_name)
      : m_name(l_name), c(0), m_details(l_name) {
  }
  void BindEvent(EventType l_type, EventInfo l_info = EventInfo()) {
    m_events.emplace_back(l_type, l_info);
  }

  Events m_events;
  std::string m_name;
  int c;  // Count of events that are "happening"

  EventDetails m_details;
};

using Bindings = std::unordered_map<std::string, Binding*>;
