# Fejix

Fejix is a cross-platform system abstraction layer for GUI.
This library is intended to be used as a base for GUI frameworks, game engines,
emulators, and other kinds of tools that draw their UI themselves, i.e. not
using a native system framework.

Features:
- provides windows and input, much like
  [winit](https://github.com/rust-windowing/winit)
  or [SDL](https://github.com/libsdl-org/SDL), and also other UI stuff
  like popups, status icons, notifications, etc.
- does not provide a runtime (i.e. program entrypoint, event loop, timers,
  threads, background jobs, etc.) or any form of graphics rendering
  &mdash; build your own!
- supports advanced features like layer composition offloading,
  multi-threaded rendering (only rendering! windows and input are inherently
  single-threaded on most systems),
  energy-efficient partial updates, client-side decorations,
  distinguishing multiple input devices and device groups, etc.
- single static/shared library, zero or few dependencies (varies depending on
  the system), simple C99 API that is easy to write bindings for

Implementation features:

- lots of build flags that let you specify only features you need
- lets you choose the backend to use at runtime
- lets you query support for every feature of the host system at runtime

<!--
Design philosophy:

- server-owned objects are always asynchronous (event-driven)
  (including creation, destruction, and all other operations)
- client-owned objects are always synchronous
- simplicity, with many ways to extend
- separation of input from output: input events are
-->

> This project is in its earliest stage of development.
>
> The most intereseting thing to see here is this emoji: 🌸
