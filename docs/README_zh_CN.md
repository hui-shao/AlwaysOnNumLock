# AlwayOnNumLock

保持 NumLock 的开启状态（防止误触）

### 前言

在使用键盘进行大量文字输入工作时，经常会不小心按到 NumLock 按键（尤其是在笔记本电脑上），带来了不小的麻烦。

本工具可以帮助你临时禁用 NumLock 按键。

### 使用指南

#### 使用方式

在 Release 页面下载构建好的二进制程序，然后运行即可。

#### 一些提示

- 程序运行后， `NumLock` 按键将被禁用，并始终保持当前的状态。退出程序后，按键的禁用状态将自动解除。
- 程序运行后默认会自动最小化窗口，故“一闪而过”是正常现象。

- 如果程序不起作用，可以尝试使用管理员身份运行。
- 你可以通过以下步骤将其加入开机自启动：
  1. 为 `AlwayOnNumLock.exe` 创建一个快捷方式。
  2. 按下 `Win+R` 组合按键，输入 `shell:startup` 然后按下 `Enter` 键。
  3. 将创建的快捷方式移动到第2步中弹出的文件夹内。

### 开发指南

#### 实现原理

注册一个低级键盘钩子，`WH_KEYBOARD_LL`，监听按键事件。

如果发现目标键码，就 `return 1` 把这个消息截断，实现按键屏蔽；否则 `return CallNextHookEx` ，把消息继续传递。

#### 开发环境配置

以 Clion 开发环境为例，需要进行如下配置：

- 修改 CMake 构建配置文件，设置工具链为 “Visual Studio 20xx”，设置生成器为 ”Visual Studio 1x 20xx”。
- 如果要编译 "x86" 目标，可以在 “CMake 选项” 填写 `-A "Win32"`

#### 注意事项

如下这段代码是程序的关键，修改时一定要谨慎。

注释掉某一个 `case` ，或者是在某个 `case` 下添加了一个 `break;` ，都会让程序的行为有很大变化。

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



