# This is a errno replacement

> see man 1 errno

This is for those who don't have errno command in 
bash for some reason, if you experienced

> errno: bash command not found

this repo is the way to go


## How to install it

> $ make

> $ sudo make install

## How to run it

> $ errno

### Examples
> $ errno 3

> Output: 3:ESRCH:No such process

> $ errno ESRCH

> Output: 3:ESRCH:No such process

> $ errno -a

> Output: 

> 0::

> 1:EPERM:Operation not permitted

> 2:ENOENT:No such file or directory 

> 3:ESRCH:No such process 

> 4:EINTR:Interrupted system call 

> 5:EIO:IO error 

> 6:ENXIO:No such device or address 

> 7:E2BIG:Argument list too long 

> 8:ENOEXEC:Exec format error

> ....
