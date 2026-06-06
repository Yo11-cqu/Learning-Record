# Learning-Record

## 仓库简介

本仓库用于记录本人在 RM 千里战队视觉组预备学习阶段的所有编程作业与 Git 版本控制学习成果。

---

## 仓库目录结构

```text
Learning-Record/
├── Part1/                          # 第 1-3 次 C++ 基础作业（已预先编译）
│   ├── 01_C++基础语法.cpp
│   ├── 01_C++基础语法
│   ├── 02_条件、循环、函数.cpp
│   ├── 02_条件、循环、函数
│   ├── 03_面向对象编程思想.cpp
│   └── 03_面向对象编程思想
│
├── student_management/             # 第 4 次作业：学生信息管理系统
│   ├── include/                    # 头文件目录
│   ├── src/                        # 源文件目录
│   ├── CMakeLists.txt              # CMake 构建配置文件
│   └── README.md                   # 子项目说明文档
│
└── README.md                       # 仓库说明文档
```

---

## 运行方式

### Part1：C++ 基础作业

进入 `Part1` 目录后，可直接运行对应可执行文件：

```bash
cd Part1

./"01_C++基础语法"

./"02_条件、循环、函数"

./"03_面向对象编程思想"
```

---

### 学生信息管理系统

编译并运行程序：

```bash
cd student_management
mkdir build
cd build
cmake ..
make
./bin/student_doc_system
```

---

## 项目说明

### Part1

包含以下基础 C++ 练习内容：

* C++ 基础语法
* 条件语句、循环与函数
* 面向对象编程思想

### student_management

基于 C++ 与 CMake 构建的学生信息管理系统，实现了学生信息的增删改查等基本功能，并采用模块化项目结构进行组织。

---

## 作者信息

* 作者：纪博宇
* 更新时间：2026 年 6 月 6 日

