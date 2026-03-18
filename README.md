# Fejix

Fejix is a cross-platform library for UI display:
- provides windows and input, much like
  [winit](https://github.com/rust-windowing/winit)
  or [SDL](https://github.com/libsdl-org/SDL), and also other UI stuff
  like popups, status icons, notifications, etc.
- does not provide a runtime (i.e. program entrypoint, event loop, timers,
  threads, background jobs, etc.) or any form of graphics rendering
  -- build your own!
- supports advanced features like layer composition offloading, energy-efficient
  updates, client-side decorations, distinguishing multiple input devices, etc.
- C API
- divided into interfaces/extensions inspired by [Wayland](https://wayland.app)
  that allow you to probe what the user's system supports at runtime
- lets you choose the backend
- distinguishes between client-owned (synchronous) and server-owned
  (event-driven) objects, which allows it to support asynchronous creation,
  destruction and system/user dismissal for windows and clipboard data.
- inherently single-threaded (because GUI multi-threading is inconsistent across
  platforms) and gracefully handles memory allocation errors only where it makes
  sense (for shared memory, framebuffers, icons, and other big binary objects).

> This project is in its earliest stage of development.
>
> The most intereseting thing to see here is this emoji: 🌸
