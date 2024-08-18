# What is a Distributed System?

A distributed system is a collection of autonomous computing elements that appears to its users as a single coherent system.

This definition highlights two characteristic features of distributed systems:
1. A distributed system is a collection of computing elements, each capable of independent behavior. These elements, generally referred to as nodes, can be either hardware devices or software processes.
2. Users (whether people or applications) perceive the system as a single entity. This necessitates collaboration among the autonomous nodes, which is central to the development of distributed systems.

## Characteristic 1: Collection of Autonomous Computing Elements

Modern distributed systems often consist of a diverse range of nodes, from large high-performance computers to small plug computers or even smaller devices. A fundamental principle is that nodes can act independently of each other, but there is no benefit in including nodes in the same distributed system if they completely ignore each other.

An important consequence of dealing with independent nodes is that each one will have its own notion of time, meaning there may not be a global clock. This lack of a common time reference raises fundamental questions about synchronization and coordination within a distributed system.

### Overlay Networks

Distributed systems are often organized as overlay networks, which can be categorized into two types:
- **Structured Overlay**: Each node has a well-defined set of neighbors with whom it can communicate, such as nodes organized in a tree or logical ring.
- **Unstructured Overlay**: Each node has references to randomly selected other nodes.

In any case, an overlay network should always be connected, ensuring that a communication path exists between any two nodes, allowing them to route messages. A well-known class of overlays is formed by peer-to-peer (P2P) networks.

## Characteristic 2: Single Coherent System

Offering a single coherent view is challenging, as it requires that an end user cannot tell on which computer a process is executing, or that part of a task has been delegated to another process running elsewhere. The location of data storage should not matter, nor should the replication of data to enhance performance.

Given that a distributed system consists of multiple networked nodes, it is inevitable that only part of the system will fail at any given time. This can lead to unexpected behavior where some applications may continue to run successfully while others fail. Partial failures are inherent to any complex system but are particularly difficult to conceal in distributed systems. This led Turing Award winner Leslie Lamport to describe a distributed system as "one in which the failure of a computer you didn’t even know existed can render your own computer unusable."

# Middleware and Distributed Systems

To facilitate the development of distributed applications, distributed systems are often organized with a separate software layer logically placed on top of the operating systems of the computers in the system. This layer is known as middleware.

![Figure 1.1](images/1.png)

Figure 1.1 illustrates four networked computers and three applications, with application B distributed across computers 2 and 3. Each application is provided with the same interface. The distributed system enables components of a single distributed application to communicate with each other and allows different applications to communicate. At the same time, it conceals, as best as possible, the differences in hardware and operating systems from each application.

In essence, middleware is to a distributed system what an operating system is to a computer: a resource manager that allows applications to efficiently share and deploy resources across a network. Besides resource management, it provides services commonly found in operating systems, including:
- Facilities for interapplication communication.
- Security services.
- Accounting services.
- Masking of and recovery from failures.

The primary difference from their operating-system equivalents is that middleware services are provided in a networked environment. Additionally, most services are useful to many applications, making middleware a container of commonly used components and functions, eliminating the need for separate implementation by each application.
