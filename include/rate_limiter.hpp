#include <chrono>
#include <iostream>
#include <cstdint>
#include <queue>

class RateLimiter {

public:
  RateLimiter(const std::uint64_t& rate) : rate_(rate) {
    std::cout << "[RateLimiter] created with: " << rate_ << std::endl;
  }

  bool allow() {
    auto now = std::chrono::steady_clock::now();
    auto now_ms =
        std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    if (timeQueue_.empty()) {
      timeQueue_.push(now);

      std::cout << "True: " << now_ms << std::endl;
      return true;
    } else {
      auto elapsed = now - timeQueue_.front();
      if (elapsed >= std::chrono::milliseconds(rate_)) {
        timeQueue_.pop();
        timeQueue_.push(now);
        std::cout << "True: " << now_ms << std::endl;
        return true;
      } else {
        std::cout << "False: " << now_ms << std::endl;
        return false;
      }
    }
  }

private:
  std::uint64_t rate_;
  std::queue<std::chrono::steady_clock::time_point> timeQueue_;
};