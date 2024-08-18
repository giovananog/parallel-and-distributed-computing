Design goals

Just because it is possible to build distributed systems does not necessarily
mean that it is a good idea. A
distributed system should make resources easily accessible; it should hide the
fact that resources are distributed across a network; it should be open; and it
should be scalable



Supporting resource sharing

An important goal of a distributed system is to make it easy for users (and
applications) to access and share remote resources. Resources can be virtually
anything, but typical examples include peripherals, storage facilities, data,
files, services, and networks, to name just a few.One obvious reason is that of economics. For
example, it is cheaper to have a single high-end reliable storage facility be
shared than having to buy and maintain storage for each user separately.

Connecting users and resources also makes it easier to collaborate and
exchange information. However, resource sharing in distributed systems is perhaps best illustrated
by the success of file-sharing peer-to-peer networks like BitTorrent. These
distributed systems make it extremely simple for users to share files across
the Internet. Peer-to-peer networks are often associated with distribution of
media files such as audio and video. In other cases, the technology is used for
distributing large amounts of data, as in the case of software updates, backup
services, and data synchronization across multiple servers.




Making distribution transparent

An important goal of a distributed system is to hide the fact that its processes
and resources are physically distributed across multiple computers possibly
separated by large distances. In other words, it tries to make the distribution
of processes and resources transparent, that is, invisible, to end users and
applications.



Types of distribution transparency


Access transparency deals with hiding differences in data representation
and the way that objects can be accessed

Location transparency refers to the fact that users cannot
tell where an object is physically located in the system

Where relocation transparency refers to being moved by the distributed
system, migration transparency is offered by a distributed system when it
supports the mobility of processes and resources initiated by users, without affecting ongoing communication and operations.

Replication transparency deals with hiding the fact that several copies of a
resource exist, or that several processes are operating in some form of lockstep
mode so that one can take over when another fails.

wo independent users may each have stored their files on the same file server
or may be accessing the same tables in a shared database. In such cases, it
is important that each user does not notice that the other is making use of
the same resource. This phenomenon is called concurrency transparency.

failure transparency means that a user or application does not
notice that some piece of the system fails to work properly, and that the system
subsequently (and automatically) recovers from that failure.


Degree of distribution transparency

Although distribution transparency is generally considered preferable for any
distributed system, there are situations in which attempting to blindly hide
all distribution aspects from users is not a good idea. A simple example is
requesting your electronic newspaper to appear in your mailbox before 7 AM
local time, as usual, while you are currently at the other end of the world
living in a different time zone. Your morning paper will not be the morning
paper you are used to.




Being open

Another important goal of distributed systems is openness. An open distributed system is essentially a system that offers components that can easily
be used by, or integrated into other systems. At the same time, an open
distributed system itself will often consist of components that originate from
elsewhere.



Interoperability, composability, and extensibility


To be open means that components should adhere to standard rules that
describe the syntax and semantics of what those components have to offer (i.e.,
which service they provide). A general approach is to define services through
interfaces using an Interface Definition Language (IDL).

re given in an informal way by means of natural language.
If properly specified, an interface definition allows an arbitrary process
that needs a certain interface, to talk to another process that provides that
interface. It also allows two independent parties to build completely different
implementations of those interfaces, leading to two separate components that
operate in exactly the same way.

Interoperability characterizes
the extent by which two implementations of systems or components from
different manufacturers can co-exist and work together by merely relying
on each other’s services as specified by a common standard. Portability
characterizes to what extent an application developed for a distributed system
A can be executed, without modification, on a different distributed system B
that implements the same interfaces as A.




Separating policy from mechanism

To achieve flexibility in open distributed systems, it is crucial that the system
be organized as a collection of relatively small and easily replaceable or
adaptable components. This implies that we should provide definitions of not
only the highest-level interfaces, that is, those seen by users and applications,
but also definitions for interfaces to internal parts of the system and describe
how those parts interact.



Being scalable

Scalability dimensions

Scalability of a system can be measured along at least three different dimensions:

Size scalability: A system can be scalable with respect to its size, meaning
that we can easily add more users and resources to the system without
any noticeable loss of performance.

Geographical scalability: A geographically scalable system is one in which
the users and resources may lie far apart, but the fact that communication
delays may be significant is hardly noticed.

Administrative scalability: An administratively scalable system is one that
can still be easily managed even if it spans many independent administrative organizations

Scaling techniques

Having discussed some of the scalability problems brings us to the question
of how those problems can generally be solved. In most cases, scalability
problems in distributed systems appear as performance problems caused by
limited capacity of servers and network. Simply improving their capacity (e.g.,
by increasing memory, upgrading CPUs, or replacing network modules) is
often a solution, referred to as scaling up. When it comes to scaling out, that
is, expanding the distributed system by essentially deploying more machines,
there are basically only three techniques we can apply: hiding communication
latencies, distribution of work, and replication

Hiding communication latencies. Hiding communication latencies is applicable in the case of geographical scalability. The basic idea is simple: try to
avoid waiting for responses to remote-service requests as much as possible.

Partitioning and distribution. Another important scaling technique is partitioning and distribution, which involves taking a component, splitting it
into smaller parts, and subsequently spreading those parts across the system. (e.g. dns)

Replication. Considering that scalability problems often appear in the form
of performance degradation, it is generally a good idea to actually replicate components across a distributed system. Caching is a special form of replication, although the distinction between
the two is often hard to make or even artificial



