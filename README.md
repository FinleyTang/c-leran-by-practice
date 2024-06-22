## VScode 创建CMake项目

### 前置条件
安装好cmake\C++

### 完整示例
以下是创建CMake项目的步骤示例：

1. **创建项目文件夹**：
直接创建文件夹，或者打开一个已存在的最好是空文件夹。

2. **使用CMake: Quick Start命令**：
   - 打开VS Code的Command Palette (Ctrl+Shift+P)。
   - 输入并选择`CMake: Quick Start`命令。
   - 输入项目名称，选择C++作为项目语言。

3. **选择项目类型**：
   - 选择Executable以创建一个包含基本`main()`函数的源文件（例如`main.cpp`）。

4. **创建CMakePresets.json**：
   - 使用CMake Quick Start命令添加一个新的预设。
   - 从系统上找到的编译器列表中选择一个编译器。
   - 输入预设名称，并将其写入`CMakePresets.json`。

### 小结
本文提供了一个清晰的指南，帮助用户在VS Code中使用CMake Tools扩展创建CMake项目。通过遵循文档中的步骤，即使是初学者也能快速上手CMake，并构建自己的C++项目。文档还强调了配置预设的重要性，这有助于简化构建和测试过程。