What is a distributed system?

A distributed system is a collection of autonomous computing elements
that appears to its users as a single coherent system.

This definition refers to two characteristic features of distributed systems.
The first one is that a distributed system is a collection of computing elements
each being able to behave independently of each other. A computing element,
which we will generally refer to as a node, can be either a hardware device
or a software process. A second feature is that users (be they people or
applications) believe they are dealing with a single system. This means
that one way or another the autonomous nodes need to collaborate. How
to establish this collaboration lies at the heart of developing distributed
systems.


Characteristic 1: Collection of autonomous computing elements

Modern distributed systems can, and often will, consist of all kinds of nodes,
ranging from very big high-performance computers to small plug computers
or even smaller devices. A fundamental principle is that nodes can act independently from each other, although it should be obvious that if they ignore each other, then there is no use in putting them into the same distributed
system.

An important observation is that, as a consequence of dealing with independent nodes, each one will have its own notion of time. In other words, we
cannot always assume that there is something like a global clock. This lack
of a common reference of time leads to fundamental questions regarding the
synchronization and coordination within a distributed system

Concerning the organization of the collection, practice shows that a distributed system is often organized as an overlay network. There are roughly two types of overlay networks:

Structured overlay: In this case, each node has a well-defined set of neighbors
with whom it can communicate. For example, the nodes are organized
in a tree or logical ring.

Unstructured overlay: In these overlays, each node has a number of references to randomly selected other nodes.

In any case, an overlay network should, in principle, always be connected,
meaning that between any two nodes there is always a communication path
allowing those nodes to route messages from one to the other. A well-known
class of overlays is formed by peer-to-peer (P2P) networks



Characteristic 2: Single coherent system

Offering a single coherent view is often challenging enough. For example,
it requires that an end user would not be able to tell exactly on which computer
a process is currently executing, or even perhaps that part of a task has
been spawned off to another process executing somewhere else. Likewise,
where data is stored should be of no concern, and neither should it matter
that the system may be replicating data to enhance performance.

As we cannot ignore the fact that a distributed system consists of
multiple, networked nodes, it is inevitable that at any time only a part of the
system fails. This means that unexpected behavior in which, for example,
some applications may continue to execute successfully while others come
to a grinding halt, is a reality that needs to be dealt with. Although partial
failures are inherent to any complex system, in distributed systems they are
particularly difficult to hide. It lead Turing-Award winner Leslie Lamport, to
describe a distributed system as “[. . .] one in which the failure of a computer
you didn’t even know existed can render your own computer unusable.”



Middleware and distributed systems

To assist the development of distributed applications, distributed systems are
often organized to have a separate layer of software that is logically placed on
top of the respective operating systems of the computers that are part of the
system. This organization is shown in Figure 1.1, leading to what is known as
middleware

![figure 1.1](images\1.png)

Figure 1.1 shows four networked computers and three applications, of
which application B is distributed across computers 2 and 3. Each application
is offered the same interface. The distributed system provides the means for
components of a single distributed application to communicate with each
other, but also to let different applications communicate. At the same time,
it hides, as best and reasonably as possible, the differences in hardware and
operating systems from each application.


In a sense, middleware is the same to a distributed system as what an
operating system is to a computer: a manager of resources offering its applications to efficiently share and deploy those resources across a network.
Next to resource management, it offers services that can also be found in most
operating systems, including:
• Facilities for interapplication communication.
• Security services.
• Accounting services.
• Masking of and recovery from failures.


The main difference with their operating-system equivalents, is that middleware services are offered in a networked environment.  Note also that
most services are useful to many applications. In this sense, middleware can also be viewed as a container of commonly used components and functions
that now no longer have to be implemented by applications separately.
