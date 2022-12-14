# Versatile Scalable Micro Kernel(VSMK Kernel)

*VSMK Kernel By AZPEP_BiliBili@Gitee*
![Logo](Logo/StarsOS_All_Logo.png)



当前版本号 Dev.0005

*注：该Kernel**仍处于开发阶段**，是**不可运行**的！*

## 介绍
"VSMK Kernel"是"Stars OS"操作系统的**开源**的操作系统内核,遵守**AGPL3.0[AFFERO GENERAL PUBLIC LICENSE (Version 3, 19 November 2007)]**协议

## 编译
### 开始之前
你应确保您已安装以下工具

- [x] i686-elf-gnu 12.1.0 及以上版本
- [x] grub 2.06 及以上版本 

## 编译
如果你想要使用GRUB 2.06引导，则执行以下指令

```
make build-grub2
```

## 调试操作系统
### 开始之前

您应确保已安装以下工具
```
qemu
bochs (支持单步调试)
```
### 调试
在编译的基础上，如果你执行了"make build-grub2"，则可以执行以下指令：
```
make debug-bochs-grub2
make debug-qemu-grub2
```