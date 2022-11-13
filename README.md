# AlwayOnNumLock

To keep the NumLock key always on（Accidental Touch protection）

------

*This document is translated by Google, some representations may be inaccurate.*

README in [简体中文](./docs/README_zh_CN.md)

------

### Introduction

When typing on the keyboard, we sometimes hit the NumLock key accidentially (especially for laptop users), which causes a lot of trouble.

This tool can help you temporarily disable the NumLock key.

### Usage

#### The simplest way

Download the built binary from the Release page and run it.

#### Some hints

- While the program is running, the `NumLock` key will be disabled and will always remain in its current state. After exiting the program, the disabled state of the keys will be automatically released.
- By default, the window will be automatically minimized after the program runs, so it is normal to see a flicker.

- If the program doesn't work, give it administrator rights and run it.

- You can add it to auto-start by following steps：
  1. Create a shortcut for `AlwayOnNumLock.exe`.
  2. Press the `Win+R` key combination, type `shell:startup` and press `Enter`.
  3. Move the created shortcut into the folder that popped up in step 2.

### Development Guide

#### How it works

We register a low-level keyboard hook, `WH_KEYBOARD_LL`, to listen for keypress events.

If the target key code is detected, the function `return 1` to truncate the message and achieve key shielding; otherwise, it `return CallNextHookEx` and  continue to deliver the message.

#### Development environment configuration

Taking the Clion development environment as an example, the following configurations are required:

- Modify the CMake build configuration file, set the toolchain to "Visual Studio 20xx", and set the generator to "Visual Studio 1x 20xx".
- If you want to compile a "x86" target, you can fill in `-A "Win32"` in "CMake Options".

#### something worth noting

Be careful when modifying the following code.

If you comment out a `case`, or add a `break;` under a `case`, the behavior of the program changes greatly.

```c
switch (wParam)
{
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
	// case WM_KEYUP:
	//case WM_SYSKEYUP:
        
        // do something
        
	default:
		break;
}
```
