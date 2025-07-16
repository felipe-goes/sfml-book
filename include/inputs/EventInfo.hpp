#pragma once

struct EventInfo {
  EventInfo() {
    m_code = 0;
  }
  explicit EventInfo(int l_event) {
    m_code = l_event;
  }
  union {
    int m_code;
  };
};
