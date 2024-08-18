# Design Goals

## Supporting Resource Sharing

An important goal of a distributed system is to make it easy for users (and applications) to access and share remote resources. Resources can be virtually anything, including peripherals, storage facilities, data, files, services, and networks. One obvious reason is economics; for example, it is cheaper to have a single high-end, reliable storage facility shared than to buy and maintain storage for each user separately.

Connecting users and resources also makes it easier to collaborate and exchange information. However, resource sharing in distributed systems is perhaps best illustrated by the success of file-sharing peer-to-peer networks like BitTorrent. These distributed systems make it extremely simple for users to share files across the Internet. Peer-to-peer networks are often associated with the distribution of media files such as audio and video. In other cases, the technology is used for distributing large amounts of data, as in the case of software updates, backup services, and data synchronization across multiple servers.

## Making Distribution Transparent

An important goal of a distributed system is to hide the fact that its processes and resources are physically distributed across multiple computers, possibly separated by large distances. In other words, it tries to make the distribution of processes and resources transparent, that is, invisible, to end users and applications.

### Types of Distribution Transparency

- **Access Transparency**: Hides differences in data representation and how objects can be accessed.
- **Location Transparency**: Refers to the fact that users cannot tell where an object is physically located in the system.
- **Relocation Transparency**: Refers to the system’s ability to move resources without affecting ongoing communication and operations.
- **Replication Transparency**: Hides the fact that several copies of a resource exist, or that several processes are operating in lockstep mode, so that one can take over when another fails.
- **Concurrency Transparency**: Ensures that independent users do not notice that others are using the same resource.
- **Failure Transparency**: Ensures that a user or application does not notice when some part of the system fails to work properly and that the system automatically recovers from that failure.

## Degree of Distribution Transparency

Although distribution transparency is generally considered preferable for any distributed system, there are situations where attempting to blindly hide all distribution aspects from users is not a good idea. A simple example is requesting your electronic newspaper to appear in your mailbox before 7 AM local time, as usual, while you are currently at the other end of the world living in a different time zone.

## Being Open

Another important goal of distributed systems is openness. An open distributed system is essentially a system that offers components that can easily be used by or integrated into other systems. At the same time, an open distributed system often consists of components that originate from elsewhere.

### Interoperability, Composability, and Extensibility

To be open means that components should adhere to standard rules that describe the syntax and semantics of what those components have to offer (i.e., which service they provide). A general approach is to define services through interfaces using an Interface Definition Language (IDL).

- **Interoperability**: Characterizes the extent to which two implementations of systems or components from different manufacturers can co-exist and work together by merely relying on each other’s services as specified by a common standard.
- **Portability**: Characterizes to what extent an application developed for a distributed system A can be executed, without modification, on a different distributed system B that implements the same interfaces as A.

## Separating Policy from Mechanism

To achieve flexibility in open distributed systems, it is crucial that the system be organized as a collection of relatively small and easily replaceable or adaptable components. This implies that we should provide definitions of not only the highest-level interfaces, those seen by users and applications, but also definitions for interfaces to internal parts of the system and describe how those parts interact.

## Being Scalable

### Scalability Dimensions

The scalability of a system can be measured along at least three different dimensions:

- **Size Scalability**: Refers to a system's ability to easily add more users and resources without noticeable loss of performance.
- **Geographical Scalability**: Refers to the system's ability to function effectively even when users and resources are geographically distant.
- **Administrative Scalability**: Refers to the system's ability to be easily managed even if it spans many independent administrative organizations.

### Scaling Techniques

Scalability problems often manifest as performance issues due to the limited capacity of servers and networks. Improving their capacity, such as by increasing memory, upgrading CPUs, or replacing network modules, is often referred to as scaling up.

When it comes to scaling out, that is, expanding the distributed system by deploying more machines, there are three main techniques:

1. **Hiding Communication Latencies**: Avoid waiting for responses to remote service requests as much as possible, especially in geographically scalable systems.
2. **Partitioning and Distribution**: Involves splitting a component into smaller parts and spreading those parts across the system (e.g., DNS).
3. **Replication**: Replicating components across the distributed system to improve performance; caching is a special form of replication.
