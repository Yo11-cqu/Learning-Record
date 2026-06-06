Learning-Record
仓库简介
本仓库用于记录本人在 RM 千里战队视觉组预备学习阶段的所有编程作业与 Git 版本控制学习成果

仓库目录结构
Learning-Record/
├── Part1/ # 第 1-3 次 C++ 基础作业（已预先编译）
│ ├── 01_C++ 基础语法.cpp
│ ├── 01_C++ 基础语法 # 可执行文件
│ ├── 02_条件、循环、函数.cpp
│ ├── 02_条件、循环、函数 # 可执行文件
│ ├── 03_面向对象编程思想.cpp
│ └── 03_面向对象编程思想 # 可执行文件
├── student_management/ # 第 4 次作业：学生信息管理系统
│ ├── include/ # 头文件目录
│ ├── src/ # 源文件目录
│ ├── build/ # 已编译好的构建目录
│ │ └── bin/ # 可执行文件目录
│ ├── CMakeLists.txt # CMake 构建配置文件
│ └── README.md # 子项目详细说明
└── README.md # 本说明文档

运行方式
进入Part1目录，直接运行对应可执行文件：

cd Part1

./"01_C++基础语法"

./"02_条件、循环、函数"

./"03_面向对象编程思想"

学生信息管理系统
进入build目录,使用终端运行:
cd student_management
cd build
./bin/student_doc_management

作者:纪博宇
更新时间:2026年6月6日
