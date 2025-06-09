You are building a component for a real-time event processing system (think: market data feed, sensor stream, network packets, etc).
The system must ensure that no more than X events per second are allowed to pass through to downstream consumers.

You are asked to build a RateLimiter module with the following behavior:

    You create it with a configurable rate limit X (events per second).

    You feed events in one by one (the system calls allow() for each event attempt).

    The RateLimiter decides whether to allow the event through based on its timing.

    If allowed, allow() returns true. If the rate limit would be exceeded, it returns false.

You can assume system time is available via your choice of clock.

Example:

Limit = 2 events/sec

t=0ms → allow() → true  
t=100ms → allow() → true  
t=200ms → allow() → false  
t=600ms → allow() → true  
t=800ms → allow() → true  
t=900ms → allow() → false  

Clarifications:

    You must design this as a reusable RateLimiter class.

    Your module must maintain internal state to enforce the rate limit.

    The external system calls allow() — your module decides.

    You can choose any modern C++ timing mechanism you like.
