#include <iostream>
#include <memory>
#include <cstdint>
#include <random>
#include <thread>

#include "rate_limiter.hpp"

void runEvents() {
  // Random number generator setup
  std::random_device rd;                              // seed
  std::mt19937 gen(rd());                             // Mersenne Twister RNG
  std::uniform_int_distribution<> distrib(100, 1000); // random between 100 and 1000 ms

  std::uint64_t rate = 500;
  auto rateLimiter = std::make_unique<RateLimiter>(rate);

  for (int i = 0; i < 15; ++i) {

    auto interval_ms = distrib(gen);

    rateLimiter->allow();

    std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
  }
}

int main() {
  std::cout << "sanity check" << std::endl;

  std::thread events([]() { runEvents(); });

  events.join();

  return 0;
}

