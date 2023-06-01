# FOS Tasks

This repository contains code for two tasks related to operating systems: Kernel Heap and Page Fault Handler.

## Kernel Heap

The Kernel Heap task focuses on modifying the kernel to allow frame allocation anywhere in memory. Traditionally, the kernel uses a one-to-one mapping to allocate frames in physical memory. However, this task proposes a new approach where the frame number is saved in the page to enable accessing frames regardless of their physical location.

The purpose of this modification is to enhance the flexibility and efficiency of memory management within the kernel. By allowing frames to be allocated anywhere, the system can make more efficient use of available memory and potentially optimize memory allocation strategies.

## Page Fault Handler

The Page Fault Handler task deals with managing page faults in an operating system. When an application requests pages that are not currently running in memory, a page fault occurs. The task involves developing a page fault handler that is responsible for allocating the required pages in memory.

The goal of the page fault handler is to handle page faults efficiently and transparently to the running applications. It ensures that necessary pages are allocated in memory, enabling the applications to access them without disruption.

The page fault handler improves overall system performance by dynamically loading pages into memory when needed, optimizing memory usage, and minimizing unnecessary disk I/O operations.

## Getting Started

To use the code in this repository, follow these steps:

1. Clone the repository:

   ```shell
   git clone https://github.com/marwankhaled1/FOS-Tasks.git
2. Navigate to the repository directory:

   ```shell
   cd FOS-Tasks
3. Explore the code related to the Kernel Heap and Page Fault Handler tasks.
